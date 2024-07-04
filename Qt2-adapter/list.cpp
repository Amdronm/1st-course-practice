#include "list.h"

MyList::MyList()
{
    first = nullptr;
}

MyList::MyList(int a)
{
    first = new SElement(a, nullptr);
}

MyList::MyList(int a, int b, int c)
{
    first = new SElement(a, new SElement(b, new SElement(c, nullptr)));
}

MyList::~MyList()
{
    while (first != nullptr) {
        this->deleteFirst();
    }
}

void MyList::print() const
{
    for (SElement* tmp = first; tmp != nullptr; tmp = tmp->next) {
        std::cout << tmp->data << std::endl;
    }
}

bool MyList::isEmpty() const
{
    return first == nullptr;
}

void MyList::addFirst(int a)
{
    SElement* tmp = new SElement(a, first);
    first = tmp;
}

int MyList::deleteFirst()
{
    int res = first->data;
    SElement* tmp = first->next;
    delete first;
    first = tmp;
    return res;
}

std::vector<int> MyList::toVector() const
{
    std::vector<int> v;
    for (SElement* tmp = first; tmp != nullptr; tmp = tmp->next) {
        v.push_back(tmp->data);
    }
    return v;
}
