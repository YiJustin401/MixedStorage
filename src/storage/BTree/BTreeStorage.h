#pragma once

#include <vector>

#include <storage/StorageEngine.h>
#include <storage/BTree/BTreeNode.h>

namespace MixS
{

/// @brief A storage engine that uses a B-Tree to store key-value pairs.
class BTreeStorage : public StorageEngine
{
public:
    BTreeStorage();
    ~BTreeStorage() override;

    void init() override;
    void shutdown() override;

    void set(const String& key, const String& value) override;
    String get(const String& key) override;
    void remove(const String& key) override;

    std::vector<String> rangeGet(const String& start, const String& end);
private:
    // TODO: add your data members here
    BTreeNode* root;
};

} // namespace MixS
