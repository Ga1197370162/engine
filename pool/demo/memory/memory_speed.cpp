#include <iostream>
#include <unistd.h>
#include <vector>

#include "../../memory_pool.h"

using namespace std;
using namespace engine;

//  与 new 速度对比

const auto count = 100;
const auto MEMORY_SIZE = 1;

void new_memory_size(size_t size) {
    clock_t now,old;
    vector<char*> vec;
    vec.reserve(count + 100);     //  提前分配这么多空间，避免插入时又分配空间浪费时间
    old = clock();
    for(int i = 0;i < count; ++i) {
        for(int j = 0;j < count; ++j) {
            vec.push_back(new char[(size+i)%127]);
        }
    }
    now = clock();
    cout << "time = " << now - old << endl;

    for(auto it = vec.begin();it != vec.end(); ++it) {
        delete[] (*it);
    }

    old = clock();
    for(int i = 0;i < count; ++i) {
        for(int j = 0;j < count; ++j) {
            make_memory<char>((size+i)%127);
        }
    }
    now = clock();
    cout << "time = " << now - old << endl;
}

int main() {
    new_memory_size(MEMORY_SIZE);

    return 0;
}