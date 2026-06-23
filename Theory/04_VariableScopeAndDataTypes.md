# Variable Scopes and Data Types in C++ - A Beginner's Guide

## 1. Data Types in More Detail

Data types tell the compiler **how much memory** to reserve and **what operations** are allowed. Choosing the right type is like choosing the right container for groceries — too small and things spill, too big and you waste space.

### Basic (Primitive) Data Types

| Data Type     | What it Stores                  | Example (Library App)                  | Size     | Range (approx)                  |
|---------------|---------------------------------|----------------------------------------|----------|---------------------------------|
| `int`         | Whole numbers                   | `bookId = 101`                         | 4 bytes  | -2 billion to +2 billion       |
| `short`       | Smaller whole numbers           | `shelfNumber = 23`                     | 2 bytes  | -32,768 to 32,767              |
| `long` / `long long` | Bigger whole numbers     | `totalBooksInLibrary = 1'234'567`      | 8 bytes  | Very large numbers             |
| `float`       | Decimal numbers (less precise)  | `fineAmount = 2.5`                     | 4 bytes  | ~7 decimal digits              |
| `double`      | Decimal numbers (more precise)  | `bookPrice = 19.99`                    | 8 bytes  | ~15 decimal digits             |
| `char`        | Single character                | `condition = 'G'` (Good)               | 1 byte   | ASCII characters               |
| `bool`        | True or False                   | `isCheckedOut = true`                  | 1 byte   | `true` / `false`               |

### String and Other Useful Types

```cpp
#include <string>     // Must include this for std::string

std::string bookTitle = "The Great Gatsby";   // Text data
```

**Real-World Tip**: 
- Use `int` for counts and IDs.
- Use `double` for money, measurements, or any calculations involving decimals (avoid `float` unless memory is critical).
- Use `bool` for flags (e.g., `isMember`, `isOverdue`).

### Modifiers (Making Types Bigger/Smaller)

```cpp
unsigned int positiveOnly = 100;     // Only positive numbers (0 to 4 billion)
const double TAX_RATE = 0.18;        // Value that cannot change
```

**Example in Library Context**:
```cpp
unsigned int totalCopies = 50;       // Can't be negative
const double LATE_FEE_PER_DAY = 1.50;
```

## 2. Variable Scopes - Where Can I Use This Variable?

**Scope** defines the **lifetime** and **visibility** of a variable — basically, "where can this variable be seen and used?"

Think of scopes like different rooms in a library building:
- **Global**: Available everywhere (main hall)
- **Local**: Only in one function (a specific room)
- **Block**: Only inside `{ }` (a small closet)

### 1. Local Scope (Most Common)

Variables declared **inside a function** or **inside `{ }`**.

```cpp
int main() {
    int bookId = 101;           // Local to main()
    
    if (bookId > 0) {
        std::string message = "Book found!";  // Only available inside this if block
        std::cout << message;
    }
    
    // std::cout << message;  // ERROR! message doesn't exist here
    return 0;
}
```

### 2. Global Scope

Declared **outside any function**. Available to all functions in the file.

```cpp
#include <iostream>
#include <string>

int totalBooksInLibrary = 1000;     // Global variable

void displayLibraryStats() {
    std::cout << "Total books: " << totalBooksInLibrary << std::endl;
}

int main() {
    totalBooksInLibrary = 950;      // Can modify global
    displayLibraryStats();
    return 0;
}
```

**Warning**: Globals can be modified from anywhere → makes debugging hard. Use them sparingly (like shared configuration).

### 3. Block Scope

Inside any curly braces `{}` — loops, if statements, etc.

### Real-World Library Example Combining Everything

```cpp
#include <iostream>
#include <string>

const double LATE_FEE_RATE = 1.50;   // Global constant - good use of global

// Function to calculate fine
double calculateLateFee(int daysLate) {   // 'daysLate' is parameter (local scope)
    double fine = daysLate * LATE_FEE_RATE;  // local variable
    return fine;
}

int main() {
    std::string bookTitle = "Dune";           // local
    int daysOverdue = 5;                      // local
    
    double fineAmount = calculateLateFee(daysOverdue);
    
    std::cout << "Book: " << bookTitle << std::endl;
    std::cout << "Days overdue: " << daysOverdue << std::endl;
    std::cout << "Fine: $" << fineAmount << std::endl;
    
    return 0;
}
```

## Common Mistakes & Best Practices

1. **Shadowing**: Don't use same name in inner and outer scope — confusing!
   ```cpp
   int x = 10;
   if (true) {
       int x = 20;   // This shadows the outer x
   }
   ```

2. **Uninitialized variables** → garbage values! Always initialize:
   ```cpp
   int count = 0;        // Good
   int count;            // Bad - contains random value
   ```

3. **Use `const`** whenever possible — tells others "this shouldn't change".

4. **Choose appropriate scope**:
   - Local for temporary calculations
   - Parameters for function inputs
   - Global constants only when truly shared

## Practice Exercise

Extend your library program:

1. Create a function `checkoutBook()` that takes `bookId` and returns whether checkout was successful.
2. Use different data types: `int`, `double`, `bool`, `std::string`.
3. Declare some variables at global, function, and block level.
4. Add comments explaining the scope of each variable.

```