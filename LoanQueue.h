#ifndef LOANQUEUE_H
#define LOANQUEUE_H

class LoanQueue {
private:
    static const int MAX_LOANS = 100;
    static int queue[MAX_LOANS];
    static int front;
    static int rear;

public:
    static bool enqueue(int code);
    static bool dequeue();
    static bool isEmpty();
};

#endif
