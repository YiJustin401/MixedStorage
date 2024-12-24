#pragma once

#include <common/ReadBuffer.h>
#include <common/WriteBuffer.h>
#include <storage/BTreePlus/BTreePlusStorage.h>
#include <utils/SingletonTemplate.h>
#include <utils/ThreadPool.h>

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
    const static size_t ThreadPoolSize = 4;
    BTreePlusStorage<String, FileMetadata> file_metadata_storage;
    BTreePlusStorage<String, BlockMetadata> block_metadata_storage;
    ThreadPool thread_pool;

}; // class MixedMetadataServer

} // namespace MixS
