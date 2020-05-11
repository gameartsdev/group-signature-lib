
#pragma once
#include <iostream>
#include <memory>
#include <pthread.h>
#include <utility>

namespace dev
{
namespace eth
{
//mutex encapsulation
class Locker
{
private:
    pthread_mutex_t m_lock;

public:
    Locker() { pthread_mutex_init(&m_lock, NULL); }

    ~Locker() { pthread_mutex_destroy(&m_lock); }

    void lock() { pthread_mutex_lock(&m_lock); }
    void unlock() { pthread_mutex_unlock(&m_lock); }
};

//manager mutx
class GuardLock
{
private:
    Locker &m_lock;

public:
    GuardLock(Locker &_m_lock) : m_lock(_m_lock)
    {
        m_lock.lock();
    }

    ~GuardLock() { m_lock.unlock(); }
};

//singleton pattern
template <typename T>
class singleton
{
private:
    //forbid assignment and construction
    singleton(const singleton &);
    singleton();
    singleton &operator=(const singleton &);

    static std::shared_ptr<T> p_value;
    static Locker mutex;

public:
    //create instance with singleton pattern
    template <typename... Args>
    static std::shared_ptr<T> instance(Args &&... args)
    {
        if (!p_value)
        {
            mutex.lock();
            p_value = std::make_shared<T>(std::forward<Args>(args)...);
            mutex.unlock();
        }
        return p_value;
    }

    /*template<typename... Args>
    static T* instance_ptr(Args&&... args)
    {
        return (intance(std::forward<Args>(args)...)).get();
    }*/
};
template <typename T>
std::shared_ptr<T> singleton<T>::p_value;
template <typename T>
Locker singleton<T>::mutex = Locker(); //init mutex
} // namespace eth
} // namespace dev
