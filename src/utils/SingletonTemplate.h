#pragma once

template <typename T>
class SingletonTemplate
{
public:
    template <typename... Args>
    static T & getInstance(Args &&... args)
    {
        static T instance = T(std::forward<Args>(args)...);
        return instance;
    }

protected:
    SingletonTemplate() = default;
    ~SingletonTemplate() = default;
    SingletonTemplate(const SingletonTemplate &) = delete;
    SingletonTemplate & operator=(const SingletonTemplate &) = delete;

}; // class SingletonTemplate
