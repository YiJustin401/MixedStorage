#include <iostream>

#include <storage/BTreePlus/BTreePlusStorage.h>
#include <storage/FileMetadata.h>
#include <gtest/gtest.h>

TEST(BTreePlusStorage, set) {
    MixS::BTreePlusStorage<String, MixS::FileMetadata> storage;
    storage.set("hello", MixS::FileMetadata("world", 0, 0, 0));
    storage.set("hello1", MixS::FileMetadata("world1", 0, 0, 0));
    storage.set("hello2", MixS::FileMetadata("world2", 0, 0, 0));
    storage.set("hello3", MixS::FileMetadata("world3", 0, 0, 0));
    storage.set("hello4", MixS::FileMetadata("world4", 0, 0, 0));
    EXPECT_EQ(storage.get("hello1"), MixS::FileMetadata("world1", 0, 0, 0));
    EXPECT_EQ(storage.get("hello2"), MixS::FileMetadata("world2", 0, 0, 0));
    EXPECT_EQ(storage.get("hello3"), MixS::FileMetadata("world3", 0, 0, 0));
    EXPECT_EQ(storage.get("hello5"), MixS::FileMetadata("", 0, 0, 0));
}