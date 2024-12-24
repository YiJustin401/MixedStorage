#pragma once

#include <base/types.h>
#include <server/HTTP/HTTPCommon.h>
#include <server/HTTP/HTTPRequestHandler.h>

namespace MixS
{
std::unique_ptr<HTTPRequestHandler> createHTTPRequestHandler(const String & uri);





} // namespace MixS
