#pragma once

#include <server/HTTP/HTTPCommon.h>
#include <server/HTTP/HTTPRequestHandler.h>



namespace MixS
{

class S3RequestHandler : public HTTPRequestHandler
{
public:
    S3RequestHandler();
    ~S3RequestHandler() = default;
    void handle(HTTPServerRequest & request, HTTPServerResponse & response) override;

private:
    /// [TODO]: add member variables


};
} // namespace MixS
