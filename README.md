# 🔗 Doubly Linked List - String Operations

A comprehensive C++ implementation of a doubly linked list designed for character/string manipulation operations.

## ✨ Features

- ✅ **Complete doubly linked list implementation** with forward and backward traversal
- ✅ **String-specific operations** - create lists from strings, search, replace, extract substrings
- ✅ **Memory-safe operations** with comprehensive bounds checking
- ✅ **Interactive testing** with user input functionality

## ⚡ Operations Supported

| Operation | Description | Time Complexity |
|-----------|-------------|-----------------|
| `createList(string)` | Initialize list from string | O(n) |
| `insertChar(pos, char)` | Insert character at position | O(n) |
| `deleteAt(index)` | Delete character at index | O(n) |
| `concatenate(other)` | Join two lists | O(1) |
| `extract(start, length)` | Get substring | O(n) |
| `search(word)` | Find first occurrence | O(n*m) |
| `replace(old, new)` | Replace all occurrences | O(n*m) |
| `display()` | Print the list | O(n) |

## 💻 Example Usage

```cpp
LinkedList myList;
myList.createList("Hello World");
myList.insertChar(5, ',');           // "Hello, World"
myList.replace("World", "C++");      // "Hello, C++"
cout << myList.extract(0, 5);       // "Hello"
```

## 🚀 Sample Run

```
Enter string to add to list 1: Hello
Enter string to add to list 2: World
Concatenated Lists: HelloWorld
Choose a character by index to remove: 5
List after removal: HelloWord
Enter index and length to get substring: 0 5
Substring: Hello
Search for a string in the list: World
Not found
Enter 2 substrings to replace one with another: Word C++
List after replacement: HelloC++
```

## 📁 Code Structure

- **`Node` class**: Basic doubly linked node with char data
- **`LinkedList` class**: Complete list implementation with string operations
- **`main()` function**: Interactive testing interface

