#pragma once

#include <memory>

#include <base/types.h>
#include <storage/Storage.h>
#include <storage/FileMetadata.h>
#include <storage/BlockMetadata.h>

namespace MixS
{
/// @brief A storage engine that uses a B-Tree to store key-value pairs.
template <typename KEY, typename VALUE>
class StorageEngine
{
public:
    virtual ~StorageEngine() = default;

    virtual void init() = 0;
    virtual void shutdown() = 0;

    virtual void set(const KEY& key, const VALUE& value) = 0;
    virtual VALUE get(const KEY& key) = 0;
    virtual void remove(const KEY& key) = 0;
};

using FileMetadataStorage = StorageEngine<String, FileMetadata>;
using FileMetadataStoragePtr = std::shared_ptr<FileMetadataStorage>;
using BlockMetadataStorage = StorageEngine<String, BlockMetadata>;
using BlockMetadataStoragePtr = std::shared_ptr<BlockMetadataStorage>;
}
