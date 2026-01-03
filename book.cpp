#include "Book.h"

// Constructor implementation
Book::Book(int _id, string _title, string _author, int _year) {
    id = _id;
    title = _title;
    author = _author;
    publishYear = _year;
    isAvailable = true; // Book is available when created
}

// Returns book ID
int Book::getId() const {
    return id;
}

// Returns book title
string Book::getTitle() const {
    return title;
}

// Returns author name
string Book::getAuthor() const {
    return author;
}

// Returns publication year
int Book::getPublishYear() const {
    return publishYear;
}

// Returns availability status
bool Book::getAvailability() const {
    return isAvailable;
}

// Marks the book as borrowed
void Book::borrowBook() {
    isAvailable = false;
}

// Marks the book as returned
void Book::returnBook() {
    isAvailable = true;
}
