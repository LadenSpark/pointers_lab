#include "Book.h"
#include <iostream>
#include <iomanip>

// Parameterized constructor implementation
Book::Book(const std::string& bookTitle, const std::string& bookAuthor, double bookPrice)
    : title(bookTitle), author(bookAuthor), price(bookPrice >= 0.0 ? bookPrice : 0.0) {}

// Displays formatted book details
void Book::displayInfo() const {
    std::cout << "Title: " << std::left << std::setw(25) << title
              << " | Author: " << std::setw(20) << author
              << " | Price: $" << std::fixed << std::setprecision(2) << price << "\n";
}

