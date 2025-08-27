#include <iostream>
#include <thread>
#include <mutex>    // for mutex

using namespace std;

int count = 0;     // shared variable
mutex mtx;         // mutex lock

// Worker function 1
void worker1() {
    for (int i = 0; i < 500000; i++) {
        lock_guard<mutex> lock(mtx);  // acquire lock
        count++;                      // critical section
    } // lock released automatically here
}

// Worker function 2
void worker2() {
    for (int i = 0; i < 500000; i++) {
        lock_guard<mutex> lock(mtx);
        count++;
    }
}

int main() {
    thread t1(worker1);
    thread t2(worker2);

    t1.join();
    t2.join();

    cout << "Final count: " << count << "\n";  // should always be 1000000

    return 0;
}

