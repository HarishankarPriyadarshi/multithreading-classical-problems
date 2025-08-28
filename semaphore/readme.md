# 🚦 Semaphore Example in Python

This program demonstrates how to use **Semaphore** for controlling access to shared resources when multiple threads are running.

---

## 📄 Code Overview

- We create a `Semaphore(3)` which allows only **3 threads** to run concurrently.
- Each thread:
  - Acquires the semaphore (`sem.acquire()`)
  - Executes its task (prints 5 times with a delay)
  - Releases the semaphore (`sem.release()`)

```python
sem = Semaphore(3)
