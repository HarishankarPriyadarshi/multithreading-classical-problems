#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

const int N = 5;               // number of philosophers
mutex forks[N];                // one mutex for each fork

void philosopher(int id) {
    for (int i = 0; i < 3; ++i) { // each philosopher eats 3 times
        cout << "Philosopher " << id << " is thinking.\n";
        this_thread::sleep_for(chrono::milliseconds(500));

        // Asymmetric solution:
        if (id % 2 == 0) {
            forks[id].lock();                  // pick left
            forks[(id + 1) % N].lock();        // pick right
        } else {
            forks[(id + 1) % N].lock();        // pick right
            forks[id].lock();                  // pick left
        }

        cout << "Philosopher " << id << " is eating.\n";
        this_thread::sleep_for(chrono::milliseconds(500));

        // put forks down
        forks[id].unlock();
        forks[(id + 1) % N].unlock();
    }
}

int main() {
    thread philosophers[N];

    for (int i = 0; i < N; i++)
        philosophers[i] = thread(philosopher, i);

    for (int i = 0; i < N; i++)
        philosophers[i].join();

    return 0;
}
