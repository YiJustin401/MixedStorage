#include <server/HTTP/HTTPServerResponse.h>

namespace MixS
{
HTTPServerResponse::HTTPServerResponse()
    : status(HTTPStatus::OK)
    , response("")
    , version("HTTP/1.1")
{

}

HTTPServerResponse::HTTPServerResponse(const HTTPStatus & status, const String & response, const String & version)
    : status(status)
    , response(response)
    , version(version)
{
}

void HTTPServerResponse::write(std::unique_ptr<WriteBuffer> & write_buffer) const
{
    /// @todo write response to connection
}

void HTTPServerResponse::read(std::unique_ptr<ReadBuffer> & read_buffer)
{
    /// @todo read response from connection
}

} // namespace MixS
