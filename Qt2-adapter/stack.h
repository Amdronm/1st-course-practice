#ifndef MyStack_H
#define MyStack_H

#include "list.h"

class MyStack
{
public:
    MyStack();
    ~MyStack();
    void push(int a);
    int pop();
    bool isEmpty() const;
    std::vector<int> toVector() const;

private:
    MyList* list;
};
#endif // MyStack_H
