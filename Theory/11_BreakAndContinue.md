# Break and Continue Statements in C++

## 1. What is the `break` Statement?

The `break` statement **immediately stops the entire loop** and moves execution to the code right after the loop.

### Real-World Analogy
Imagine you're searching for a specific product in a big inventory list. Once you find it, you don't need to check the remaining items. You "break" out of the search.

### Syntax
```cpp
for (/* loop condition */) {
    if (/* some condition */) {
        break;  // Exit the loop completely
    }
    // Rest of the loop body
}
// Code here runs after break
```

### Example 1: Finding a User in a List (Real Project Scenario)
You're building a user management system and need to find if a user with ID 42 exists.

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> userIds = {10, 25, 42, 67, 89};  // Imagine this comes from a database
    
    int targetId = 42;
    bool found = false;
    
    for (int i = 0; i < userIds.size(); i++) {
        if (userIds[i] == targetId) {
            std::cout << "User found at index: " << i << std::endl;
            found = true;
            break;  // Stop checking remaining users
        }
    }
    
    if (!found) {
        std::cout << "User not found" << std::endl;
    }
    
    return 0;
}
```

**Output:**
```
User found at index: 2
```

Without `break`, the loop would continue unnecessarily, wasting CPU time in large lists (think 10,000+ users).

---

## 2. What is the `continue` Statement?

The `continue` statement **skips the rest of the current iteration** and moves to the next iteration of the loop.

### Real-World Analogy
You're processing a list of orders. Some orders are cancelled — you want to skip them and process only active ones.

### Syntax
```cpp
for (/* loop condition */) {
    if (/* condition to skip */) {
        continue;  // Jump to next iteration
    }
    // This code runs only for items we don't skip
}
```

### Example 2: Processing Orders - Skip Cancelled Ones
```cpp
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> orders = {"active", "cancelled", "active", "shipped", "cancelled"};
    
    int processedCount = 0;
    
    for (const std::string& status : orders) {
        if (status == "cancelled") {
            std::cout << "Skipping cancelled order..." << std::endl;
            continue;  // Don't process this order
        }
        
        std::cout << "Processing " << status << " order..." << std::endl;
        processedCount++;
    }
    
    std::cout << "Total orders processed: " << processedCount << std::endl;
    return 0;
}
```

**Output:**
```
Processing active order...
Skipping cancelled order...
Processing active order...
Processing shipped order...
Skipping cancelled order...
Total orders processed: 3
```

This is very common when cleaning data or filtering invalid records from logs or API responses.

---

## 3. `break` vs `continue` - Side by Side Comparison

| Feature              | `break`                          | `continue`                          |
|----------------------|----------------------------------|-------------------------------------|
| What it does         | Exits the loop completely        | Skips to next iteration             |
| Code after it        | Never runs in current loop       | Runs in next iteration              |
| Use case             | Stop when goal is achieved       | Skip unwanted items                 |
| Real project example | Stop searching after finding item| Skip invalid records in batch job   |

---

## 4. Nested Loops - Important Behavior

- `break` only exits the **innermost** loop.
- `continue` also works only on the **innermost** loop.

### Example 3: Finding a Seat in a Cinema (2D Grid)
```cpp
#include <iostream>

int main() {
    // Rows x Seats (simplified cinema booking)
    for (int row = 1; row <= 5; row++) {
        std::cout << "Checking Row " << row << std::endl;
        
        for (int seat = 1; seat <= 10; seat++) {
            if (seat == 3 && row == 2) {  // Found available seat
                std::cout << "Booked seat at Row " << row << ", Seat " << seat << std::endl;
                break;  // Only breaks inner seat loop, continues to next row? No - we can add outer break logic
            }
            
            if (seat % 2 == 0) {  // Skip even seats for some reason
                continue;
            }
            // Process odd seats only
        }
    }
    return 0;
}
```

**Note**: To break out of multiple loops, many developers use a flag variable or `goto` (not recommended for clean code).

---

## 5. Common Mistakes Beginners Make

1. **Putting code after `break` or `continue`** inside the same iteration — it won't execute.
2. Using `break`/`continue` **outside** any loop → Compiler error.
3. Forgetting that `break` only affects the innermost loop in nested structures.
4. Overusing them — sometimes refactoring into smaller functions is cleaner.

---

## 6. Practice Exercise (Try This Now)

**Problem**: Write a program that reads numbers from the user until they enter -1. Sum only positive numbers and ignore negative ones except -1 (which should stop the program).

**Hint**: Use `while(true)`, `continue` for negative numbers, and `break` for -1.

**Solution** (try first before seeing):

```cpp
#include <iostream>

int main() {
    int sum = 0;
    int num;
    
    std::cout << "Enter numbers (-1 to stop):" << std::endl;
    
    while (true) {
        std::cin >> num;
        
        if (num == -1) {
            break;  // Stop everything
        }
        
        if (num < 0) {
            std::cout << "Ignoring negative number" << std::endl;
            continue;  // Skip to next input
        }
        
        sum += num;
    }
    
    std::cout << "Total sum: " << sum << std::endl;
    return 0;
}
```

---

## Key Takeaways

- Use **`break`** when you want to **stop** the loop early (searching, validation).
- Use **`continue`** when you want to **skip** the current item and move forward (filtering bad data).
- Both make your loops more efficient and readable in real applications.
- Always test with different inputs — edge cases like empty lists or all items being skipped.