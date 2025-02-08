#include <programs/MixedMetadataServer.h>
#include <logger/log_helper.h>

namespace MixS
{
MixedMetadataServer::MixedMetadataServer()
    : file_metadata_storage(MixS::BTreePlusOrder)
    , block_metadata_storage(MixS::BTreePlusOrder)
    , thread_pool(MixedMetadataServer::ThreadPoolSize)
    {}

/// @brief  start the http server
void MixedMetadataServer::start()
{
    /// add http server
    thread_pool.trySchedule([this]() {
        LOG_INFO("MixedMetadataServer start");
    });

    thread_pool.joinAll();
}

} // namespace MixS


int main(int argc, const char** argv) {
    MixS::MixedMetadataServer server;
    server.start();
    return 0;
}
