#pragma once

#include <server/HTTP/HTTPServerResponse.h>
#include <server/HTTP/HTTPServerRequest.h>

namespace MixS
{

/// @brief Middleware for the HTTP server.
class Middleware
{
public:
    virtual ~Middleware() = default;

    virtual void process(HTTPServerRequest & request, HTTPServerResponse & response) = 0;
    virtual Middleware * next() = 0;
};




} // namespace MixS
