#include <iostream>
#include "Library.h"

using namespace std;

void showMenu() {
    cout << "\n===== Library Management System =====\n";
    cout << "1. Add book\n";
    cout << "2. Remove book\n";
    cout << "3. Search book by ID\n";
    cout << "4. Borrow book\n";
    cout << "5. Return book\n";
    cout << "6. Sort books by ID\n";
    cout << "7. Sort books by publish year\n";
    cout << "8. Show all books\n";
    cout << "9. Undo last operation\n";
    cout << "0. Exit\n";
    cout << "Choose: ";
}

int main() {
    Library library;
    int choice;

    do {
        showMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input.\n";
            continue;
        }

        if (choice == 1) {
            int id, year;
            string title, author;

            cout << "Book ID: ";
            cin >> id;
            cin.ignore();

            cout << "Title: ";
            getline(cin, title);

            cout << "Author: ";
            getline(cin, author);

            cout << "Publish year: ";
            cin >> year;

            Book book(id, title, author, year);
            cout << (library.addBook(book) ? "Book added.\n" : "Add failed.\n");
        }

        else if (choice == 2) {
            int id;
            cout << "Book ID to remove: ";
            cin >> id;
            cout << (library.removeBook(id) ? "Removed.\n" : "Not found.\n");
        }

        else if (choice == 3) {
            int id;
            cout << "Book ID to search: ";
            cin >> id;
            Book* b = library.searchBookByCode(id);
            if (b) b->print();
            else cout << "Not found.\n";
        }

        else if (choice == 4) {
            int id;
            cout << "Book ID to borrow: ";
            cin >> id;
            cout << (library.borrowBook(id) ? "Borrowed.\n" : "Borrow failed.\n");
        }

        else if (choice == 5) {
            int id;
            cout << "Book ID to return: ";
            cin >> id;
            cout << (library.returnBook(id) ? "Returned.\n" : "Return failed.\n");
        }

        else if (choice == 6) {
            library.sortByCode();
            cout << "Sorted by ID.\n";
        }

        else if (choice == 7) {
            library.sortByYear();
            cout << "Sorted by year.\n";
        }

        else if (choice == 8) {
            library.printAllBooks();
        }

        else if (choice == 9) {
            cout << (library.undoLastOperation() ? "Undo done.\n" : "Nothing to undo.\n");
        }

        else if (choice == 0) {
            cout << "Goodbye!\n";
        }

        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
