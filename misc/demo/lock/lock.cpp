#include <iostream>
#include <unistd.h>
#include <string.h>

#include "../../noncopyable.h"
#include "../../mutex_lock.h"
#include "../../condition.h"

using namespace std;
using namespace engine;

mutex_lock m_mutex;

mutex_lock m_mutex_t;
condition con(m_mutex_t);

void* read(void*) {
    char buf[1024];
    for(;;) {
        memset(buf,'\0',sizeof(buf));
        cin >> buf;
        if(strcmp(buf,"one") == 0) {
            con.notify();
        } else if(strcmp(buf,"all") == 0) {
            con.notifyAll();
        }
    }
}

void* test(void*) {
    for(;;) {
        {
            mutex_lock_guard lock(m_mutex);
            cout << "id: " << gettid() << " time: " << clock() << endl;
        }

        sleep(5);
    }
}

void* test2(void*) {
    for(;;) {
        con.wait();
        cout << "id: " << gettid() << " time: " << clock() << endl;
    }
}

int main() { 
    pthread_t main,pa,pb,pc,pd;
    
    int pl_th0 = pthread_create(&main, NULL, read, NULL);
	int pl_th1 = pthread_create(&pa, NULL, test, NULL);
	int pl_th2 = pthread_create(&pb, NULL, test, NULL);
    int pl_th3 = pthread_create(&pc, NULL, test2, NULL);
	int pl_th4 = pthread_create(&pd, NULL, test2, NULL);

    pthread_join(main, NULL);
    pthread_join(pa, NULL);
	pthread_join(pb, NULL);
    pthread_join(pc, NULL);
	pthread_join(pd, NULL);

    for(;;) {}

    return 0;
}