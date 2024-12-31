#pragma once

#include <base/types.h>
#include <storage/StorageEngine.h>

namespace MixS
{

/// @brief A metadata server that stores metadata for the MixS system.
class MetadataServer
{
public:
    void addFile(const String& filename, const FileMetadata& fileMetadata);
    FileMetadata getFile(const String& filename);
    void removeFile(const String& filename);

private:
    // StorageEngine<String, String> storageEngine;
    FileMetadataStoragePtr fileMetadataStorage;
    BlockMetadataStoragePtr blockMetadataStorage;



};






} // namespace MixS
