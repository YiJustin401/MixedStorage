#pragma once

#include <common/ReadBuffer.h>
#include <common/WriteBuffer.h>
#include <storage/BTreePlus/BTreePlusStorage.h>
#include <utils/SingletonTemplate.h>

namespace MixS
{
class MixedMetadataServer : public SingletonTemplate<MixedMetadataServer>
{
public:
    MixedMetadataServer();
    ~MixedMetadataServer() = default;

    void start();
    void stop();
    void config();

    void execute(ReadBuffer & read_buffer, WriteBuffer & write_buffer);

private:
    BTreePlusStorage<String, FileMetadata> file_metadata_storage;
    BTreePlusStorage<String, BlockMetadata> block_metadata_storage;

}; // class MixedMetadataServer

} // namespace MixS
