#include <iostream>
#include <unistd.h>
#include <time.h>

#include "../../memory_pool.h"

using namespace std;
using namespace engine;

bool shutdown = false;
//  多线程环境下竞争关系

void* test(void*) {
    char buf[10];
    for(;;) {
        if(shutdown) break;
        cin >> buf;
        if(strcmp(buf,"quit") == 0) shutdown = true;
    }

    return nullptr;
}

void* alloc_7(void *) {
    for(;;) {
        if(shutdown) break;
        printf("id: %d time: %ld address: %p\n", gettid(),clock(),make_memory<char>(7));
        sleep(10);
    }

    return nullptr;
}

void* alloc_31(void *) {
    for(;;) {
        if(shutdown) break;
        printf("id: %d time: %ld address: %p\n", gettid(),clock(),make_memory<char>(31));
        sleep(10);
    }

    return nullptr;
}

void* alloc_200(void *) {
    for(;;) {
        if(shutdown) break;
        printf("id: %d time: %ld address: %p\n", gettid(),clock(),make_memory<char>(200));
        sleep(10);
    }

    return nullptr;
}

int main() {
    pthread_t main,pa,pb,pc,pd,pe,pf;
    
    int z = pthread_create(&main, NULL, test, NULL);
    int pl_th0 = pthread_create(&pf, NULL, alloc_7, NULL);
	int pl_th1 = pthread_create(&pa, NULL, alloc_7, NULL);
	int pl_th2 = pthread_create(&pb, NULL, alloc_31, NULL);
    int pl_th3 = pthread_create(&pc, NULL, alloc_31, NULL);
	int pl_th4 = pthread_create(&pd, NULL, alloc_200, NULL);
    int pl_th5 = pthread_create(&pe, NULL, alloc_200, NULL);

    pthread_join(main, NULL);
    pthread_join(pa, NULL);
	pthread_join(pb, NULL);
    pthread_join(pc, NULL);
	pthread_join(pd, NULL);
    pthread_join(pe, NULL);
    pthread_join(pf, NULL);
    
    for(;;) {
        if(shutdown) break;
    }

    return 0;
}