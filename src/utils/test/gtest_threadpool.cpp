#include <utils/ThreadPool.h>
#include <mutex>
#include <gtest/gtest.h>

/// @brief Test ThreadPool
TEST(ThreadPool, testThreadPool)
{
    ThreadPool pool(4);
    std::vector<int> results;
    std::set<int> results_set;
    std::mutex mutex;
    for (int i = 0; i < 100; ++i)
    {
        pool.trySchedule([&results, &mutex ,i] { 
            std::lock_guard<std::mutex> lock(mutex);
            results.push_back(i);
            });
    }
    pool.joinAll();
    ASSERT_EQ(results.size(), 100);
    for (const auto & result : results)
    {
        ASSERT_TRUE(!results_set.contains(result));
        results_set.insert(result);
    }
}