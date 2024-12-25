#include <common/Exception.h>

#include <storage/BTreePlus/BTreePlusStorage.h>


namespace MixS
{
BTreePlusStorage::BTreePlusStorage(size_t order) : order(order)
{
    root = std::make_shared<BTreePlusLeafNode>();
    leaf_head = std::dynamic_pointer_cast<BTreePlusLeafNode>(root);
}

BTreePlusStorage::~BTreePlusStorage()
{
}

void BTreePlusStorage::init()
{
}

void BTreePlusStorage::shutdown()
{
}

void BTreePlusStorage::set(const String& key, const String& value)
{
    if (!root->isFull())
    {
        insertNonFull(root, key, value);
    }
    else
    {
        BTreePlusInternalNodePtr new_root = std::make_shared<BTreePlusInternalNode>();
        new_root->children.push_back(root);
        splitchild(new_root, 0, root);
        root = new_root;
        insertNonFull(root, key, value);
    }
}

String BTreePlusStorage::get(const String& key)
{
    BTreePlusNodePtr node = root;

    while (!node->isLeaf())
    {
        BTreePlusInternalNodePtr internal = std::dynamic_pointer_cast<BTreePlusInternalNode>(node);
        size_t i = 0;
        while (i < internal->keys.size() && key >= internal->keys[i])
        {
            i++;
        }
        node = internal->children[i];
    }

    BTreePlusLeafNodePtr leaf = std::dynamic_pointer_cast<BTreePlusLeafNode>(node);
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
        return "null";
    }
}

void BTreePlusStorage::remove(const String& key)
{

}

std::vector<String> BTreePlusStorage::rangeGet(const String& start, const String& end)
{
    return std::vector<String>();
}

void BTreePlusStorage::insertNonFull(BTreePlusNodePtr node, const String& key, const String& value)
{
    if (node->isFull())
        throw Exception("Node is full");
    
    if (node->isLeaf())
    {
        BTreePlusLeafNodePtr leaf = std::dynamic_pointer_cast<BTreePlusLeafNode>(node);
        size_t i = leaf->keys.size() - 1;
        leaf->keys.push_back("");
        leaf->values.push_back("");
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
        BTreePlusInternalNodePtr internal = std::dynamic_pointer_cast<BTreePlusInternalNode>(node);
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

void BTreePlusStorage::splitchild(BTreePlusNodePtr parent, size_t index, BTreePlusNodePtr child)
{
    BTreePlusInternalNodePtr internal = std::dynamic_pointer_cast<BTreePlusInternalNode>(parent);
    BTreePlusInternalNodePtr new_internal = std::make_shared<BTreePlusInternalNode>();
    BTreePlusInternalNodePtr old_internal = std::dynamic_pointer_cast<BTreePlusInternalNode>(child);
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

}