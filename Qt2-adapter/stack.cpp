#include "stack.h"

MyStack::MyStack()
{
    list = new MyList;
}

MyStack::~MyStack()
{
    while (!isEmpty()) {
        this->pop();
    }
}

void MyStack::push(int a)
{
    this->list->addFirst(a);
}

int MyStack::pop()
{
    int res = this->list->deleteFirst();
    return res;
}

bool MyStack::isEmpty() const
{
    return this->list->isEmpty();
}

std::vector<int> MyStack::toVector() const
{
    return list->toVector();
}
