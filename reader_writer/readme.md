# 📖 Reader–Writer Problem

## 🔹 Problem Statement
The **Reader–Writer Problem** is a classic synchronization problem in operating systems and multithreading.

- A **shared resource** (e.g., database, file, memory) is accessed by multiple threads.  
- **Readers** can access the resource simultaneously, since they do not modify data.  
- **Writers** require **exclusive access** to avoid race conditions and inconsistent data.  

**Rule:**  
- Multiple readers ✅ (allowed at the same time).  
- Writers ❌ (only one writer, and no readers during writing).  

---

## ⚙️ Solution Explanation
This implementation uses:
- **`mutex`** – ensures safe access to shared variables.  
- **`condition_variable`** – allows threads to wait until conditions are met.  

### Key Points
1. **Shared State**
   ```cpp
   int readerCount = 0;       // Active readers
   bool writerPresent = false; // Writer flag
