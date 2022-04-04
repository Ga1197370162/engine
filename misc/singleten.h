#pragma once 
#ifndef __SINGLETEN_H__
#define __SINGLETEN_H__

#include <memory>
#include <pthread.h>

//  单例类模板
namespace engine {
    using namespace std;
    
    template<typename T>
    class singleten:public noncopyable {
        private:
        static unique_ptr<T> single;                    //  唯一管理对象
        static pthread_once_t once;

        singleten() {}
        ~singleten() {}

        static void initiazer() {
            single = make_unique<T>();
        }
        public:
        static T* GetInstance() {
            pthread_once(&once,&singleten::initiazer);
            return single.get();
        }
    };

    template<typename T>
    unique_ptr<T> singleten<T>::single = nullptr;

    template<typename T>
    pthread_once_t singleten<T>::once = PTHREAD_ONCE_INIT;
}

#endif