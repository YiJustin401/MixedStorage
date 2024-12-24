#pragma once

#include <vector>

#include <storage/StorageEngine.h>
#include <storage/BTreePlus/BTreePlusNode.h>

namespace MixS
{
class BTreePlusStorage;
using BTreePlusStoragePtr = std::shared_ptr<BTreePlusStorage>;

/// @brief A storage engine that uses a B-Tree to store key-value pairs.
class BTreePlusStorage : public StorageEngine
{
public:
    BTreePlusStorage(size_t order = MixS::BTreePlusOrder);
    ~BTreePlusStorage() override;

    void init() override;
    void shutdown() override;

    void set(const String& key, const String& value) override;
    String get(const String& key) override;
    void remove(const String& key) override;

    std::vector<String> rangeGet(const String& start, const String& end);
private:
    // BTreePlusNodePtr SplitNode(BTreePlusNodePtr node, String& up_key);
    void insertNonFull(BTreePlusInternalNodePtr node, const String& key);
    void splitchild(BTreePlusInternalNodePtr parent, size_t index, BTreePlusInternalNodePtr child);

private:
    // TODO: add your data members here
    BTreePlusInternalNodePtr root;
    BTreePlusLeafNodePtr leaf_head;
    size_t order;

};

} // namespace MixS
