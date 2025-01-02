#pragma once

#include <vector>
#include <iostream>

#include <base/types.h>
#include <server/HTTP/HTTPServerResponse.h>
#include <server/HTTP/HTTPCommon.h>
#include <server/HTTP/Connection.h>

namespace MixS
{

enum class HTTPMethod
{
    GET,
    POST,
    PUT,
    DELETE,
    HEAD,
    OPTIONS,
    PATCH,
    TRACE,
    CONNECT
};

class HTTPServerRequest
{
public:
    HTTPServerRequest(
        IoContext & ioContext,
        const HTTPMethod & method,
        const String & uri,
        const String & version,
        const std::vector<std::pair<String, String>> & headers = {})
        : connection(ioContext)
        , method(method)
        , uri(uri)
        , version(version)
        , headers(headers)
    {}

    void setMethod(const HTTPMethod & method)
    {
        this->method = method;
    }

    HTTPMethod getMethod() const
    {
        return method;
    }

    void setUri(const String & uri)
    {
        this->uri = uri;
    }

    String getUri() const
    {
        return uri;
    }

    void setVersion(const String & version)
    {
        this->version = version;
    }

    String getVersion() const
    {
        return version;
    }

    void addHeader(const String & key, const String & value)
    {
        headers.push_back(std::make_pair(key, value));
    }

    void read(std::istream & is)
    {
        // read the request
    }

    void write(std::ostream & os)
    {
        // write the request
    }

    // std::istream & getInputStream()
    // {
        
    // }

private:
    Connection connection;

    HTTPMethod method;
    String uri;
    String version;
    std::vector<std::pair<String, String>> headers;
};




} // namespace MixS
