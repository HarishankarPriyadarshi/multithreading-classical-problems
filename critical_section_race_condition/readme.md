# ⚠️ Critical Section and Race Condition

This program demonstrates the **race condition problem** in multithreading when multiple threads access and modify a **shared resource** without proper synchronization.

---

## 📄 Code Overview

- We define a shared variable:
  ```cpp
  int count = 0;   // CRITICAL SECTION
