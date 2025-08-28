from threading import Thread, Semaphore
import time

# Semaphore allows only 3 threads at a time
sem = Semaphore(3)

def task(name):
    sem.acquire()  # lock semaphore
    for i in range(5):
        print(f"{name} working")
        time.sleep(1)
    sem.release()  # release semaphore

if __name__ == "__main__":
    t1 = Thread(target=task, args=("Thread-1",))
    t2 = Thread(target=task, args=("Thread-2",))
    t3 = Thread(target=task, args=("Thread-3",))
    t4 = Thread(target=task, args=("Thread-4",))
    t5 = Thread(target=task, args=("Thread-5",))

    t1.start()
    t2.start()
    t3.start()
    t4.start()
    t5.start()

    t1.join()
    t2.join()
    t3.join()
    t4.join()
    t5.join()

