#pragma once

#include <base/types.h>

namespace MixS
{
class FileMetadata
{
public:
    String file_path;
    u64 file_size;
    time_t create_time;
    time_t last_modify_time;

    FileMetadata(String file_path, u64 file_size, time_t create_time, time_t last_modify_time)
        : file_path(file_path), file_size(file_size), create_time(create_time), last_modify_time(last_modify_time)
    {
    }

    static FileMetadata getNull()
    {
        return FileMetadata("", 0, 0, 0);
    }

    bool operator ==(const FileMetadata &rhs) const
    {
        return file_path == rhs.file_path && file_size == rhs.file_size && create_time == rhs.create_time && last_modify_time == rhs.last_modify_time;
    }
};




} // namespace MixS
