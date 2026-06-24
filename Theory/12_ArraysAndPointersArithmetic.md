# Arrays and Pointers Arithmetic in C++ - A Beginner's Guide

## 1. What is an Array? (Real-world Analogy)

Think of an **array** as a row of fixed-size lockers in a company warehouse. Each locker holds one item (like an employee ID), and lockers are numbered from 0.

```cpp
#include <iostream>

int main() {
    // Real-world: Store 5 employee IDs
    int employeeIds[5] = {101, 102, 103, 104, 105};
    
    // Access like lockers
    std::cout << "Employee 0: " << employeeIds[0] << std::endl;  // 101
    std::cout << "Employee 3: " << employeeIds[3] << std::endl;  // 104
    
    // Modify
    employeeIds[2] = 999;  // Update ID of third employee
    std::cout << "Updated Employee 2: " << employeeIds[2] << std::endl;
    
    return 0;
}
```

**Key Rules:**
- Size is fixed after declaration (`int arr[5]`).
- Indices start at **0**.
- Memory is **contiguous** (lockers are next to each other).

## 2. Introduction to Pointers

A **pointer** is a variable that stores the **memory address** of another variable.

```cpp
int salary = 50000;
int* ptr = &salary;  // & = address-of operator

std::cout << "Salary value: " << salary << std::endl;
std::cout << "Pointer address: " << ptr << std::endl;
std::cout << "Value via pointer: " << *ptr << std::endl;  // * = dereference
```

**Real-world:** Like a sticky note with the locker number written on it. You don't carry the item, you carry the location.

## 3. Pointer Arithmetic - The Core Concept

Pointer arithmetic is powerful because arrays and pointers are closely related in C++.

### Basic Operations
- `ptr + 1` → moves to the **next element** (adds `sizeof(type)` bytes)
- `ptr + n` → jumps n elements ahead
- `ptr++` → increment pointer
- `*(ptr + n)` → access nth element

```cpp
int prices[4] = {29, 49, 19, 99};  // Product prices in dollars
int* p = prices;  // Array name decays to pointer to first element

std::cout << "First price: " << *p << std::endl;           // 29
std::cout << "Second price: " << *(p + 1) << std::endl;    // 49
std::cout << "Third price: " << p[2] << std::endl;         // 19 (same as *(p+2))

p = p + 2;  // Move pointer forward
std::cout << "Price after jump: " << *p << std::endl;      // 19
```

**Why does this work?**  
The compiler knows the type (`int` = 4 bytes usually). `p + 1` automatically adds 4 bytes.

## 4. Arrays are Pointers in Disguise

```cpp
int numbers[5] = {10, 20, 30, 40, 50};

std::cout << numbers << std::endl;      // Prints address of first element
std::cout << &numbers[0] << std::endl;  // Same address
std::cout << *(numbers + 3) << std::endl; // 40
```

**Real-world Example: Processing a List of Transactions**

```cpp
#include <iostream>

void printTransactions(double* trans, int size) {
    for(int i = 0; i < size; i++) {
        std::cout << "Transaction " << i << ": $" << *(trans + i) << std::endl;
    }
}

int main() {
    double transactions[6] = {125.50, 89.99, 250.00, 45.75, 300.0, 12.99};
    
    std::cout << "All transactions:\n";
    printTransactions(transactions, 6);
    
    // Using pointer arithmetic to find total
    double total = 0;
    double* ptr = transactions;
    for(int i = 0; i < 6; i++) {
        total += *(ptr + i);
    }
    std::cout << "\nTotal revenue: $" << total << std::endl;
    
    return 0;
}
```

## 5. Common Pointer Arithmetic Patterns

### Looping with Pointers (Efficient)

```cpp
int scores[5] = {85, 92, 78, 95, 88};
int* end = scores + 5;  // One past the last element

for(int* p = scores; p < end; p++) {
    std::cout << *p << " ";
}
std::cout << std::endl;
```

### Finding Maximum Value

```cpp
int findMax(int* arr, int size) {
    int max = *arr;
    for(int i = 1; i < size; i++) {
        if(*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}

// Usage
int temperatures[7] = {23, 25, 19, 28, 22, 24, 26};
std::cout << "Hottest day: " << findMax(temperatures, 7) << "°C\n";
```

## 6. Pointers vs Array Indexing - Performance

Both are equivalent in performance, but pointer arithmetic can be slightly faster in tight loops (modern compilers optimize both well).

**Array style (more readable):**
```cpp
arr[i]
```

**Pointer style:**
```cpp
*(ptr + i)
```

**Recommendation:** Use array notation for clarity unless you need pointer manipulation.

## 7. Common Pitfalls (Learn from Real Mistakes)

1. **Going out of bounds**
   ```cpp
   int arr[3] = {1,2,3};
   std::cout << arr[5];  // Undefined behavior! (crashes or garbage)
   ```

2. **Forgetting array size**
   ```cpp
   void process(int* arr) {
       // Bad: How do I know when to stop?
   }
   // Solution: Always pass size or use std::vector (later topic)
   ```

3. **Modifying const data**
   ```cpp
   const int days[7] = {1,2,3,4,5,6,7};
   int* p = const_cast<int*>(days);  // Dangerous - avoid
   ```

4. **Uninitialized pointers**
   ```cpp
   int* badPtr;     // Points to random memory
   *badPtr = 10;    // Crash!
   ```

## 8. Hands-on Exercise

Create a small program for **inventory management**:

```cpp
// TODO: Complete this
int inventory[10] = {5, 0, 12, 3, 8, 1, 0, 15, 4, 7};

// 1. Print items with stock < 5 using pointer arithmetic
// 2. Increase stock of index 2 by 10 using pointer
// 3. Calculate total items in stock
```

**Solution sketch** (try first!):
```cpp
int* ptr = inventory;
for(int i = 0; i < 10; i++) {
    if(*(ptr + i) < 5) {
        std::cout << "Low stock at " << i << ": " << *(ptr + i) << std::endl;
    }
}
*(ptr + 2) += 10;
```