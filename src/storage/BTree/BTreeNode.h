#pragma once

#include <base/types.h>
#include <vector>


namespace MixS
{
struct BTreeNode
{
    bool is_leaf;
    std::vector<String> keys;
    std::vector<BTreeNode*> children;
    std::vector<String> values;

    BTreeNode* next;

    BTreeNode(bool is_leaf) : is_leaf(is_leaf), next(nullptr) {}
};

} // namespace MixS
