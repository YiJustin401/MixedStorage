#pragma once

#include <base/types.h>

#include <server/HTTP/HTTPServerResponse.h>
#include <server/HTTP/HTTPServerRequest.h>

namespace MixS
{
class HTTPRequestHandler
{
public:
    virtual ~HTTPRequestHandler() = default;
    virtual void handle(HTTPServerRequest & request, HTTPServerResponse & response) = 0;
};




} // namespace MixS

