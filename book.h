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
    // Constructor
    Book(int _id, string _title, string _author, int _year);

    // Getter methods
    int getId() const;
    string getTitle() const;
    string getAuthor() const;
    int getPublishYear() const;
    bool getAvailability() const;

    // Book status operations
    void borrowBook();      // Mark book as borrowed
    void returnBook();      // Mark book as available
};

#endif
