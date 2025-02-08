#include <utils/ThreadPool.h>

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
    std::unique_lock<std::mutex> lock(mutex);
    job_finished.wait(lock, [this]() { return threads.empty(); });
}

template <typename Thread>
void ThreadPoolImpl<Thread>::worker(typename std::list<Thread>::iterator /*thread_it*/)
{
    while (true)
    {
        Job job;
        {
            std::unique_lock<std::mutex> lock(mutex);
            job_added.wait(lock, [this]() { return stop || !jobs.empty(); });
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
    std::unique_lock<std::mutex> lock(mutex);
    while (threads.size() >= max_threads)
    {
        job_added.wait(lock);
    }
    threads.emplace_front();
    threads.front() = std::thread(&ThreadPoolImpl<Thread>::worker, this, threads.begin());
    jobs.push(job);

    if constexpr (!std::is_void_v<ReturnType>)
    {
        return ReturnType();
    }
}

template class ThreadPoolImpl<std::thread>;