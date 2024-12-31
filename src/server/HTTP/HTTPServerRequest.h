#pragma once

#include <base/types.h>
#include <server/HTTP/HTTPServerResponse.h>
#include <server/HTTP/HTTPCommon.h>
#include <server/HTTP/Connection.h>

namespace MixS
{
class HTTPServerRequest
{
public:
    HTTPServerRequest(IoContext & ioContext)
        : connection(ioContext)
        , read_buffer(std::move(connection.read()))
    {}


private:
    Connection connection;
    Buffer read_buffer;

    void readRequest();
};




} // namespace MixS
