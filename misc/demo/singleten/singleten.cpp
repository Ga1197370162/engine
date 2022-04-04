//  测试单例类对象
#include <iostream>
#include <memory>

#include "../../noncopyable.h"
#include "../../singleten.h"

using namespace std;
using namespace engine;

class A {
public:
    A(){
        cout << "A 构造" << endl;
    }

    ~A(){
        cout << "A 析构" << endl;
    }

    void test(){
        cout << "A test" << endl;
    }
};

class B {
public:
    B(){
        cout << "B 构造" << endl;
    }

    ~B(){
        cout << "B 析构" << endl;
    }

    void test(){
        cout << "B test" << endl;
    }
};

int main(){
    {
        A* a = singleten<A>::GetInstance();
        a->test();

        B* b = singleten<B>::GetInstance();
        b->test();
        
        int* c = singleten<int>::GetInstance();
        *c = 10;
    }

    {
        A* a = singleten<A>::GetInstance();
        a->test();

        int* b = singleten<int>::GetInstance();
        cout << *b << endl;
    }

    return 0;
}