#include <storage/BTreePlus/BTreePlusStorage.h>

namespace MixS
{
BTreePlusStorage::BTreePlusStorage(size_t order) : order(order)
{
    root = std::make_shared<BTreePlusInternalNode>();
    leaf_head = nullptr;
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
    BTreePlusInternalNodePtr node = root;
    if (node->keys.size() == 2 * order - 1)
    {
        BTreePlusInternalNodePtr new_root = std::make_shared<BTreePlusInternalNode>();
        new_root->children.push_back(root);
        root = new_root;
        splitchild(new_root, 0, node);
        insertNonFull(new_root, key);
    }
    else
    {
        insertNonFull(node, key);
    }
}

String BTreePlusStorage::get(const String& key)
{
    return "";
}

void BTreePlusStorage::remove(const String& key)
{

}

std::vector<String> BTreePlusStorage::rangeGet(const String& start, const String& end)
{
    return std::vector<String>();
}

void BTreePlusStorage::insertNonFull(BTreePlusInternalNodePtr node, const String& key)
{
    size_t i = node->keys.size() - 1;
    if (node->children.empty())
    {
        node->keys.push_back(key);
        return;
    }
    while (i >= 0 && key < node->keys[i])
    {
        i--;
    }
    i++;
    if (node->children[i]->keys.size() == 2 * order - 1)
    {
        splitchild(node, i, node->children[i]);
        if (key > node->keys[i])
        {
            i++;
        }
    }
    insertNonFull(node->children[i], key);
}

void BTreePlusStorage::splitchild(BTreePlusInternalNodePtr parent, size_t index, BTreePlusInternalNodePtr child)
{
    BTreePlusInternalNodePtr new_child = std::make_shared<BTreePlusInternalNode>();
    parent->keys.insert(parent->keys.begin() + index, child->keys[order - 1]);
    parent->children.insert(parent->children.begin() + index + 1, new_child);

    // move the last (order - 1) keys of child to new_child
    for (size_t i = 0; i < order - 1; i++)
    {
        new_child->keys.push_back(child->keys[order + i]);
    }
}

}