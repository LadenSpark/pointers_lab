#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Book.h"

class Inventory {
private:
    std::vector<Book*> books; // Vector of pointers to dynamically allocated Book objects

public:
    // Default constructor
    Inventory();

    // Prevent shallow copies of raw pointers
    Inventory(const Inventory&) = delete;
    Inventory& operator=(const Inventory&) = delete;

    // Destructor (CRITICAL for RAII: frees all remaining Book* in the vector)
    ~Inventory();

    // Public interface methods
    void addBook(Book* bookPtr);
    void displayAll() const;
    void removeBook(int index);
    bool isEmpty() const;
};

#endif // INVENTORY_H