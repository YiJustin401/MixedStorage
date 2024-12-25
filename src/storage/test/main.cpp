#include <iostream>

#include <storage/BTreePlus/BTreePlusStorage.h>
#include <gtest/gtest.h>

TEST(BTreePlusStorage, set) {
    MixS::BTreePlusStorage storage;
    storage.set("hello", "world");
    storage.set("hello1", "world1");
    storage.set("hello2", "world2");
    storage.set("hello3", "world3");
    storage.set("hello4", "world4");
    EXPECT_EQ(storage.get("hello1"), "world1");
    EXPECT_EQ(storage.get("hello2"), "world2");
    EXPECT_EQ(storage.get("hello3"), "world3");
    EXPECT_EQ(storage.get("hello5"), "null");
}