#pragma once

#include <base/types.h>
#include <common/ReadBuffer.h>
#include <common/WriteBuffer.h>


namespace MixS
{

enum class HTTPStatus
{
    OK = 200,
    CREATED = 201,
    ACCEPTED = 202,
    NO_CONTENT = 204,
    MOVED_PERMANENTLY = 301,
    FOUND = 302,
    SEE_OTHER = 303,
    NOT_MODIFIED = 304,
    TEMPORARY_REDIRECT = 307,
    PERMANENT_REDIRECT = 308,
    BAD_REQUEST = 400,
    UNAUTHORIZED = 401,
    FORBIDDEN = 403,
    NOT_FOUND = 404,
    METHOD_NOT_ALLOWED = 405,
    REQUEST_TIMEOUT = 408,
    CONFLICT = 409,
    GONE = 410,
    LENGTH_REQUIRED = 411,
    PAYLOAD_TOO_LARGE = 413,
    URI_TOO_LONG = 414,
    UNSUPPORTED_MEDIA_TYPE = 415,
    RANGE_NOT_SATISFIABLE = 416,
    UPGRADE_REQUIRED = 426,
    TOO_MANY_REQUESTS = 429,
    INTERNAL_SERVER_ERROR = 500,
    NOT_IMPLEMENTED = 501,
    BAD_GATEWAY = 502,
    SERVICE_UNAVAILABLE = 503,
    GATEWAY_TIMEOUT = 504,
    HTTP_VERSION_NOT_SUPPORTED = 505,
    NETWORK_AUTHENTICATION_REQUIRED = 511
};

class HTTPServerResponse
{
public:
    HTTPServerResponse();
    HTTPServerResponse(const HTTPStatus & status, const String & response, const String & version);

    void setStatus(const HTTPStatus & status) { this->status = status; }
    HTTPStatus getStatus() const { return status; }
    void setResponse(const String & response) { this->response = response; }
    String getResponse() const { return response; }
    void setVersion(const String & version) { this->version = version; }
    String getVersion() const { return version; }

    void write(std::unique_ptr<WriteBuffer> & write_buffer) const;
    void read(std::unique_ptr<ReadBuffer> & read_buffer);

private:
    HTTPStatus status;
    String response;
    String version;

};


} // namespace MixS
