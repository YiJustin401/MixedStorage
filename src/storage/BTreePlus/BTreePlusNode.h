#pragma once

#include <base/types.h>
#include <vector>
#include <memory>

namespace MixS
{
const static size_t BTreePlusOrder = 4;

class BTreePlusNode;
using BTreePlusNodePtr = std::shared_ptr<BTreePlusNode>;

class BTreePlusNode
{
public:
    virtual ~BTreePlusNode() = default;

    virtual bool isLeaf() const = 0;
    virtual bool isFull() const = 0;
};

class BTreePlusInternalNode : public BTreePlusNode
{
public:
    BTreePlusInternalNode() = default;
    ~BTreePlusInternalNode() override = default;

    bool isLeaf() const override
    {
        return false;
    }

    bool isFull() const override
    {
        return keys.size() == 2 * BTreePlusOrder - 1;
    }

    std::vector<String> keys;
    std::vector<BTreePlusNodePtr> children;
};

class BTreePlusLeafNode : public BTreePlusNode
{
public:
    BTreePlusLeafNode() = default;
    ~BTreePlusLeafNode() override = default;

    bool isLeaf() const override
    {
        return true;
    }

    bool isFull() const override
    {
        return keys.size() == 2 * BTreePlusOrder - 1;
    }

    std::vector<String> keys;
    std::vector<String> values;

    BTreePlusLeafNode* next;
};

using BTreePlusInternalNodePtr = std::shared_ptr<BTreePlusInternalNode>;
using BTreePlusLeafNodePtr = std::shared_ptr<BTreePlusLeafNode>;

} // namespace MixS
