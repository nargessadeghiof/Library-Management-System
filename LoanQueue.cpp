#include "LoanQueue.h"

int LoanQueue::queue[MAX_LOANS];
int LoanQueue::front = 0;
int LoanQueue::rear = 0;

bool LoanQueue::enqueue(int code) {
    if (rear >= MAX_LOANS) {
        return false;
    }
    queue[rear++] = code;
    return true;
}

bool LoanQueue::dequeue() {
    if (front == rear) {
        return false;
    }
    front++;
    return true;
}

bool LoanQueue::isEmpty() {
    return front == rear;
}
