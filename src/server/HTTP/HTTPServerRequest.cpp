#include <server/HTTP/HTTPServerRequest.h>


namespace MixS
{

void HTTPServerRequest::read(std::unique_ptr<ReadBuffer> & read_buffer)
{
    /// @todo read request from connection
}

void HTTPServerRequest::write(std::unique_ptr<WriteBuffer> & write_buffer) const
{
    /// @todo write request to connection
}

} // namespace MixS
