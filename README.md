Got it! You want **one full README.md** with **two separate sections**: one for the vector-based stack and one for the linked list class. No combined examples — just clear descriptions and usage info for each. Here's a ready-to-copy version:

---

# 📦 Data Structures Playground

This project is a small C++ program that lets you explore and interact with two fundamental data structures: **stacks** and **singly linked lists**. It’s perfect for learning how these structures work and practicing basic C++ programming concepts like classes, templates, and pointers.

---

## ⚙️ Vector-Based Stack

The **vector-based stack** (`v_stack`) is a stack implementation using `std::vector` internally. It supports basic stack operations and comes with a simple console menu for testing.

### Features

* **`push()`** → Adds an integer to the top of the stack
* **`pop()`** → Removes the top integer
* **`top()`** → Returns the top integer (throws an exception if the stack is empty)
* **`empty()`** → Checks if the stack has any elements
* **`size()`** → Returns the number of elements in the stack
* **`findAverage()`** → Calculates the average of all elements without modifying the stack

### Menu Interface

The stack includes an interactive menu with the following options:

```
1. Check if the stack is empty
2. Insert an integer
3. Remove an integer
4. Find the top
5. Find average value
6. Exit
```

This menu allows users to add, remove, inspect, and perform calculations on the stack elements easily.

### Usage Example

```cpp
#include "vector_based_stack.h"
#include <iostream>

int main() {
    v_stack stack;
    stack.push(10);
    stack.push(20);

    std::cout << "Top element: " << stack.top() << std::endl; // 20
    stack.pop();
    std::cout << "Stack size: " << stack.size() << std::endl; // 1
    findAverage(stack); // 10

    return 0;
}
```

---

## ⚙️ Single Linked List

The **single linked list** (`Single_Linked_List`) is a **templated class** that can hold any type of data. It uses nodes connected via pointers and allows insertion, removal, and search operations at any position.

### Features

* **`push_front()` / `push_back()`** → Add elements to the front or back
* **`pop_front()` / `pop_back()`** → Remove elements from front or back
* **`front()` / `back()`** → Access first or last element
* **`insert(index, item)`** → Insert an element at a specific index
* **`remove(index)`** → Remove an element at a specific index
* **`find(item)`** → Get the index of the first occurrence of an item
* **`empty()`** → Check if the list is empty
* **`size()`** → Returns the number of elements

### Usage Example

```cpp
#include "linked_list_class.h"
#include <iostream>

int main() {
    Single_Linked_List<int> list;

    list.push_back(10);
    list.push_front(5);
    list.insert(1, 7); // list: 5, 7, 10

    std::cout << "Front: " << list.front() << std::endl; // 5
    std::cout << "Back: " << list.back() << std::endl;   // 10

    list.pop_back(); // removes 10
    std::cout << "Size: " << list.size() << std::endl;  // 2

    size_t idx = list.find(7);
    std::cout << "Index of 7: " << idx << std::endl;    // 1

    return 0;
}
```

---

## 🧰 How to Compile and Run

### Compile Stack Example

```bash
g++ -std=c++17 main.cpp vector_based_stack.cpp -o stack_program
./stack_program
```

> Note: The `main.cpp` provided runs the **stack menu**.

### Compile Linked List Example

Create your own `main.cpp` to test the linked list like in the example above, then compile:

```bash
g++ -std=c++17 main.cpp linked_list_class.cpp -o list_program
./list_program
```

---

## 🧑‍💻 Author

**Fisayo Popoola**
CS101L – Data Structures Project
University of Missouri–Kansas City
