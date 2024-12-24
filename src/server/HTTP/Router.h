#pragma once

#include <unordered_map>

#include <server/HTTP/HTTPRequestHandler.h>
#include <server/HTTP/HTTPServerRequest.h>
#include <server/HTTP/HTTPServerResponse.h>

namespace MixS
{
class Router
{
public:
    Router() = default;

    void addRoute(const String & path, const HTTPRequestHandler & handler)
    {
        routes[path] = handler;
    }

    void removeRoute(const String & path)
    {
        routes.erase(path);
    }
    
    /// @brief Dispatch the request to the appropriate handler.
    void dispatch()
    {
        // route(request.getPath(), request, response);
    }

private:
    std::unordered_map<String, HTTPRequestHandler> routes;


};




} // namespace MixS
