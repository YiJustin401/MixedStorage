#include <utils/ThreadPool.h>
#include <gtest/gtest.h>

/// @brief Test ThreadPool
TEST(ThreadPool, testThreadPool)
{
    ThreadPool pool(4);
    std::vector<int> results;
    for (int i = 0; i < 100; ++i)
    {
        pool.trySchedule([&results, i] { results.push_back(i); });
    }
    pool.joinAll();
    ASSERT_EQ(results.size(), 100);
    for (int i = 0; i < 100; ++i)
    {
        ASSERT_EQ(results[i], i);
    }
}