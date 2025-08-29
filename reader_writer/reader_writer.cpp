#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

mutex mtx;
condition_variable cv;
int readerCount = 0;
bool writerPresent = false;

void reader(int id, int readLimit) {
    for (int i = 0; i < readLimit; ++i) {
        // Acquire shared access
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return !writerPresent; });

        readerCount++;
        cout << "Reader " << id << " is reading. Readers active: " << readerCount << endl;
        lock.unlock();

        this_thread::sleep_for(chrono::milliseconds(500));  // simulate read

        // Release shared access
        lock.lock();
        readerCount--;
        cout << "Reader " << id << " finished. Readers left: " << readerCount << endl;
        if (readerCount == 0)
            cv.notify_all();  // notify waiting writers
        lock.unlock();

        this_thread::sleep_for(chrono::milliseconds(500));  // delay before next read
    }
}

void writer(int id, int writeLimit) {
    for (int i = 0; i < writeLimit; ++i) {
        // Request exclusive access
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return !writerPresent && readerCount == 0; });

        writerPresent = true;
        cout << "Writer " << id << " is writing." << endl;
        lock.unlock();

        this_thread::sleep_for(chrono::milliseconds(1000));  // simulate write

        // Release exclusive access
        lock.lock();
        writerPresent = false;
        cout << "Writer " << id << " finished writing." << endl;
        cv.notify_all();  // notify readers and writers
        lock.unlock();

        this_thread::sleep_for(chrono::milliseconds(1000));  // delay before next write
    }
}

int main() {
    // Each reader reads 3 times, each writer writes 2 times
    thread r1(reader, 1, 3);
    thread r2(reader, 2, 3);
    thread w1(writer, 1, 2);
    thread w2(writer, 2, 2);

    r1.join();
    r2.join();
    w1.join();
    w2.join();

    return 0;
}

