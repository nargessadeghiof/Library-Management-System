#include "Library.h"
#include "LoanQueue.h"
#include <iostream>

Library::Library() {
    bookCount = 0;
}

int Library::findBookIndexByCode(int code) const {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getId() == code) {
            return i;
        }
    }
    return -1;
}

bool Library::addBook(const Book& book) {
    if (bookCount >= MAX_BOOKS) return false;
    if (findBookIndexByCode(book.getId()) != -1) return false;

    books[bookCount++] = book;
    history.push(ADD_BOOK, book.getId());
    return true;
}


bool Library::removeBook(int code) {
    int index = findBookIndexByCode(code);
    if (index == -1) return false;

    for (int i = index; i < bookCount - 1; i++) {
        books[i] = books[i + 1];
    }

    bookCount--;
    history.push(REMOVE_BOOK, code);
    return true;
}



bool Library::borrowBook(int code) {
    int index = findBookIndexByCode(code);
    if (index == -1) {
        return false; // کتاب وجود ندارد
    }

    if (!books[index].getAvailability()) {
        return false; // قبلاً امانت داده شده
    }

    books[index].borrowBook();
    LoanQueue::enqueue(code);
    history.push(BORROW_BOOK, code); // ← برای Undo لازم است
    return true;
}


bool Library::returnBook(int code) {
    int index = findBookIndexByCode(code);
    if (index == -1) return false;
    if (books[index].getAvailability()) return false;

    books[index].returnBook();
    history.push(RETURN_BOOK, code);
    return true;
}


Book* Library::searchBookByCode(int code) {
    int index = findBookIndexByCode(code);
    if (index == -1) {
        return nullptr;
    }
    return &books[index];
}

void Library::sortByCode() {
    for (int i = 0; i < bookCount - 1; i++) {
        for (int j = 0; j < bookCount - i - 1; j++) {
            if (books[j].getId() > books[j + 1].getId()) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

void Library::sortByYear() {
    for (int i = 0; i < bookCount - 1; i++) {
        for (int j = 0; j < bookCount - i - 1; j++) {
            if (books[j].getPublishYear() > books[j + 1].getPublishYear()) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

int Library::getBookCount() const {
    return bookCount;
}

void Library::printAllBooks() const {
    for (int i = 0; i < bookCount; i++) {
        std::cout << "ID: " << books[i].getId() << std::endl;
        std::cout << "Title: " << books[i].getTitle() << std::endl;
        std::cout << "Author: " << books[i].getAuthor() << std::endl;
        std::cout << "Year: " << books[i].getPublishYear() << std::endl;
        std::cout << "Status: "
                  << (books[i].getAvailability() ? "Available" : "Borrowed")
                  << std::endl;
        std::cout << "------------------" << std::endl;
    }
}
bool Library::undoLastOperation() {
    Operation lastOp;

    if (!history.pop(lastOp)) {
        return false;
    }

    switch (lastOp.type) {
    case ADD_BOOK:
        removeBook(lastOp.bookCode);
        break;

    case REMOVE_BOOK:
        // Undo remove is not fully supported without backup data
        return false;

    case BORROW_BOOK:
        returnBook(lastOp.bookCode);
        break;

    case RETURN_BOOK:
        borrowBook(lastOp.bookCode);
        break;
    }

    return true;
}

