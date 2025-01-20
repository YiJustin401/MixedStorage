#include <programs/MixedMetadataServer.h>

namespace MixS
{
MixedMetadataServer::MixedMetadataServer()
    : file_metadata_storage(MixS::BTreePlusOrder)
    , block_metadata_storage(MixS::BTreePlusOrder)
    {}

/// @brief  start the http server
void MixedMetadataServer::start()
{

}




} // namespace MixS
