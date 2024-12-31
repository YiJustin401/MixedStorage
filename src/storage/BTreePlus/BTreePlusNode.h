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

template <typename Derived>
class DV
{
public:
    using Ptr = std::shared_ptr<Derived>;
    Derived& derived()
    {
        return *static_cast<Derived*>(this);
    }

    const Derived& derived() const
    {
        return *static_cast<const Derived*>(this);
    }
};

template <typename KEY, typename VALUE>
class BTreePlusInternalNode : public BTreePlusNode, public DV<BTreePlusInternalNode<KEY, VALUE>>
{
public:
    friend class DV<BTreePlusInternalNode<KEY, VALUE>>;
    using Ptr = typename DV<BTreePlusInternalNode<KEY, VALUE>>::Ptr;
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

    std::vector<KEY> keys;
    std::vector<BTreePlusNodePtr> children;
};

template <typename KEY, typename VALUE>
class BTreePlusLeafNode : public BTreePlusNode, public DV<BTreePlusLeafNode<KEY, VALUE>>
{
public:
    friend class DV<BTreePlusLeafNode<KEY, VALUE>>;
    using Ptr = typename DV<BTreePlusLeafNode<KEY, VALUE>>::Ptr;
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

    std::vector<KEY> keys;
    std::vector<VALUE> values;

    Ptr next;
};

template <typename KEY, typename VALUE>
using BTreePlusInternalNodePtr = std::shared_ptr<BTreePlusInternalNode<KEY, VALUE>>;
template <typename KEY, typename VALUE>
using BTreePlusLeafNodePtr = std::shared_ptr<BTreePlusLeafNode<KEY, VALUE>>;

} // namespace MixS
