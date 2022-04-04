#include <iostream>
#include <unistd.h>

#include "../../noncopyable.h"
#include "../../mutex_lock.h"
#include "../../condition.h"

using namespace std;
using namespace engine;

mutex_lock m_mutex;

void* test(void*) {
    for(;;) {
        {
            mutex_lock_guard lock(m_mutex);
            cout << "id: " << gettid() << " time: " << clock() << endl;
        }

        sleep(5);
    }
}

int main() { 
    pthread_t pa,pb;
 
	int pl_th1 = pthread_create(&pa, NULL, test, NULL);
	int pl_th2 = pthread_create(&pb, NULL, test, NULL);

    pthread_join(pa, NULL);
	pthread_join(pb, NULL);

    for(;;) {

    }

    return 0;
}