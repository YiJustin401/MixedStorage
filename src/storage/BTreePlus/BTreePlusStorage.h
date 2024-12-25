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
    /// @brief Insert a key-value pair into a non-full node.
    /// @param node The node to insert the key-value pair.
    /// @param key The key to insert.
    /// @param value The value to insert
    void insertNonFull(BTreePlusNodePtr node, const String& key, const String& value);
    void splitchild(BTreePlusNodePtr parent, size_t index, BTreePlusNodePtr child);

private:
    // TODO: add your data members here
    BTreePlusNodePtr root;
    BTreePlusLeafNodePtr leaf_head;
    size_t order;

};

} // namespace MixS
