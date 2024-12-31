#pragma once

#include <boost/asio.hpp>

namespace MixS
{
using Endpoint = boost::asio::ip::tcp::endpoint;
using Socket = boost::asio::ip::tcp::socket;
using Acceptor = boost::asio::ip::tcp::acceptor;
using IoContext = boost::asio::io_context;
using Resolver = boost::asio::ip::tcp::resolver;
using Streambuf = boost::asio::streambuf;
using Error = boost::system::error_code;
using Address = boost::asio::ip::address;
using Buffer = boost::asio::mutable_buffer;

} // namespace MixS
