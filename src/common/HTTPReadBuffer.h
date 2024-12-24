#pragma once

#include <common/ReadBuffer.h>
#include <server/HTTP/HTTPCommon.h>


namespace MixS
{

class HTTPReadBuffer : public ReadBuffer
{
public:
    HTTPReadBuffer(Socket & socket)
        : ReadBuffer(nullptr, 0)
        , socket(socket)
    {

    }





private:
    virtual bool nextImpl() override
    {
        return false;
    }

    Socket & socket;
    Streambuf http_stream;
};

} // namespace MixS
