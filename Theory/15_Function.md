# Functions and Function Prototypes in C++

## 1. What is a Function in C++?

A **function** is a reusable block of code that performs a specific task.  
Think of it as a **worker** in a factory: you give it some inputs (materials), it does its job, and returns an output (finished product).

### Real-World Analogy
Imagine you are building a **Banking App**:
- You need to calculate interest many times (for savings, loans, etc.).
- Instead of writing the interest calculation code everywhere, you create one `calculateInterest()` function and call it whenever needed.

**Benefits**:
- Code reusability
- Easier debugging (fix once, works everywhere)
- Cleaner and organized code

---

## 2. Basic Function Syntax

```cpp
return_type function_name(parameter1, parameter2, ...) {
    // body - the actual work
    // statements...
    return value;  // optional, depending on return_type
}
```

**Breakdown**:
- `return_type`: What the function gives back (`int`, `double`, `void`, `string`, etc.)
- `function_name`: Descriptive name (use camelCase or snake_case)
- `parameters`: Inputs the function needs (can be zero)
- `return`: Sends result back to the caller

---

## 3. Simple Function Example

Let's create a function that adds two numbers.

```cpp
#include <iostream>
using namespace std;

// Function definition
int addNumbers(int a, int b) {
    int sum = a + b;
    return sum;
}

int main() {
    int result = addNumbers(10, 25);  // Calling the function
    cout << "Sum is: " << result << std::endl;
    return 0;
}
```

**Output**:
```
Sum is: 35
```

**Real-world use**: In an e-commerce app, you might have:
```cpp
double calculateTotal(double price, int quantity) {
    return price * quantity;
}
```

---

## 4. Function with No Return Value (`void`)

```cpp
#include <iostream>
using namespace std;

void printWelcomeMessage(string userName) {
    cout << "Hello " << userName << "! Welcome to our banking app." << endl;
    cout << "Today's date: 26 June 2026" << endl;
}

int main() {
    printWelcomeMessage("Alice");
    return 0;
}
```

**When to use `void`**?  
When the function just **does something** (prints, updates database, sends email) but doesn't need to return a value.

---

## 5. Function Prototypes (Function Declaration)

A **function prototype** tells the compiler: "Hey, this function exists. I'll define it later."

### Why do we need Prototypes?

In C++, the compiler reads code from top to bottom.  
If you call a function **before** defining it, the compiler complains:  
`"error: ‘calculateInterest’ was not declared in this scope"`

**Solution**: Write a **prototype** at the top.

### Syntax of Prototype

```cpp
return_type function_name(parameter_types);
```

**Note**: No body, just semicolon `;`

---

## 6. Complete Example with Prototype

```cpp
#include <iostream>

// Function Prototypes (Declarations)
int addNumbers(int a, int b);
double calculateInterest(double principal, double rate, int time);

int main() {
    int sum = addNumbers(15, 30);
    std::cout << "Sum: " << sum << std::endl;

    double interest = calculateInterest(10000.0, 0.05, 2);
    std::cout << "Interest: " << interest << std::endl;

    return 0;
}

// Function Definitions (actual code) - can be after main()
int addNumbers(int a, int b) {
    return a + b;
}

double calculateInterest(double principal, double rate, int time) {
    // Simple interest formula: (P * R * T)
    return principal * rate * time;
}
```

**Output**:
```
Sum: 45
Interest: 1000
```

This is a common pattern in real C++ projects.

---

## 7. Real-World Banking App Example

```cpp
#include <iostream>

// Prototypes
double deposit(double currentBalance, double amount);
double withdraw(double currentBalance, double amount);
void showBalance(double balance);

int main() {
    double balance = 5000.0;

    balance = deposit(balance, 2500.0);
    showBalance(balance);

    balance = withdraw(balance, 1200.0);
    showBalance(balance);

    return 0;
}

// Definitions
double deposit(double currentBalance, double amount) {
    if (amount > 0) {
        std::cout << "Deposited: " << amount << std::endl;
        return currentBalance + amount;
    }
    return currentBalance;
}

double withdraw(double currentBalance, double amount) {
    if (amount > 0 && amount <= currentBalance) {
        std::cout << "Withdrawn: " << amount << std::endl;
        return currentBalance - amount;
    }
    std::cout << "Insufficient balance or invalid amount!" << std::endl;
    return currentBalance;
}

void showBalance(double balance) {
    std::cout << "Current Balance: Rs. " << balance << std::endl;
}
```

This mirrors how real banking software organizes operations.

---

## 8. Important Rules & Best Practices

1. **Prototype must match definition** exactly (return type, name, parameters).
2. Parameter names in prototype are **optional**:
   ```cpp
   double calculateInterest(double, double, int);  // Valid
   ```
3. Use **descriptive names**:
   - Good: `getUserAge()`
   - Bad: `func1()`
4. Keep functions **small** — one function should do **one thing**.
5. Pass by value vs reference (we'll cover references later, but remember: large objects should use `const std::string&`).

---