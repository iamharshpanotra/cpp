# C++ Header Files and Operators - Beginner Friendly Guide

---

## 1. What are Header Files? (The "Import" Concept)

In C++, **header files** are like toolkits or libraries that bring in pre-written code so you don't have to write everything from scratch.

- They usually end with `.h` or `.hpp`
- You include them at the top of your `.cpp` file using `#include`
- They contain declarations (like function signatures, class definitions) that your program can use.

### Why do we need them?
Imagine building a simple banking app. You need:
- Input/output → already using `<iostream>`
- Math calculations (like interest) → use `<cmath>`
- Working with strings (names, account numbers) → `<string>`

Without headers, you'd have to implement everything yourself — which is impossible for beginners!

### Common Header Files (Real-world usage)

```cpp
#include <iostream>     // For cout, cin - basic input/output
#include <string>       // For std::string - handling text like user names
#include <cmath>        // For math functions: sqrt, pow, round
#include <vector>       // For dynamic lists (like list of transactions)
#include <fstream>      // For reading/writing files (save user data)
#include <iomanip>      // For formatting output (like money with 2 decimals)
```

**Example: A simple Interest Calculator**

```cpp
#include <iostream>
#include <cmath>    // For pow() function
#include <iomanip>  // For setprecision

int main() {
    double principal = 1000.0;
    double rate = 0.05;     // 5% interest
    int years = 3;

    // Compound interest formula: P * (1 + r)^t
    double amount = principal * pow(1 + rate, years);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Final Amount: $" << amount << std::endl;

    return 0;
}
```

**Real-world scenario**: You're building a small finance tool for your team. This calculates how much money grows over time.

---

## 2. Using Your Own Header Files

You can create your own headers for reusable code.

**Step-by-step example:**

1. Create `utils.h`:
```cpp
// utils.h
#ifndef UTILS_H     // Header guard - prevents including twice
#define UTILS_H

double calculateTax(double income);

#endif
```

2. Create `utils.cpp`:
```cpp
#include "utils.h"

double calculateTax(double income) {
    if (income > 50000) return income * 0.25;
    return income * 0.15;
}
```

3. Use in `main.cpp`:
```cpp
#include <iostream>
#include "utils.h"   // Your own header!

int main() {
    double salary = 60000;
    std::cout << "Tax: $" << calculateTax(salary) << std::endl;
    return 0;
}
```

**Why header guards (`#ifndef`)?** Prevents errors when the same header is included multiple times.

---

## 3. Operators in C++ (The Building Blocks)

Operators are symbols that perform operations on variables/values.

### Arithmetic Operators (+, -, *, /, %)
```cpp
int a = 10;
int b = 3;

std::cout << a + b << "\n";  // 13 - Addition
std::cout << a - b << "\n";  // 7  - Subtraction  
std::cout << a * b << "\n";  // 30 - Multiplication
std::cout << a / b << "\n";  // 3  - Division (integer)
std::cout << a % b << "\n";  // 1  - Modulo (remainder)
```

**Real-world**: Calculating total bill + tax in a POS system.

### Assignment Operators
```cpp
int score = 100;
score += 50;   // score = score + 50 → 150
score -= 20;   // 130
score *= 2;    // 260
score /= 2;    // 130
```

### Comparison Operators (Very useful in conditions)
- `==` equal to
- `!=` not equal
- `>` greater than
- `<` less than
- `>=` greater or equal
- `<=` less or equal

**Example - Login System:**
```cpp
std::string password;
std::cout << "Enter password: ";
std::cin >> password;

if (password == "admin123") {
    std::cout << "Access granted!\n";
} else {
    std::cout << "Access denied!\n";
}
```

### Logical Operators (&&, ||, !)
```cpp
bool isLoggedIn = true;
bool hasPermission = false;

if (isLoggedIn && hasPermission) {
    std::cout << "You can edit the document.\n";
} else if (isLoggedIn || hasPermission) {
    std::cout << "Limited access.\n";
}
```

**Real-world**: Checking user access in a simple CRM tool.

### Increment / Decrement (`++`, `--`)
```cpp
int counter = 0;
counter++;        // 1
++counter;        // 2 (pre-increment)

for(int i = 0; i < 5; i++) {  // Counting loop
    std::cout << i << " ";
}
```

---

## 4. Putting It All Together: Mini Project

Here's a complete example combining headers, operators, and previous knowledge:

**main.cpp**
```cpp
#include <iostream>
#include <string>
#include <iomanip>
#include "calculator.h"   // Our custom header

int main() {
    double num1, num2;
    char op;

    std::cout << "=== Simple Calculator ===\n";
    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter operator (+ - * /): ";
    std::cin >> op;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    double result = calculate(num1, num2, op);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Result: " << num1 << " " << op << " " << num2 
              << " = " << result << std::endl;

    return 0;
}
```

**calculator.h** and **calculator.cpp** would contain the `calculate` function using switch and arithmetic operators.

---

## Common Mistakes Beginners Make

1. Forgetting `#include <string>` when using `std::string`
2. Using `=` instead of `==` in conditions (assignment vs comparison)
3. Integer division losing decimal part: `5/2 = 2` (not 2.5)
4. Not using header guards in custom headers
5. Mixing `cin >>` with `getline()` without handling leftover newline

**Tip**: Always compile with warnings: `g++ -Wall -Wextra yourfile.cpp`

---