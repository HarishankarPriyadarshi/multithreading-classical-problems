#include <iostream>
#include <thread>
#include <unistd.h>  // for sleep()


int count=0;   // CRITICAL SECTION
void worker1() {
    for (int i = 0; i < 500000; i++) {
        count++;
        
    }
}


void worker2() {
    for (int i = 0; i < 500000; i++) {
        count++;
        
    }
}

int main() {
    std::thread t1(worker1);
    std::thread t2(worker2);

    t1.join();  // wait for thread 1
    t2.join();  // wait for thread 2
     std::cout << "final " << count<< "\n";

    return 0;
}

