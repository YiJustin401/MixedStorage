#pragma once

#include <vector>

#include <common/Exception.h>

#include <storage/StorageEngine.h>
#include <storage/BTreePlus/BTreePlusNode.h>

namespace MixS
{

/// @brief A storage engine that uses a B-Tree to store key-value pairs.
template <typename KEY, typename VALUE>
class BTreePlusStorage : public StorageEngine<KEY, VALUE>
{
public:
    using BTreePlusINodePtr = std::shared_ptr<BTreePlusInternalNode<KEY, VALUE>>;
    using BTreePlusLNodePtr = std::shared_ptr<BTreePlusLeafNode<KEY, VALUE>>;

    typedef BTreePlusInternalNode<KEY, VALUE> BTreePlusINode;
    typedef BTreePlusLeafNode<KEY, VALUE> BTreePlusLNode;

    BTreePlusStorage(size_t order = MixS::BTreePlusOrder)
    {
        this->order = order;
        root = std::make_shared<BTreePlusLNode>();
        leaf_head = std::dynamic_pointer_cast<BTreePlusLNode>(root);
    }
    ~BTreePlusStorage() override = default;

    void init() override
    {}
    void shutdown() override
    {}

    void set(const KEY& key, const VALUE& value) override
    {
         if (!root->isFull())
        {
            insertNonFull(root, key, value);
        }
        else
        {
            BTreePlusINodePtr new_root = std::make_shared<BTreePlusINode>();
            new_root->children.push_back(root);
            splitchild(new_root, 0, root);
            root = new_root;
            insertNonFull(root, key, value);
        }
    }
    VALUE get(const KEY& key) override
    {
        BTreePlusNodePtr node = root;

        while (!node->isLeaf())
        {
            BTreePlusINodePtr internal = std::dynamic_pointer_cast<BTreePlusINode>(node);
            size_t i = 0;
            while (i < internal->keys.size() && key >= internal->keys[i])
            {
                i++;
            }
            node = internal->children[i];
        }

        BTreePlusLNodePtr leaf = std::dynamic_pointer_cast<BTreePlusLNode>(node);
        size_t i = 0;
        while (i < leaf->keys.size() && key > leaf->keys[i])
        {
            i++;
        }
        if (i < leaf->keys.size() && key == leaf->keys[i])
        {
            return leaf->values[i];
        }
        else
        {
            return VALUE::getNull();
        }
    }
    void remove(const KEY& key) override
    {}

    std::vector<VALUE> rangeGet(const KEY& start, const KEY& end)
    {
        return std::vector<VALUE>();
    }
private:
    /// @brief Insert a key-value pair into a non-full node.
    /// @param node The node to insert the key-value pair.
    /// @param key The key to insert.
    /// @param value The value to insert
    void insertNonFull(BTreePlusNodePtr node, const KEY& key, const VALUE& value)
    {
        if (node->isFull())
            throw Exception("Node is full");
        
        if (node->isLeaf())
        {
            BTreePlusLNodePtr leaf = std::dynamic_pointer_cast<BTreePlusLNode>(node);
            size_t i = leaf->keys.size() - 1;
            leaf->keys.push_back(KEY());
            leaf->values.push_back(VALUE::getNull());
            while (i >= 0 && key < leaf->keys[i])
            {
                leaf->keys[i + 1] = leaf->keys[i];
                leaf->values[i + 1] = leaf->values[i];
                i--;
            }
            leaf->keys[i + 1] = key;
            leaf->values[i + 1] = value;
        }
        else
        {
            BTreePlusINodePtr internal = std::dynamic_pointer_cast<BTreePlusINode>(node);
            size_t i = internal->keys.size() - 1;
            while (i >= 0 && key < internal->keys[i])
            {
                i--;
            }
            i++;
            if (internal->children[i]->isFull())
            {
                splitchild(internal, i, internal->children[i]);
                if (key > internal->keys[i])
                {
                    i++;
                }
            }
            insertNonFull(internal->children[i], key, value);
        }
    }
    void splitchild(BTreePlusNodePtr parent, size_t index, BTreePlusNodePtr child)
    {
        BTreePlusINodePtr internal = std::dynamic_pointer_cast<BTreePlusINode>(parent);
        BTreePlusINodePtr new_internal = std::make_shared<BTreePlusINode>();
        BTreePlusINodePtr old_internal = std::dynamic_pointer_cast<BTreePlusINode>(child);
        new_internal->keys.resize(order - 1);
        new_internal->children.resize(order);
        for (size_t i = 0; i < order - 1; i++)
        {
            new_internal->keys[i] = old_internal->keys[i + order];
        }
        for (size_t i = 0; i < order; i++)
        {
            new_internal->children[i] = old_internal->children[i + order];
        }
        for (size_t i = internal->keys.size(); i > index; i--)
        {
            internal->keys[i] = internal->keys[i - 1];
        }
        internal->keys[index] = old_internal->keys[order - 1];
        internal->children.insert(internal->children.begin() + index + 1, new_internal);
        old_internal->keys.resize(order - 1);
        old_internal->children.resize(order);
    }

private:
    // TODO: add your data members here
    BTreePlusNodePtr root;
    BTreePlusLNodePtr leaf_head;
    size_t order;
};

} // namespace MixS
