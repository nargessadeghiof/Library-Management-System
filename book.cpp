#include "Book.h"
#include <iostream>

using namespace std;

// Default constructor
Book::Book() {
    id = -1;
    title = "";
    author = "";
    publishYear = 0;
    isAvailable = true;
}

// Constructor implementation
Book::Book(int _id, string _title, string _author, int _year) {
    id = _id;
    title = _title;
    author = _author;
    publishYear = _year;
    isAvailable = true;
}

// Original getters
int Book::getId() const {
    return id;
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

int Book::getPublishYear() const {
    return publishYear;
}

bool Book::getAvailability() const {
    return isAvailable;
}

// === Compatibility methods ===
int Book::getCode() const {
    return id;
}

int Book::getYear() const {
    return publishYear;
}

bool Book::getStatus() const {
    return isAvailable;
}

void Book::setStatus(bool status) {
    isAvailable = status;
}

// Book status operations
void Book::borrowBook() {
    isAvailable = false;
}

void Book::returnBook() {
    isAvailable = true;
}

// Display book info
void Book::print() const {
    cout << "ID: " << id << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Publish Year: " << publishYear << endl;
    cout << "Status: " << (isAvailable ? "Available" : "Borrowed") << endl;
    cout << "------------------------" << endl;
}
