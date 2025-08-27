#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

mutex mtx;
condition_variable cv;
bool ready = false;

// Worker 1: Waits for signal
void worker1() {
    unique_lock<mutex> lock(mtx);
    cout << "worker1: waiting for signal...\n";

    // Wait until 'ready' becomes true
    cv.wait(lock, [] { return ready; });

    // After being notified
    cout << "worker1: got signal, continuing work\n";
}

// Worker 2: Sends signal after delay
void worker2() {
    this_thread::sleep_for(chrono::seconds(2));  // simulate work
    cout << "worker2: doing some work, then sending signal\n";

    unique_lock<mutex> lock(mtx);
    ready = true;
    cv.notify_one();  // Notify worker1
    cout << "worker2: signal sent\n";
}

int main() {
    thread t1(worker1);
    thread t2(worker2);

    t1.join();
    t2.join();

    return 0;
}

