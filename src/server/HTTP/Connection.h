#pragma once

#include <base/types.h>
#include <server/HTTP/HTTPCommon.h>


namespace MixS
{
class Connection
{
public:
    Connection(IoContext & ioContext)
        : socket(ioContext)
    {}

    Connection(const Connection & connection) = delete;

    Connection(Connection && connection) noexcept
        : socket(std::move(connection.socket))
    {}

    Buffer read()
    {
        Buffer buffer;
        socket.read_some(buffer);
        return buffer;
    }

    void write(const Buffer & buffer)
    {
        socket.write_some(buffer);
    }

    void close()
    {
        socket.close();
    }
private:
    Socket socket;
};


} // namespace MixS
