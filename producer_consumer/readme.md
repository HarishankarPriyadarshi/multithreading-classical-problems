# 📦 Producer–Consumer Problem

This project demonstrates the **Producer–Consumer Problem** using **C++ threads, mutex, and condition variables**.

---

## 📝 What is the Producer–Consumer Problem?

- Two or more threads share a **bounded buffer** (a queue of fixed size).  
- **Producer**:
  - Creates data (items) and puts them in the buffer.  
  - Must **wait** if the buffer is **full**.  
- **Consumer**:
  - Takes data (items) from the buffer and processes it.  
  - Must **wait** if the buffer is **empty**.  

👉 The challenge is to **avoid race conditions** and ensure correct **synchronization** between producers and consumers.

---

## ⚙️ How It Works in This Code

1. **Shared Buffer**
   ```cpp
   queue<int> buffer;
   const unsigned int MAX_SIZE = 5;
