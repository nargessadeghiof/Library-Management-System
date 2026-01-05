# Library Management System (C++)

This project is a simple Library Management System written in C++.


## Project Functionality
The program allows the user to manage a small library using a menu-based interface.

Main features:
- Adding new books to the library
- Removing books by ID
- Searching for a book by its ID
- Borrowing and returning books
- Sorting books by ID or publish year
- Viewing all stored books
- Undoing recent operations (up to 5 actions)

## Project Components

### Book
Represents a single book.
Each book has:
- ID
- Title
- Author
- Publish year
- Availability status (available or borrowed)

### Library
Manages the collection of books.
It is responsible for:
- Storing books
- Searching, sorting, and displaying books
- Handling borrow and return operations
- Connecting all other parts of the program

### LoanQueue
Handles borrow requests using a queue.
Borrow requests are processed in the order they are received.

### History
Keeps track of recent operations using a stack.
It allows undoing the last operations (maximum 5).

### Main
Provides a simple text-based menu for user interaction.
The user selects options and performs actions on the library.

## Compilation and Run

Compile:
```bash
g++ -std=c++17 *.cpp -o library
