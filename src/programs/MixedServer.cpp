#include <programs/MixedServer.h>
#include <logger/log_helper.h>

namespace MixS
{

MixedServer::MixedServer()
{
}

void MixedServer::start()
{
    createServer();
}

void MixedServer::createServer()
{
    LOG_INFO("MixedServer start");
    /// 实现服务器的创建，这里只是简单的打印日志
    /// 创建服务器时，需要绑定端口，监听端口，http 服务器，rpc 服务器等
}
} // namespace MixS

int main(int argc, const char** argv) {
    MixS::MixedServer server;
    server.start();
    return 0;
}
