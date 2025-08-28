

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

using namespace std;

// Buffer and max size
queue<int> buffer;
const unsigned int MAX_SIZE = 5;

// Semaphores (simulated using mutex + condition_variable)
mutex mtx;
condition_variable cv_full, cv_empty;

void producer(int id) {
    int item = 0;
    while (true) {
        unique_lock<mutex> lock(mtx);
        cv_empty.wait(lock, [] { return buffer.size() < MAX_SIZE; });

        item++;
        buffer.push(item);
        cout << "Producer " << id << " produced: " << item << endl;

        lock.unlock();
        cv_full.notify_one();  // Notify consumer

        this_thread::sleep_for(chrono::milliseconds(500));  // Simulate delay
    }
}

void consumer(int id) {
    while (true) {
        unique_lock<mutex> lock(mtx);
        cv_full.wait(lock, [] { return !buffer.empty(); });

        int item = buffer.front();
        buffer.pop();
        cout << "Consumer " << id << " consumed: " << item << endl;

        lock.unlock();
        cv_empty.notify_one();  // Notify producer

        this_thread::sleep_for(chrono::milliseconds(1000));  // Simulate delay
    }
}

int main() {
    thread p1(producer, 1);
    thread p2(producer, 2);
    thread c1(consumer, 1);
    thread c2(consumer, 2);

    p1.join();
    p2.join();
    c1.join();
    c2.join();

    return 0;
}

