# Call by Value and Call by Reference in C++

## What is Parameter Passing?

When you call a function in C++ and pass a variable to it, the language decides **how** to send that data to the function.

There are two main ways:
1. **Call by Value** (default in C++)
2. **Call by Reference**

These decide whether the function works on a **copy** of your data or the **original** data.

---

## 1. Call by Value

### Simple Explanation
- The function receives a **copy** of the variable.
- Any changes made inside the function **do not affect** the original variable outside the function.
- It's like giving someone a photocopy of your document — they can write on the copy, but your original remains unchanged.

### Real-World Example
Imagine you have a bank account with ₹5000 balance. You tell your friend the balance so they can calculate something. Your friend adds ₹1000 in their calculation notebook. Your actual bank balance should still be ₹5000, right? That's Call by Value.

### Code Example
```cpp
#include <iostream>

void callByValue(int num) {
    num = num + 10;  // This only changes the copy
    std::cout << "Inside function (Call by Value): num = " << num << std::endl;
}

int main() {
    int original = 5;
    
    std::cout << "Before function: original = " << original << std::endl;
    
    callByValue(original);
    
    std::cout << "After function: original = " << original << std::endl;  // Still 5
    
    return 0;
}
```

**Expected Output:**
```
Before function: original = 5
Inside function (Call by Value): num = 15
After function: original = 5
```

**Why it happens:** `num` inside the function is a separate copy in memory.

---

## 2. Call by Reference

### Simple Explanation
- The function receives the **memory address** of the original variable (using `&`).
- Any changes made inside the function **directly modify** the original variable.
- It's like giving someone the actual document with permission to edit it.

### Real-World Example
You give your friend your actual bank passbook (not a copy) and say "add ₹1000 to my balance". Now your real balance becomes ₹6000. That's Call by Reference — changes affect the original.

### Code Example
```cpp
#include <iostream>

void callByReference(int& num) {  // Notice the & here
    num = num + 10;  // This changes the original!
    std::cout << "Inside function (Call by Reference): num = " << num << std::endl;
}

int main() {
    int original = 5;
    
    std::cout << "Before function: original = " << original << std::endl;
    
    callByReference(original);
    
    std::cout << "After function: original = " << original << std::endl;  // Now 15
    
    return 0;
}
```

**Expected Output:**
```
Before function: original = 5
Inside function (Call by Reference): num = 15
After function: original = 15
```

**Key Point:** The `&` symbol makes `num` a **reference** to the original variable.

---

## Side-by-Side Comparison

| Feature                  | Call by Value                  | Call by Reference                  |
|-------------------------|--------------------------------|------------------------------------|
| Syntax                  | `void func(int x)`            | `void func(int& x)`               |
| Memory used             | Creates a copy                 | Uses original variable            |
| Changes affect original?| No                             | Yes                               |
| Performance             | Slower for large data (copy)   | Faster (no copy)                  |
| Safety                  | Safer (original protected)     | Riskier (can accidentally modify) |
| Use case                | When you don't want changes    | When you need to modify original  |

---

## When to Use Which?

**Use Call by Value:**
- When you want to **protect** the original data.
- For small data types like `int`, `float`, `char`.
- Example: A function that calculates tax on salary but shouldn't change the actual salary.

**Use Call by Reference:**
- When you **need to modify** the original variable.
- For large objects (like `std::vector`, `std::string`) to avoid expensive copying.
- When returning multiple values from a function.
- Example: A function that swaps two numbers, or updates a user's profile.

**Pro Tip for Beginners:**  
For big data structures, always prefer `const` reference if you don't need to modify:
```cpp
void printVector(const std::vector<int>& vec) {  // Efficient + safe
    // cannot modify vec
}
---