# 🍽️ Dining Philosophers Problem

## 🔹 Problem Statement
- **5 philosophers** sit around a round table.  
- Each has a plate of food and a fork on their **left**.  
- To **eat**, a philosopher needs **two forks** (left + right).  
- Philosophers alternate between **thinking** and **eating**.  

### ⚠️ The Problem
- If each philosopher picks up their **left fork at the same time** → no one can pick up the right fork → **deadlock** (all waiting forever).  

### 🎯 Goals
- Avoid **deadlock**.  
- Avoid **starvation** (every philosopher eventually eats).  
- Allow **maximum parallelism** (multiple philosophers can eat if forks are free).  

---

## 🔹 Core Issues
- **Deadlock** → All philosophers pick the same fork, no progress.  
- **Starvation** → One philosopher may never get both forks.  
- **Concurrency** → More than one philosopher can eat as long as forks don’t overlap.  

---

## 🔹 Classical Solution Strategies
1. **Asymmetric solution (used in this code)**  
   - Odd philosophers pick **right fork first**, then left.  
   - Even philosophers pick **left fork first**, then right.  
   - This breaks the circular waiting condition → avoids deadlock.  

2. **Limit philosophers (resource hierarchy)**  
   - Allow only 4 philosophers to sit down at once.  
   - Guarantees one philosopher can always eat.  

3. **Use a waiter (central authority)**  
   - A mutex "waiter" grants permission before forks are picked.  
   - Prevents deadlock & starvation.  

---
