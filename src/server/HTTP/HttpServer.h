#pragma once

#include <server/HTTP/HTTPCommon.h>
#include <server/IServer.h>


namespace MixS
{

class HTTPServer : public IServer
{
public:
    HTTPServer();
    ~HTTPServer();

    void start() override;
    void stop() override;
    void config() override;
private:
    void createServer(const String & listen_address, const String & port);

};
} // namespace MixS
