#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

// Book class represents a single book in the library
class Book {
private:
    int id;                 // Unique book ID
    string title;           // Book title
    string author;          // Author name
    int publishYear;        // Year of publication
    bool isAvailable;       // Availability status

public:
    Book();
    // Constructor
    Book(int _id, string _title, string _author, int _year);

    // Original getters
    int getId() const;
    string getTitle() const;
    string getAuthor() const;
    int getPublishYear() const;
    bool getAvailability() const;

    // === Added for Library compatibility ===
    int getCode() const;        // Same as getId()
    int getYear() const;        // Same as getPublishYear()
    bool getStatus() const;     // Same as getAvailability()
    void setStatus(bool status);

    // Book status operations
    void borrowBook();          // Mark book as borrowed
    void returnBook();          // Mark book as available

    // Display book info
    void print() const;
};

#endif
