#include "History.h"

History::History() {
    top = -1;
}

bool History::isEmpty() const {
    return top == -1;
}

bool History::isFull() const {
    return top == MAX_HISTORY - 1;
}

void History::push(OperationType type, int bookCode) {
    if (isFull()) {
        // Shift left to remove oldest operation
        for (int i = 0; i < MAX_HISTORY - 1; i++) {
            operations[i] = operations[i + 1];
        }
        top--;
    }

    top++;
    operations[top].type = type;
    operations[top].bookCode = bookCode;
}

bool History::pop(Operation& lastOperation) {
    if (isEmpty()) {
        return false;
    }

    lastOperation = operations[top];
    top--;
    return true;
}
