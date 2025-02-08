#pragma once

#include <base/types.h>

#include <server/HTTP/HTTPServerResponse.h>
#include <server/HTTP/HTTPServerRequest.h>

namespace MixS
{
class HTTPRequestHandler
{
public:
    HTTPRequestHandler() = default;
    virtual ~HTTPRequestHandler() = default;
    virtual void handle(HTTPServerRequest & request, HTTPServerResponse & response) = 0;

private:
    HTTPRequestHandler(const HTTPRequestHandler & handler) = delete;
    HTTPRequestHandler & operator=(const HTTPRequestHandler & handler) = delete;
};




} // namespace MixS

