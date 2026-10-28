#include "Inventory.h"
#include <iostream>

// Default Constructor
Inventory::Inventory() = default;

// Destructor: Loops through the vector and deletes every dynamically allocated Book
Inventory::~Inventory() {
    for (Book* bookPtr : books) {
        delete bookPtr;
    }
    books.clear();
    std::cout << "\n[RAII Destructor] Inventory destroyed. All dynamically allocated books freed.\n";
}

// Adds a newly allocated Book pointer to the vector
void Inventory::addBook(Book* bookPtr) {
    if (bookPtr != nullptr) {
        books.push_back(bookPtr);
        std::cout << "Book added to inventory successfully!\n";
    }
}

// Iterates through the vector and calls displayInfo() using the arrow operator (->)
void Inventory::displayAll() const {
    std::cout << "\n--- Current Book Inventory ---\n";
    if (books.empty()) {
        std::cout << "The inventory is currently empty.\n";
        return;
    }

    for (size_t i = 0; i < books.size(); ++i) {
        std::cout << "[" << i << "] ";
        books[i]->displayInfo();
    }
}

// Deletes the Book object on the heap BEFORE erasing the pointer from the vector
void Inventory::removeBook(int index) {
    if (books.empty()) {
        std::cout << "Cannot remove: Inventory is empty.\n";
        return;
    }

    if (index < 0 || index >= static_cast<int>(books.size())) {
        std::cout << "Error: Invalid index. Please choose an index between 0 and "
                  << (books.size() - 1) << ".\n";
        return;
    }

    // 1. Free the memory on the heap first
    delete books[index];

    // 2. Erase the pointer from the vector second
    books.erase(books.begin() + index);

    std::cout << "Book at index " << index << " removed and memory freed.\n";
}

// Helper to check if the inventory has any books
bool Inventory::isEmpty() const {
    return books.empty();
}