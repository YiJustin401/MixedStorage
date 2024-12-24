#pragma once

#include <base/types.h>
#include <storage/Storage.h>

namespace MixS
{
class StorageEngine
{
public:
    virtual ~StorageEngine() = default;

    virtual void init() = 0;
    virtual void shutdown() = 0;

    virtual void set(const String& key, const String& value) = 0;
    virtual String get(const String& key) = 0;
    virtual void remove(const String& key) = 0;
};
}
