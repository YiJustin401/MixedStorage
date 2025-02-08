#pragma once

#include <vector>
#include <list>
#include <queue>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <atomic>

template <typename Thread>
class ThreadPoolImpl
{
public:
    using Job = std::function<void()>;
    ThreadPoolImpl(size_t max_threads_);

    bool trySchedule(Job job) noexcept;

    void joinAll();

    void worker(typename std::list<Thread>::iterator thread_it);

protected:
    template <typename ReturnType>
    ReturnType scheduleImpl(Job job);


protected:
    size_t max_threads;
    std::atomic<bool> stop = false;

    std::list<Thread> threads;
    std::queue<Job> jobs;
    std::mutex mutex;
    std::condition_variable job_finished;
    std::condition_variable job_added;
};

using ThreadPool = ThreadPoolImpl<std::thread>;
