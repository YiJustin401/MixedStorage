#pragma once

#include <vector>
#include <queue>
#include <thread>
#include <functional>


template <typename F = std::function<void()>>
class ThreadPool
{
public:
    ThreadPool(size_t size)
        : size(size)
    {
        for (size_t i = 0; i < size; i++)
        {
            threads.push_back(std::thread([this] {
                while (!stop)
                {
                    std::unique_lock<std::mutex> lock(mutex);
                    if (!tasks.empty())
                    {
                        F task = std::move(tasks.front());
                        tasks.pop();
                        lock.unlock();
                        task();
                    }
                    else
                    {
                        cv.wait(lock);
                    }
                }
            }));
        }
    }

    void addTask(F && task)
    {
        std::unique_lock<std::mutex> lock(mutex);
        tasks.push(std::forward<F>(task));
        cv.notify_one();
    }

    void stop()
    {
        stop = true;
        cv.notify_all();
        for (auto & thread : threads)
        {
            thread.join();
        }
    }

private:
    size_t size = 0;
    bool stop = false;

    std::vector<std::thread> threads;
    std::queue<F> tasks;
    std::mutex mutex;
    std::condition_variable cv;

}; // class ThreadPool
