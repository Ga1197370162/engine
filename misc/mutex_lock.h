#pragma once
#ifndef __MUTEX_LOCK_H__
#define __MUTEX_LOCK_H__

#include <mutex>
#include <assert.h>
#include <pthread.h>
#include <unistd.h>

//  封装互斥器

namespace engine {
    using namespace std;

    class mutex_lock:public noncopyable {
        private:
        pthread_mutex_t mutex;         //  锁对象
        pid_t _pid;                    //  线程id
        public:
        mutex_lock(): _pid(0) {
            pthread_mutex_init(&mutex,nullptr);
        }

        ~mutex_lock() {
            assert(_pid == 0);
            pthread_mutex_destroy(&mutex);
        }

        bool IsLockByThisThread() {
            return _pid == gettid();
        }

        void assertLocked() {
            assert(IsLockByThisThread());
        }

        void lock() {
            pthread_mutex_lock(&mutex);
            _pid = gettid();
        }

        void unlock() {
            _pid = 0;
            pthread_mutex_unlock(&mutex);
        }

        //  condition调用,用户不能调用
        pthread_mutex_t* GetPthreadMutex() {
            return &mutex;
        }
    };

    class mutex_lock_guard :public noncopyable {
        private:
        mutex_lock& m_mutex;
        public:
        explicit mutex_lock_guard(mutex_lock& mutex):m_mutex(mutex) {
            m_mutex.lock();
        }

        ~mutex_lock_guard() {
            m_mutex.unlock();
        }
    };

    #define mutex_lock_guard(x) static_assert(false,"missing mutex guard var name")
}

#endif