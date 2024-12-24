#include <utils/ThreadPool.h>
#include <logger/log_helper.h>

template <typename Thread>
ThreadPoolImpl<Thread>::ThreadPoolImpl(size_t max_threads_)
    : max_threads(max_threads_)
{
}

template <typename Thread>
bool ThreadPoolImpl<Thread>::trySchedule(Job job) noexcept
{
    scheduleImpl<void>(job);
    return true;
}

template <typename Thread>
void ThreadPoolImpl<Thread>::joinAll()
{
    {
        std::unique_lock<std::mutex> lock(mutex);
        job_finished.wait(lock, [this]() { return jobs.empty(); });
        stop.store(true);
        job_added.notify_all();
    }
    for (auto &thread : threads)
    {
        thread.join();
    }
}

template <typename Thread>
void ThreadPoolImpl<Thread>::worker(typename std::list<Thread>::iterator /*thread_it*/)
{
    while (!stop.load())
    {
        Job job;
        {
            std::unique_lock<std::mutex> lock(mutex);
            job_added.wait(lock, [this]() { return stop.load() || !jobs.empty(); });
            if (stop && jobs.empty())
            {
                return;
            }
            job = std::move(jobs.front());
            jobs.pop();
        }
        job();
        std::unique_lock<std::mutex> lock(mutex);
        job_finished.notify_one();
    }
}

template <typename Thread>
template <typename ReturnType>
ReturnType ThreadPoolImpl<Thread>::scheduleImpl(Job job)
{
    {
        std::unique_lock<std::mutex> lock(mutex);
        if (threads.size() <= max_threads)
        {
            threads.emplace_front();
            threads.front() = std::thread(&ThreadPoolImpl<Thread>::worker, this, threads.begin());
        }
        // job_added.wait(lock);
        jobs.push(job);
        job_added.notify_all();
    }

    if constexpr (!std::is_void_v<ReturnType>)
    {
        return ReturnType();
    }
}

template class ThreadPoolImpl<std::thread>;