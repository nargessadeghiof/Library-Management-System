#ifndef HISTORY_H
#define HISTORY_H

// Types of operations that can be undone
enum OperationType {
    ADD_BOOK,
    REMOVE_BOOK,
    BORROW_BOOK,
    RETURN_BOOK
};

// Represents a single operation
struct Operation {
    OperationType type;
    int bookCode;
};

class History {
private:
    static const int MAX_HISTORY = 5;
    Operation operations[MAX_HISTORY];
    int top; // points to last operation

public:
    History();

    bool isEmpty() const;
    bool isFull() const;

    void push(OperationType type, int bookCode);
    bool pop(Operation& lastOperation);
};

#endif
