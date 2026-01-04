#include <iostream>
#include "Library.h"

using namespace std;

void showMenu() {
    cout << "\n===== Library Management System =====\n";
    cout << "1. Add book\n";
    cout << "2. Remove book\n";
    cout << "3. Search book by code\n";
    cout << "4. Borrow book\n";
    cout << "5. Return book\n";
    cout << "6. Sort books by code\n";
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

            if (library.addBook(book))
                cout << "Book added successfully.\n";
            else
                cout << "Failed to add book.\n";
        }

        else if (choice == 2) {
            int code;
            cout << "Book ID to remove: ";
            cin >> code;

            if (library.removeBook(code))
                cout << "Book removed.\n";
            else
                cout << "Book not found.\n";
        }

        else if (choice == 3) {
            int code;
            cout << "Book ID to search: ";
            cin >> code;

            Book* book = library.searchBookByCode(code);
            if (book)
                book->print();
            else
                cout << "Book not found.\n";
        }

        else if (choice == 4) {
            int code;
            cout << "Book ID to borrow: ";
            cin >> code;

            if (library.borrowBook(code))
                cout << "Book borrowed successfully.\n";
            else
                cout << "Borrow failed.\n";
        }

        else if (choice == 5) {
            int code;
            cout << "Book ID to return: ";
            cin >> code;

            if (library.returnBook(code))
                cout << "Book returned successfully.\n";
            else
                cout << "Return failed.\n";
        }

        else if (choice == 6) {
            library.sortByCode();
            cout << "Books sorted by code.\n";
        }

        else if (choice == 7) {
            library.sortByYear();
            cout << "Books sorted by year.\n";
        }

        else if (choice == 8) {
            library.printAllBooks();
        }

        else if (choice == 9) {
            if (library.undoLastOperation())
                cout << "Last operation undone.\n";
            else
                cout << "Nothing to undo.\n";
        }

    } while (choice != 0);

    cout << "Goodbye!\n";
    return 0;
}
