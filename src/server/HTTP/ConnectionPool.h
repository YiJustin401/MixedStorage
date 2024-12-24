#pragma once

#include <base/types.h>
#include <list>

#include <server/HTTP/HTTPCommon.h>
#include <server/HTTP/Connection.h>

namespace MixS
{
class ConnectionPool
{
public:
    ConnectionPool() = default;

    Connection acquire(IoContext & ioContext)
    {
        std::lock_guard<std::mutex> lock(mutex);
        if (connections.empty())
        {
            return Connection(ioContext);
        }
        else
        {
            Connection connection = std::move(connections.front());
            connections.pop_front();
            return connection;
        }
    }

    void release(Connection & connection)
    {
        std::lock_guard<std::mutex> lock(mutex);
        connections.push_back(connection);
    }

    void closeAll()
    {
        std::lock_guard<std::mutex> lock(mutex);
        for (auto & connection : connections)
        {
            connection.close();
        }
    }

private:
    std::list<Connection> connections;
    std::mutex mutex;
}


} // namespace MixS
