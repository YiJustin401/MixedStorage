#pragma once

#include "HTTPHandlerFactory.h"

namespace MixS
{

std::unique_ptr<HTTPRequestHandler> createHTTPRequestHandler(const String & uri)
{
    return nullptr;



};

} // namespace MixS
