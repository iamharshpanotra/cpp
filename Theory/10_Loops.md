# Loops in C++: for, while, and do-while

## 1. The `for` Loop
The `for` loop is best when you know **exactly how many times** you want to repeat something. It has three parts in one line:
- **Initialization**: Set up a counter (runs once at start).
- **Condition**: Check if we should continue.
- **Increment/Decrement**: Update the counter after each run.

### Syntax
```cpp
for (initialization; condition; increment) {
    // code to repeat
}
```

### Real-World Example: Printing Numbers Like Counting Inventory
Imagine you're a shopkeeper counting stock from item 1 to 10.

```cpp
#include <iostream>

int main() {
    for (int i = 1; i <= 10; i++) {  // i starts at 1, runs while i<=10, i increases by 1 each time
        std::cout << "Item number: " << i << std::endl;
    }
    return 0;
}
```

**Output:**
```
Item number: 1
Item number: 2
...
Item number: 10
```

**How it works step-by-step:**
1. `int i = 1;` → Counter starts.
2. Check `i <= 10` → True, run code.
3. After code, `i++` → i becomes 2.
4. Repeat until condition false.

**Common Use:** Processing arrays or lists where you know the size. Example: Looping through 100 customer orders.

**Tip for Beginners:** The variable `i` (or `counter`) is local to the loop. Don't use it outside unless declared before.

## 2. The `while` Loop
The `while` loop repeats **as long as a condition is true**. Use it when you don't know the exact number of repetitions in advance, but you have a stopping condition.

### Syntax
```cpp
while (condition) {
    // code to repeat
}
```

### Real-World Example: Processing User Input Like ATM Withdrawals
Imagine an ATM that keeps asking for withdrawal amount until the balance is too low.

```cpp
#include <iostream>

int main() {
    double balance = 500.0;
    double amount;

    std::cout << "Current balance: $" << balance << std::endl;

    while (balance > 0) {  // Keep going while money left
        std::cout << "Enter withdrawal amount (0 to stop): ";
        std::cin >> amount;

        if (amount <= 0) break;  // Extra safety

        if (amount > balance) {
            std::cout << "Not enough balance!" << std::endl;
            continue;  // Skip to next iteration
        }

        balance -= amount;
        std::cout << "Withdrawn $" << amount << ". Remaining: $" << balance << std::endl;
    }

    std::cout << "Session ended. Final balance: $" << balance << std::endl;
    return 0;
}
```

**How it works:**
- Check condition `balance > 0`.
- If true, run the body (ask input, update balance).
- Repeat.

**Infinite Loop Warning:** If condition never becomes false (e.g., forgot to decrease `balance`), it runs forever. Always ensure progress inside the loop.

**Common Use:** Reading files line-by-line until end-of-file, or game loops waiting for user action.

## 3. The `do-while` Loop
The `do-while` loop is like `while`, but **it runs the code at least once** before checking the condition. Perfect when you must execute something first (like showing a menu).

### Syntax
```cpp
do {
    // code to repeat
} while (condition);
```

Note the semicolon `;` at the end.

### Real-World Example: Simple Login Retry Like Bank App
You always show the login screen at least once, then retry if wrong.

```cpp
#include <iostream>
#include <string>

int main() {
    std::string password = "secret123";
    std::string input;
    int attempts = 0;

    do {
        std::cout << "Enter password: ";
        std::cin >> input;
        attempts++;

        if (input == password) {
            std::cout << "Login successful!" << std::endl;
            break;
        } else {
            std::cout << "Wrong password. Attempt " << attempts << std::endl;
        }
    } while (attempts < 3);  // Check after first run

    if (attempts >= 3) {
        std::cout << "Too many attempts. Account locked." << std::endl;
    }
    return 0;
}
```

**Key Difference:** Even if condition is false initially, the body runs once. In a plain `while`, it might not run at all.

**Common Use:** Menus in console apps, validation forms where you prompt user first.

## Comparison Table

| Loop Type   | Runs at least once? | Best For                          | Example Scenario                  |
|-------------|---------------------|-----------------------------------|-----------------------------------|
| `for`      | No                 | Known number of iterations       | Process 50 records                |
| `while`    | No                 | Condition-based, unknown count   | Read until end of file            |
| `do-while` | Yes                | Must run once, then check        | Show menu / get user input first  |

## Best Practices & Common Mistakes (Beginner Tips)
- **Avoid Infinite Loops:** Always update a variable in the condition inside the body.
- **Use `break`:** To exit early (e.g., found what you needed).
- **Use `continue`:** Skip to next iteration.
- **Indentation:** Makes code readable.
- **Nested Loops:** Possible, but keep simple (e.g., for printing tables).
- **Performance:** For large data, `for` is often fastest as it's optimized.

### Example of Nested For Loop (Real-world: Printing Multiplication Table)
```cpp
for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 5; j++) {
        std::cout << i * j << "\t";
    }
    std::cout << std::endl;
}
```