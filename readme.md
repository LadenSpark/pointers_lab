# Book Inventory System (RAII & Destructors Lab)

A C++ console application demonstrating **Resource Acquisition Is Initialization (RAII)** and dynamic memory management. The program uses an `Inventory` class to own and manage the lifecycle of heap-allocated `Book` pointers (`std::vector<Book*>`), ensuring all memory allocated with `new` is automatically freed with `delete` upon removal or destruction.

---

## 1. Book Class

A class representing an individual book entry in the store's catalog.

### Data Dictionary

| Attribute | Data Type | Description |
| :--- | :--- | :--- |
| `title` | `std::string` | The title of the book. |
| `author` | `std::string` | The full name of the book's author. |
| `price` | `double` | The retail price of the book. |

### Methods List

| Method Signature | Return Type | Description |
| :--- | :--- | :--- |
| `Book(const std::string& bookTitle, const std::string& bookAuthor, double bookPrice)` | (Constructor) | Parameterized constructor initializing the book's title, author, and non-negative price. |
| `displayInfo() const` | `void` | Prints the book's formatted title, author, and price to standard output. |

---

## 2. Inventory Class (RAII Resource Manager)

A class responsible for owning and managing a collection of dynamically allocated `Book` objects, preventing memory leaks via its destructor and removal logic.

### Data Dictionary

| Attribute | Data Type | Description |
| :--- | :--- | :--- |
| `books` | `std::vector<Book*>` | A dynamic array storing pointers to heap-allocated `Book` objects. |

### Methods List

| Method Signature | Return Type | Description |
| :--- | :--- | :--- |
| `Inventory()` | (Constructor) | Default constructor initializing an empty vector of `Book` pointers. |
| `~Inventory()` | (Destructor) | **RAII Destructor:** Iterates through the `books` vector and calls `delete` on every remaining `Book*` before the `Inventory` object goes out of scope. |
| `Inventory(const Inventory&) = delete` | (Deleted) | Deleted copy constructor to prevent shallow copies of raw pointers. |
| `operator=(const Inventory&) = delete` | (Deleted) | Deleted copy assignment operator to prevent shallow copies and double-deletion. |
| `addBook(Book* bookPtr)` | `void` | Takes ownership of a dynamically allocated `Book*` and appends it to the `books` vector. |
| `displayAll() const` | `void` | Iterates through the `books` vector and calls `displayInfo()` on each `Book*` using the arrow operator (`->`). |
| `removeBook(int index)` | `void` | Validates the index, calls `delete` on `books[index]` to free the heap memory, and erases the pointer from the vector. |
| `isEmpty() const` | `bool` | Returns `true` if the inventory vector contains no books, `false` otherwise. |