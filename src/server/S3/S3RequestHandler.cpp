#include <server/S3/S3RequestHandler.h>

namespace MixS
{

S3RequestHandler::S3RequestHandler()
{

};

void S3RequestHandler::handle(HTTPServerRequest & request, HTTPServerResponse & response)
{
    /// http mathod:
    /// GET /bucket/object
    /// PUT /bucket/object
    /// DELETE /bucket/object
    /// HEAD /bucket/object
    /// POST /bucket/object

    
};







} // namespace MixS
