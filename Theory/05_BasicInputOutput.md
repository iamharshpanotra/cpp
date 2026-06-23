# C++ Basics: Input, Output, and More

## 1. Your First C++ Program: "Hello, World!"

Every C++ program starts with some boilerplate. Here's the classic "Hello, World!" example:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

### Breaking it down (like explaining to your teammate):
- `#include <iostream>`: This brings in the library for **Input/Output**. It's like importing a toolbox for talking to the user.
- `int main()`: This is the **entry point** — where your program starts running. Every C++ program needs this.
- `std::cout`: This is how you **output** (print) things to the console. `cout` stands for "character output".
- `<<`: The "insertion operator" — it "inserts" the text into the output stream.
- `std::endl`: Adds a new line and flushes the output (makes sure it shows immediately).
- `return 0;`: Tells the system "everything went well" (0 means success).

**Real-world example**: Imagine you're writing a backend service that logs "Server started successfully!" when it boots up. This is the foundation.

**How to run it**:
1. Save as `hello.cpp`
2. Compile: `g++ hello.cpp -o hello`
3. Run: `./hello`

## 2. Basic Output with `cout`

Let's make it more useful. You can output variables, numbers, and mix text.

```cpp
#include <iostream>

int main() {
    std::cout << "Welcome to My App!" << std::endl;
    std::cout << "Today's date: " << 2026 << std::endl;
    std::cout << "Version: " << 1.5 << std::endl;
    return 0;
}
```

**Pro tip for beginners**: Use `using namespace std;` at the top to avoid typing `std::` every time (but be careful in big projects — it can cause name conflicts).

Updated version:
```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, User!\n";  // \n also makes a new line
    return 0;
}
```

**Real-world**: In a logging system for an e-commerce app, you'd output order confirmations or error messages to help debug issues quickly.

## 3. Basic Input with `cin`

Now, let's get input from the user. This is where programs become interactive!

```cpp
#include <iostream>
using namespace std;

int main() {
    string name;  // We need to declare variables first
    
    cout << "Enter your name: ";
    cin >> name;  // Reads input until space or Enter
    
    cout << "Hello, " << name << "! Welcome to the store." << endl;
    return 0;
}
```

### Key points:
- `string name;`: Declares a variable to store text. (We'll cover data types soon.)
- `cin >> name;`: Reads from console into the variable. `>>` is the "extraction operator".
- **Limitation**: `cin >>` stops at the first space. For full names or sentences, use `getline()` (more on that later).

**Real-world example**: Building a login screen for a banking app. User enters their username, and the program greets them or validates it.

Try it: Compile and run, type your name!

## 4. Variables and Data Types

Variables are like boxes to store data. You must declare their **type** first.

Common types:
- `int`: Whole numbers (age, count)
- `double` / `float`: Decimal numbers (price, temperature)
- `string`: Text
- `char`: Single character
- `bool`: True/False

Example:
```cpp
#include <iostream>
#include <string>  // For std::string
using namespace std;

int main() {
    int age;
    double salary;
    string fullName;
    bool isActive = true;

    cout << "Enter your full name: ";
    getline(cin, fullName);  // Better for spaces!

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter expected salary: ";
    cin >> salary;

    cout << "\n--- User Profile ---" << endl;
    cout << "Name: " << fullName << endl;
    cout << "Age: " << age << endl;
    cout << "Salary: $" << salary << endl;
    cout << "Active: " << (isActive ? "Yes" : "No") << endl;

    return 0;
}
```

**Real-world**: This could be part of an HR system where you collect employee info. `getline(cin, fullName)` handles names like "John Doe".

## 5. Simple Calculations (Operators)

Let's build a mini calculator.

```cpp
#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    
    cout << "Enter first number: ";
    cin >> num1;
    
    cout << "Enter second number: ";
    cin >> num2;
    
    cout << "Sum: " << (num1 + num2) << endl;
    cout << "Difference: " << (num1 - num2) << endl;
    cout << "Product: " << (num1 * num2) << endl;
    cout << "Division: " << (num1 / num2) << endl;  // Watch for divide by zero!

    return 0;
}
```

**Real-world**: Pricing calculator in an online store. Or currency converter for a travel booking app.

## 6. Conditionals (if-else) — Making Decisions

```cpp
#include <iostream>
using namespace std;

int main() {
    int score;
    cout << "Enter your test score (0-100): ";
    cin >> score;

    if (score >= 90) {
        cout << "Excellent! A grade." << endl;
    } else if (score >= 75) {
        cout << "Good job! B grade." << endl;
    } else {
        cout << "Needs improvement." << endl;
    }
    return 0;
}
```

**Real-world**: Grade system in an education platform, or eligibility check in a loan approval tool.

## 7. Loops — Repeating Tasks

**While loop** (good when you don't know how many times):
```cpp
#include <iostream>
using namespace std;

int main() {
    int count = 0;
    while (count < 5) {
        cout << "Processing item " << count + 1 << "..." << endl;
        count++;
    }
    cout << "Done!" << endl;
    return 0;
}
```

**For loop** (when you know the count):
```cpp
#include <iostream>
using namespace std;

int main() {
    for(int i = 1; i <= 3; i++) {
        cout << "Iteration " << i << ": Loading data..." << endl;
    }
    return 0;
}
```

**Real-world**: Processing a list of transactions in a payment system (loop through 100 orders).

## 8. Putting It All Together: Simple Menu Program

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int choice;
    string name;

    cout << "=== Simple App Menu ===" << endl;
    cout << "1. Greet User" << endl;
    cout << "2. Calculate Sum" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter your name: ";
        cin.ignore();  // Clear buffer before getline
        getline(cin, name);
        cout << "Hi " << name << "!" << endl;
    } else if (choice == 2) {
        // Add calculator code here
        double a, b;
        cout << "Enter two numbers: ";
        cin >> a >> b;
        cout << "Sum = " << a + b << endl;
    } else {
        cout << "Goodbye!" << endl;
    }
    return 0;
}
```

**Note**: `cin.ignore()` helps when mixing `cin >>` and `getline()`.