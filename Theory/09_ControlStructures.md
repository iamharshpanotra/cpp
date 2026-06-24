## 1. Why Do We Need Control Structures?

Imagine you're building a simple login system for a mobile app:
- If the user enters the correct password → Show "Welcome!"
- Else → Show "Try again" or lock the account.

Without control structures, every user would get the same message. Boring and useless!

## 2. The `if` Statement

The simplest control structure. It checks a condition and runs code only if it's **true**.

### Basic Syntax:
```cpp
if (condition) {
    // Code to run if condition is true
}
```

### Real-World Example:
Let's say you're writing a program to check if a student passed an exam.

```cpp
#include <iostream>

int main() {
    int marks = 75;  // Imagine this comes from user input

    if (marks >= 40) {
        std::cout << "Congratulations! You passed the exam." << std::endl;
    }

    return 0;
}
```

**Explanation**
- `marks >= 40` is the condition (like asking "Are marks 40 or more?").
- If yes (true), the message inside `{}` runs.
- If no, the program skips it and continues.

**Pro Tip:** Always use curly braces `{}` even for single lines. It prevents bugs when you add more code later.

## 3. `if-else` Statement

What if you want to do something when the condition is **false**?

### Syntax:
```cpp
if (condition) {
    // Code if true
} else {
    // Code if false
}
```

### Real-World Example: Bank Withdrawal

```cpp
#include <iostream>

int main() {
    double balance = 5000.0;
    double withdraw = 6000.0;

    if (withdraw <= balance) {
        std::cout << "Withdrawal successful! New balance: " << (balance - withdraw) << std::endl;
    } else {
        std::cout << "Sorry, insufficient funds!" << std::endl;
    }

    return 0;
}
```

This is like an ATM machine deciding whether to give money or show an error.

## 4. `else if` Ladder (Multiple Conditions)

For more than two choices:

```cpp
if (condition1) {
    // ...
} else if (condition2) {
    // ...
} else if (condition3) {
    // ...
} else {
    // None of the above
}
```

### Example: Grading System

```cpp
#include <iostream>

int main() {
    int score = 85;

    if (score >= 90) {
        std::cout << "Grade: A - Excellent!" << std::endl;
    } else if (score >= 80) {
        std::cout << "Grade: B - Good job!" << std::endl;
    } else if (score >= 70) {
        std::cout << "Grade: C - Keep practicing." << std::endl;
    } else {
        std::cout << "Grade: F - Let's work together." << std::endl;
    }

    return 0;
}
```

**Real-life analogy:** Like a doctor diagnosing based on symptoms (fever high? → serious; medium? → normal flu; low? → check more).

## 5. Nested `if` Statements

Putting an `if` inside another `if`.

### Example: Movie Ticket Booking

```cpp
#include <iostream>

int main() {
    int age = 25;
    bool isMember = true;

    if (age >= 18) {  // First check: Adult?
        if (isMember) {
            std::cout << "Discount applied! Ticket price: $8" << std::endl;
        } else {
            std::cout << "Regular ticket: $12" << std::endl;
        }
    } else {
        std::cout << "Sorry, kids under 18 not allowed." << std::endl;
    }

    return 0;
}
```

**Caution:** Too many nested ifs can make code hard to read.

## 6. The `switch` Statement

Use `switch` when you have **one variable** and want to check it against many fixed values (like menu choices).

### Syntax:
```cpp
switch (expression) {
    case value1:
        // code
        break;
    case value2:
        // code
        break;
    default:
        // if no match
}
```

**Important:** 
- `break;` is crucial! Without it, the program "falls through" to the next case (sometimes useful, but usually a bug).
- Works best with `int`, `char`, or `enum` (not floats or strings in older C++).

### Real-World Example: Simple Calculator Menu

```cpp
#include <iostream>

int main() {
    char operation;
    double num1 = 10, num2 = 5;

    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> operation;

    switch (operation) {
        case '+':
            std::cout << num1 << " + " << num2 << " = " << (num1 + num2) << std::endl;
            break;
        case '-':
            std::cout << num1 << " - " << num2 << " = " << (num1 - num2) << std::endl;
            break;
        case '*':
            std::cout << num1 << " * " << num2 << " = " << (num1 * num2) << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                std::cout << num1 << " / " << num2 << " = " << (num1 / num2) << std::endl;
            } else {
                std::cout << "Cannot divide by zero!" << std::endl;
            }
            break;
        default:
            std::cout << "Invalid operator!" << std::endl;
    }

    return 0;
}
```

**When to use switch?**
- Day of the week
- Menu options in a console game
- HTTP status codes

## 7. If-Else vs Switch-Case

| Feature              | If-Else                          | Switch-Case                     |
|----------------------|----------------------------------|---------------------------------|
| Conditions           | Any (>, <, ==, &&, etc.)        | Equality only (==)             |
| Number of choices    | Any number                       | Best for 3+ fixed values       |
| Readability          | Good for ranges/complex logic   | Cleaner for single variable    |
| Performance          | Similar                         | Slightly faster in some cases  |

**Rule of thumb:** 
- Use `if-else` for ranges (age < 18, 18-60, >60)
- Use `switch` for exact matches (menu item 1, 2, 3)

## 8. Common Mistakes

1. Forgetting `==` vs `=` in conditions (`if (x = 5)` assigns instead of compares).
2. Missing `break` in switch → unexpected behavior.
3. Too deep nesting → hard to maintain (consider functions or switch).
4. Not handling all cases in else/default.
```