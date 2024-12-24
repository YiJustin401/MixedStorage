#pragma once

#include <base/types.h>

namespace MixS
{

class MixedServer
{
public:
    MixedServer();
    ~MixedServer() = default;

    void start();

private:
    void createServer();

}




} // namespace MixS
