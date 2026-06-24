# Pointers in C++

## Introduction

A pointer is a variable that **stores the memory address** of another variable.

### Real-World Example
Imagine your house address is 123 Main Street. 
- The house itself has furniture (data).
- The address "123 Main Street" is like a pointer - it tells you where the house is.

In code:
```cpp
int age = 25;  // A normal variable storing value 25
```

`age` lives at some memory address, say `0x7fff5fbff8ac`.

A pointer to `age` would store that address.

## 2. Declaring a Pointer

To declare a pointer, use `*` after the data type.

```cpp
int* ptr;  // Pointer to an integer
double* dptr; // Pointer to double
```

The `*` means "this variable will hold an address of an int".

**Important**: Initialize pointers! Uninitialized pointers point to garbage.

```cpp
int value = 42;
int* ptr = &value;  // & is address-of operator
```

`&value` gives the address of `value`.

## 3. Accessing Value with Pointer (Dereferencing)

Use `*ptr` to get the value at the address stored in `ptr`.

```cpp
#include <iostream>

int main() {
    int value = 42;
    int* ptr = &value;
    
    std::cout << "Value: " << value << std::endl;
    std::cout << "Address: " << ptr << std::endl;
    std::cout << "Value via pointer: " << *ptr << std::endl;
    
    return 0;
}
```

**Output**:
```
Value: 42
Address: 0x7fff5fbff8ac (example)
Value via pointer: 42
```

Real-world: This is like using the address to open the door and see inside the room.

## 4. Modifying Value Using Pointer

You can change the original variable through the pointer.

```cpp
*ptr = 100;  // Changes value to 100
```

**Example**:
```cpp
int main() {
    int score = 50;
    int* ptr = &score;
    *ptr = 95;  // Update score using pointer
    
    std::cout << "Updated score: " << score << std::endl;  // 95
}
```

**Analogy**: You have the address of your friend's house. You go there and rearrange furniture (change data) without your friend knowing directly.

## 5. Pointers and Arrays

Arrays and pointers are closely related in C++.

The name of an array is a pointer to its first element.

```cpp
int numbers[5] = {10, 20, 30, 40, 50};
int* ptr = numbers;  // No & needed for array name

std::cout << *ptr << std::endl;     // 10
std::cout << *(ptr + 1) << std::endl; // 20
```

**Pointer Arithmetic**:
- `ptr + 1` moves to next integer (adds size of int bytes).

This is very useful for looping through arrays efficiently.

## 6. Dynamic Memory Allocation (new and delete)

Pointers shine with dynamic memory - allocating at runtime.

```cpp
int* dynamicPtr = new int;     // Allocate memory for one int
*dynamicPtr = 999;

std::cout << *dynamicPtr << std::endl;

delete dynamicPtr;  // Free memory - very important!
dynamicPtr = nullptr;  // Good practice
```

For arrays:
```cpp
int* arr = new int[10];  // Array of 10 ints

for(int i = 0; i < 10; i++) {
    arr[i] = i * 10;
}

delete[] arr;  // Note the [] for arrays
```

**Real-world use**: Video game loading levels dynamically, database results of unknown size, or building a flexible list.

## 7. Null Pointers

A null pointer points to nothing.

```cpp
int* nullPtr = nullptr;  // Modern C++ way

if(nullPtr == nullptr) {
    std::cout << "Safe - points to nothing" << std::endl;
}
```

Always check before dereferencing!

## 8. Pointers to Pointers (Double Pointers)

```cpp
int x = 10;
int* p1 = &x;
int** p2 = &p1;  // Pointer to pointer
```

Used in advanced cases like dynamic 2D arrays or function parameters.

## 9. Common Mistakes (Avoid These!)

1. **Dangling Pointers**: Using pointer after memory is deleted.
   ```cpp
   int* bad = new int(5);
   delete bad;
   // *bad = 10; // CRASH! Memory gone
   ```

2. **Memory Leaks**: Forgetting `delete`.
3. **Uninitialized Pointers**: `int* p;` then `*p = 5;` → Crash.
4. **Wrong delete**: `delete` vs `delete[]`.

**Best Practice**: Always initialize, check null, use `nullptr`, free memory.

## 10. Real-World Example: Simple Dynamic List

Let's build a tiny dynamic array manager.

```cpp
#include <iostream>

class SimpleList {
private:
    int* data;
    int size;
public:
    SimpleList(int s) {
        size = s;
        data = new int[size];
        for(int i=0; i<size; i++) data[i] = 0;
    }
    
    ~SimpleList() {
        delete[] data;
    }
    
    void set(int index, int val) {
        if(index >= 0 && index < size) {
            data[index] = val;
        }
    }
    
    int get(int index) {
        if(index >= 0 && index < size) {
            return data[index];
        }
        return -1;
    }
};

int main() {
    SimpleList myList(5);
    myList.set(2, 777);
    std::cout << "Value at 2: " << myList.get(2) << std::endl;
    return 0;
}
```

This uses pointers internally for flexible data storage - common in real apps.

---