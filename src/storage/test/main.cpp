#include <iostream>

#include <storage/BTreePlus/BTreePlusStorage.h>

int main()
{
    MixS::BTreePlusStorage storage;
    storage.set("hello", "world");
    std::cout << storage.get("hello") << std::endl;
    return 0;
}