#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    double price;

public:
    // Parameterized constructor prototype
    Book(const std::string& bookTitle, const std::string& bookAuthor, double bookPrice);

    // Displays formatted book information
    void displayInfo() const;
};

#endif // BOOK_H