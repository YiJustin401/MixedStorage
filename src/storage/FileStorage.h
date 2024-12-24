#pragma once

#include <Storage.h>


namespace MixS
{
class FileStorage : public Storage
{
public:
    explicit FileStorage(const String& filename);
    ~FileStorage() override;

    void init() override;
    void shutdown() override;

    void writeBlock(u64 blockId, const u8* data, size_t size) override;
    void readBlock(u64 blockId, u8* data, size_t size) override;

private:
    // TODO: add your data members here
    int file_descriptor;
};

} // namespace MixS
