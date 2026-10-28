/*
 * Name: Jason Suits
 * Date: October 27, 2026
 * Assignment: Lab - Pointers & Vectors (RAII and Destructors)
 * Purpose: Driver program demonstrating RAII resource management by allocating
 *          Book objects with 'new' and entrusting their lifecycle to the Inventory class.
 */

#include <iostream>
#include <string>
#include <limits>
#include "Inventory.h"

// Input validation helpers
int getValidInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cout << "Invalid input. Please enter a valid integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

double getValidPrice(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= 0.0) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cout << "Invalid price. Please enter a non-negative number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string getValidString(const std::string& prompt) {
    std::string text;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, text);
        if (!text.empty()) {
            return text;
        }
        std::cout << "Input cannot be empty. Please try again.\n";
    }
}

int main() {
    // Single Inventory object; its destructor automatically cleans up all Books on exit
    Inventory store;
    int choice = 0;

    do {
        std::cout << "\n========================================\n";
        std::cout << "         BOOK INVENTORY SYSTEM          \n";
        std::cout << "========================================\n";
        std::cout << "1. Add New Book\n";
        std::cout << "2. Display All Books\n";
        std::cout << "3. Remove Book\n";
        std::cout << "4. Quit\n";

        choice = getValidInt("Enter your choice (1-4): ");

        switch (choice) {
            case 1: {
                std::cout << "\n--- Add New Book ---\n";
                std::string title = getValidString("Enter Book Title: ");
                std::string author = getValidString("Enter Book Author: ");
                double price = getValidPrice("Enter Book Price: $");

                // Dynamically allocate a new Book on the heap and pass pointer to store
                Book* newBook = new Book(title, author, price);
                store.addBook(newBook);
                break;
            }
            case 2:
                store.displayAll();
                break;
            case 3: {
                std::cout << "\n--- Remove Book ---\n";
                if (store.isEmpty()) {
                    std::cout << "No books available to remove.\n";
                } else {
                    store.displayAll();
                    int index = getValidInt("Enter the index of the book to remove: ");
                    store.removeBook(index);
                }
                break;
            }
            case 4:
                std::cout << "Exiting program. Cleaning up resources...\n";
                break;
            default:
                std::cout << "Invalid choice. Please select an option from 1 to 4.\n";
        }
    } while (choice != 4);

    // 'store' goes out of scope here, automatically triggering ~Inventory()
    return 0;
}