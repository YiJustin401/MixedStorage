#include "HttpServer.h"
#include <server/HTTP/HTTPServerRequest.h>
#include <server/HTTP/HTTPServerResponse.h>
#include <logger/log_helper.h>
#include <common/WriteBuffer.h>

namespace MixS
{
HTTPServer::HTTPServer()
{


}



HTTPServer::~HTTPServer()
{

}


void HTTPServer::start()
{
    createServer("127.0.0.1", "5143");
};


void HTTPServer::stop()
{

};

void HTTPServer::config()
{

};

void HTTPServer::createServer(const String & listen_address, const String & port)
{
    try
    {
        IoContext io_context;
        Acceptor acceptor(io_context, Endpoint(make_address(listen_address), std::stoi(port)));
        Socket socket(io_context);
        acceptor.accept(socket);
        Streambuf streambuf;
        Error error;
        boost::asio::read_until(socket, streambuf, "\r\n\r\n", error);
        if (error && error != boost::asio::error::eof)
        {
            throw boost::system::system_error(error);
        }
        std::istream stream(&streambuf);
        String request;
        std::getline(stream, request);
        LOG_INFO("Request: {}", request);
        HTTPServerRequest http_request(io_context, HTTPMethod::GET, "/index.html", "HTTP/1.1");
        http_request.setMethod(HTTPMethod::GET);
        http_request.setUri("/index.html");
        http_request.setVersion("HTTP/1.1");
        HTTPServerResponse http_response(HTTPStatus::OK, "Hello World", "HTTP/1.1");
        http_response.setStatus(HTTPStatus::OK);
        http_response.setResponse("Hello World");
        http_response.setVersion("HTTP/1.1");
        std::unique_ptr<WriteBuffer> write_buffer = std::make_unique<WriteBuffer>(nullptr, 0);
        http_response.write(write_buffer);
        // boost::asio::write(socket, boost::asio::buffer(write_buffer->getBuffer(), write_buffer->getSize()));
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}

} // namespace MixS
