#pragma once
#ifndef __NONCOPYABLE_H__
#define __NONCOPYABLE_H__

//  无法拷贝

namespace engine {
    struct noncopyable {
        private:
        noncopyable(const noncopyable&) = delete;
        noncopyable& operator=(const noncopyable&) = delete;
        public:
        noncopyable() = default;
        ~noncopyable() = default;
    };
}

#endif