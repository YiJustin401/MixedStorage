#pragma once

#include <base/types.h>

#include <vector>

namespace MixS
{
enum class Method
{
    GET,
    POST,
    PUT,
    DELETE,
    HEAD,
    OPTIONS,
    PATCH,
    TRACE,
    CONNECT,
    UNKNOWN
};


class HTTPRequest
{
public:
    HTTPRequest()
        : http_method(Method::UNKNOWN)
    {}

    void setMethod(Method method)
    {
        http_method = method;
    }

    void setVersion(const String & version)
    {
        http_version = version;
    }

    void setURL(const String & url)
    {
        this->url = url;
    }

    void addHeader(const String & key, const String & value)
    {
        headers.push_back(std::make_pair(key, value));
    }


private:
    Method http_method;
    String http_version;
    String url;
    std::vector<std::pair<String, String>> headers;



};





} // namespace MixS
