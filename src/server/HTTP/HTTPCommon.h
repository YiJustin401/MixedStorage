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
using AddressV4 = boost::asio::ip::address_v4;
using AddressV6 = boost::asio::ip::address_v6;
using Buffer = boost::asio::mutable_buffer;

Address make_address(const std::string & str)
{
    return boost::asio::ip::make_address(str);
}

} // namespace MixS
