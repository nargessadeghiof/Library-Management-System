#ifndef LIBRARY_H
#define LIBRARY_H
#include "History.h"

#include "Book.h"

class Library {
private:
    static const int MAX_BOOKS = 100;
    Book books[MAX_BOOKS];
    int bookCount;
    History history;
 
    int findBookIndexByCode(int code) const;
    

public:
    Library();

    // Book management
    bool addBook(const Book& book);
    bool removeBook(int code);
    Book* searchBookByCode(int code);

    // Sorting
    void sortByCode();
    void sortByYear();

    // Utility
    int getBookCount() const;
    void printAllBooks() const;


    bool undoLastOperation();
    // Loan operations
    bool borrowBook(int code);
    bool returnBook(int code);
    

};

#endif
