# Multiple Thread Execution at Same Time

This program demonstrates how multiple threads can run concurrently in C++ using the `<thread>` library.  
Two worker functions (`worker1` and `worker2`) execute in parallel, each printing output with a delay.  

---

## Code File
- `multi_thread_execution.cpp`

---

## Concepts Used
- **Threads (`std::thread`)** → to create independent flows of execution.  
- **`join()`** → to wait for threads to finish execution before the program exits.  
- **`sleep()`** → to simulate work and visualize interleaved execution.  

---

## Sample Output
[Worker 1] → Step 0 completed ✅
[Worker 2] → Step 0 completed ✅
[Worker 1] → Step 1 completed ✅
[Worker 2] → Step 1 completed ✅
[Worker 1] → Step 2 completed ✅
[Worker 2] → Step 2 completed ✅
[Worker 1] → Step 3 completed ✅
[Worker 2] → Step 3 completed ✅
[Worker 1] → Step 4 completed ✅
[Worker 2] → Step 4 completed ✅
