#include <iostream>
#include <thread>
#include <unistd.h>  // for sleep()
using namespace std;

void worker1() {
    for (int i = 0; i < 5; i++) {
        sleep(1);  // pause for 1 second
        cout << "[Worker 1] → Step " << i << " completed ✅" << endl;
    }
}


void worker2() {
    for (int i = 0; i < 5; i++) {
        sleep(1);  // pause for 1 second
        cout << "[Worker 2] → Step " << i << " completed ✅" << endl;
    }
}


int main() {
    thread t1(worker1);
    thread t2(worker2);

    t1.join();  // wait for thread 1
    t2.join();  // wait for thread 2

    return 0;
}
