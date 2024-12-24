#pragma once

#include <server/HTTP/HTTPCommon.h>


namespace MixS
{
class HTTPConnectFactory
{
public:
    HTTPConnectFactory() = default;
    ~HTTPConnectFactory() = default;

    void createConnect(const String & listen_address, const String & port);

    void start();
    void stop();
    void config();






}; // class HTTPConnectFactory

} // namespace MixS
