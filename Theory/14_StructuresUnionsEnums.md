# Structures, Unions, and Enums in C++

## Introduction

In C++, **structures**, **unions**, and **enums** are user-defined data types. They help you group related data together or represent specific sets of values. 

- A **structure** (`struct`) groups different types of data (like a record in a database).
- A **union** is like a structure but saves memory by sharing the same storage space for its members.
- An **enum** (enumeration) creates a set of named integer constants (like fixed options).

These are important for real software development. For example, you might use them to store employee details, handle different data types in the same memory slot, or define states in a program.

We will use simple, complete code examples you can copy, compile, and run. Each example includes comments explaining every line.

---

## Structures (struct)

### What is a Structure?

A structure is a collection of variables of **different data types** under one name. Think of it as a custom "box" that holds multiple pieces of information.

Real-world example: Imagine an **Employee record** in a company HR system. One employee has a name (string), ID (integer), salary (float), and joining date (another structure or string). A `struct` keeps all this together.

### How to Declare and Use a Structure

1. Declare the structure outside `main()`.
2. Create variables of that structure type.
3. Access members using the dot `.` operator.

```cpp
#include <iostream>
#include <string>  // For std::string

// Step 1: Declare the structure
struct Employee {
    int id;           // Integer for employee ID
    std::string name; // String for name
    float salary;     // Float for salary
};

int main() {
    // Step 2: Create a variable of Employee type
    Employee emp1;
    
    // Step 3: Assign values to members
    emp1.id = 101;
    emp1.name = "Alice Johnson";
    emp1.salary = 75000.50f;
    
    // Step 4: Print the data
    std::cout << "Employee ID: " << emp1.id << std::endl;
    std::cout << "Name: " << emp1.name << std::endl;
    std::cout << "Salary: $" << emp1.salary << std::endl;
    
    return 0;
}
```

**Output:**
```
Employee ID: 101
Name: Alice Johnson
Salary: $75000.5
```

### Important Points About Structures
- Structures can contain other structures (nested structs).
- You can use `struct Employee emp1 = {101, "Alice", 75000.50f};` for initialization.
- In C++, `struct` members are **public** by default (accessible from anywhere).
- Structures are passed by value to functions by default (copy is made). Use references (`&`) for efficiency.

**Real-world use**: Database records, game characters (position, health, speed), or configuration settings.

---

## Unions

### What is a Union?

A union is similar to a structure, but **all members share the same memory location**. Only one member can hold a value at a time. This saves memory.

Real-world example: In a sensor device, a value can be either a temperature (float) or a status code (int). You use a union so only one type occupies memory at any time.

### How to Declare and Use a Union

```cpp
#include <iostream>

// Declare the union
union Data {
    int intValue;      // 4 bytes (usually)
    float floatValue;  // 4 bytes (usually)
    char charValue;    // 1 byte
};

int main() {
    Data myData;
    
    // Store integer value
    myData.intValue = 42;
    std::cout << "Integer value: " << myData.intValue << std::endl;
    
    // Now store float - this overwrites the memory
    myData.floatValue = 3.14f;
    std::cout << "Float value: " << myData.floatValue << std::endl;
    
    // Reading intValue now would give garbage because memory is overwritten
    std::cout << "Int after float: " << myData.intValue << " (garbage!)" << std::endl;
    
    return 0;
}
```

**Key Difference from Struct**:
- Struct: Each member gets its own separate memory.
- Union: All members share **one memory block** equal to the size of the largest member.

**When to use**: Low-memory embedded systems, device drivers, or when you need to interpret the same bytes in different ways (type punning).

**Warning**: Reading a member you didn't write to recently can cause undefined behavior. Always track which member is active.

---

## Enums (Enumeration)

### What is an Enum?

An enum creates a list of named constants. It makes your code readable by replacing "magic numbers" with meaningful names.

Real-world example: In a traffic light control system, states can be `RED`, `YELLOW`, `GREEN`. Instead of using numbers 0, 1, 2, you use enum names.

### How to Declare and Use an Enum

```cpp
#include <iostream>

// Basic enum
enum TrafficLight {
    RED,      // Automatically 0
    YELLOW,   // 1
    GREEN     // 2
};

// Scoped enum (C++11+) - better practice
enum class Day {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main() {
    TrafficLight light = RED;
    
    if (light == RED) {
        std::cout << "Stop! Light is RED." << std::endl;
    }
    
    // Using scoped enum
    Day today = Day::WEDNESDAY;
    
    // You must use Day:: prefix with scoped enums
    switch (today) {
        case Day::MONDAY:
            std::cout << "Start of work week." << std::endl;
            break;
        case Day::WEDNESDAY:
            std::cout << "Mid week!" << std::endl;
            break;
        default:
            std::cout << "Other day." << std::endl;
    }
    
    return 0;
}
```

### Types of Enums in C++
- **Unscoped enum** (`enum`): Old style. Values are in global scope. Can cause name conflicts.
- **Scoped enum** (`enum class`): Modern. Requires `EnumName::VALUE`. Safer and recommended.

You can assign specific values:
```cpp
enum Status {
    SUCCESS = 0,
    ERROR = -1,
    WARNING = 1
};
```

**Real-world use**: Game states (PLAYING, PAUSED, GAME_OVER), HTTP status codes, or user roles (ADMIN, USER, GUEST).

---

## Key Differences and When to Use Each

| Feature       | Structure (struct)          | Union                     | Enum                     |
|---------------|-----------------------------|---------------------------|--------------------------|
| Memory        | Separate for each member   | Shared (one at a time)   | Just named constants    |
| Purpose       | Group related data         | Save memory / reinterpret| Define fixed options    |
| Best for      | Records (Employee, Point)  | Sensors, variant data    | States, options         |
| Access        | All members at once        | Only one at a time       | Used in conditions      |

**Summary for beginners**:
- Use **struct** when you need multiple pieces of data together.
- Use **union** only when memory is critical and you are sure only one member is active.
- Use **enum** (especially `enum class`) to avoid magic numbers and make code self-documenting.