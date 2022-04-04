#pragma once 
#ifndef __CONDITION_H__
#define __CONDITION_H__

#include <assert.h>
#include <pthread.h>

namespace engine {
    class condition:public noncopyable {
        private:
        mutex_lock& _mutex;
        pthread_cond_t m_condition;
        public:
        explicit condition(mutex_lock& mutex):_mutex(mutex) {
            pthread_cond_init(&m_condition,nullptr);
        }

        ~condition() {
            pthread_cond_destroy(&m_condition);
        }

        void wait() {
            pthread_cond_wait(&m_condition,_mutex.GetPthreadMutex());
        }

        void notify() {
            pthread_cond_signal(&m_condition);
        }

        void notifyAll() {
            pthread_cond_broadcast(&m_condition);
        }
    };
}

#endif