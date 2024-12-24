#pragma once

#include <base/types.h>
#include <vector>
#include <memory>

namespace MixS
{
const static size_t BTreePlusOrder = 4;

struct BTreePlusInternalNode;
using BTreePlusInternalNodePtr = std::shared_ptr<BTreePlusInternalNode>;
struct BTreePlusInternalNode
{
    std::vector<String> keys;
    std::vector<BTreePlusInternalNodePtr> children;

    BTreePlusInternalNode() = default;
};

struct BTreePlusLeafNode;
using BTreePlusLeafNodePtr = std::shared_ptr<BTreePlusLeafNode>;
struct BTreePlusLeafNode
{
    std::vector<String> keys;
    std::vector<String> values;

    BTreePlusLeafNodePtr next;

    BTreePlusLeafNode() : next(nullptr) {}
};

} // namespace MixS
