#include <iostream>

#include <storage/BTreePlus/BTreePlusStorage.h>

int main()
{
    MixS::BTreePlusStorage storage;
    storage.set("hello", "world");
    storage.set("hello1", "world1");
    storage.set("hello2", "world2");
    storage.set("hello3", "world3");
    storage.set("hello4", "world4");
    std::cout << storage.get("hello1") << std::endl;
    return 0;
}