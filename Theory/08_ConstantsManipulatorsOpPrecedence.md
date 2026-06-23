# Constants, Manipulators, and Operator Precedence in C++

1. **Constants** – Values that stay fixed.
2. **Manipulators** – Tools to make your console output look professional.
3. **Operator Precedence** – Rules that decide the order of calculations.

---

## 1. Constants in C++

### What is a Constant?
A **constant** is like a promise: "This value will never change during the program."

**Real-world example**:  
- The value of **PI (3.14159)** in a circle area calculator.  
- Maximum number of login attempts allowed (e.g., 5).  
- Tax rate of your country (e.g., 18%).

If you accidentally try to change it, the compiler will stop you — this prevents bugs!

### Ways to Create Constants

#### a) Using `const` keyword (Recommended)
```cpp
#include <iostream>

int main() {
    const double PI = 3.14159;        // Constant double
    const int MAX_LOGIN_ATTEMPTS = 5; // Constant int
    const std::string COMPANY_NAME = "TechCorp"; // Constant string

    // PI = 3.14;  // Error! You cannot change a const

    double radius = 5.0;
    double area = PI * radius * radius;

    std::cout << "Area of circle: " << area << std::endl;
    return 0;
}
```

#### b) Using `#define` (Old style — still used sometimes)
```cpp
#define PI 3.14159
#define MAX_USERS 100
```

**Tip**: Prefer `const` or `constexpr` (modern C++) over `#define` because it has better type safety.

#### c) `constexpr` (Modern C++ — Best for compile-time constants)
```cpp
constexpr int DAYS_IN_WEEK = 7;

constexpr double calculateTax(double amount) {
    return amount * 0.18;
}
```

**When to use what?**
- Use `const` for values known at runtime.
- Use `constexpr` when the value can be calculated at compile time (faster).

---

## 2. Manipulators in C++

Manipulators help you **format** your output nicely — like setting width, decimal places, alignment, etc.

You need to include: `#include <iomanip>`

### Common Manipulators

| Manipulator          | What it does                          | Example Use Case                  |
|----------------------|---------------------------------------|-----------------------------------|
| `std::endl`          | New line + flush                      | Clean output                      |
| `std::setw(n)`       | Set width of next output              | Table-like alignment              |
| `std::setprecision(n)` | Set decimal places                   | Money, percentages                |
| `std::fixed`         | Fixed decimal format                  | Currency                          |
| `std::left` / `std::right` | Alignment                        | Reports                           |

### Real-world Example: Simple Invoice Printer

```cpp
#include <iostream>
#include <iomanip>

int main() {
    std::string item = "Wireless Mouse";
    double price = 1299.75;
    int quantity = 2;

    std::cout << std::fixed << std::setprecision(2); // Show 2 decimal places

    std::cout << "=================== INVOICE ===================" << std::endl;
    std::cout << std::left << std::setw(20) << "Item" 
              << std::setw(10) << "Qty" 
              << std::setw(15) << "Price" << std::endl;

    std::cout << std::left << std::setw(20) << item 
              << std::setw(10) << quantity 
              << std::setw(15) << price << std::endl;

    double total = price * quantity;
    std::cout << "\nTotal Amount: Rs " << total << std::endl;

    return 0;
}
```

**Output will look clean and aligned** — perfect for reports or CLI tools.

**Pro Tip**: Always use `std::fixed` and `std::setprecision` when dealing with money or measurements.

---

## 3. Operator Precedence

**Operator Precedence** tells C++ which operation to do first — just like BODMAS rule you learned in school.

### Real-world Example
You are calculating employee bonus:
```cpp
bonus = salary + salary * 0.10 - 1000;
```

What should happen?
1. Multiply salary by 0.10 first (higher precedence).
2. Then add and subtract.

### Common Precedence Order (Highest to Lowest)

| Precedence Level | Operators                              | Example                     |
|------------------|----------------------------------------|-----------------------------|
| Highest          | `()` parentheses                       | `(a + b) * c`              |
|                  | `* / %`                                | Multiplication, division   |
|                  | `+ -`                                  | Addition, subtraction      |
|                  | `< <= > >=`                            | Comparisons                |
|                  | `== !=`                                | Equality                   |
| Lowest           | `=` (assignment)                       | `x = 5`                    |

### Dangerous Example Without Parentheses

```cpp
int a = 10, b = 20, c = 30;

int result1 = a + b * c;        // 10 + (20*30) = 610
int result2 = (a + b) * c;      // (10+20)*30 = 900

std::cout << result1 << " vs " << result2 << std::endl;
```

**Always use parentheses** when in doubt. It makes code easier to read and prevents bugs.

### Another Common Mistake
```cpp
if (score = 100) {     // BUG! This assigns 100, then checks if true
    std::cout << "You won!";
}
```

Should be:
```cpp
if (score == 100) {    // Comparison
    std::cout << "You won!";
}
```

---

## Complete Practice Program

```cpp
#include <iostream>
#include <iomanip>

int main() {
    // Constants
    const double TAX_RATE = 0.18;
    const int MAX_ITEMS = 5;

    double price = 499.99;
    int quantity = 3;

    // Calculations with proper precedence
    double subtotal = price * quantity;
    double tax = subtotal * TAX_RATE;
    double total = subtotal + tax;

    // Formatted output using manipulators
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "=============== SHOPPING BILL ===============" << std::endl;
    std::cout << std::left << std::setw(15) << "Item Price" << ": Rs " << price << std::endl;
    std::cout << std::left << std::setw(15) << "Quantity" << ": " << quantity << std::endl;
    std::cout << std::left << std::setw(15) << "Subtotal" << ": Rs " << subtotal << std::endl;
    std::cout << std::left << std::setw(15) << "Tax (" << (TAX_RATE*100) << "%)" << ": Rs " << tax << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(15) << "TOTAL" << ": Rs " << total << std::endl;

    return 0;
}
```

---

## Summary & Tips for Beginners

- **Constants** (`const`) → Protect important values from accidental changes.
- **Manipulators** (`<iomanip>`) → Make your programs look professional.
- **Operator Precedence** → Always use parentheses `()` to make your intention clear.

**Practice Ideas**:
1. Create a BMI calculator using constants for conversion factors.
2. Build a simple salary slip generator with formatted output.
3. Try different operator combinations and see what changes with parentheses.

```

