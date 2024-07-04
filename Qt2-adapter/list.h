#ifndef MyList_H
#define MyList_H

#include <iostream>
#include <vector>

class MyList
{
public:
    MyList();
    MyList(int);
    MyList(int, int, int);
    ~MyList();
    struct SElement {
        int data;
        SElement* next;
        SElement() = default;
        SElement(int data_, SElement* next_) : data(data_), next(next_) {}
        ~SElement() = default;
    };
    void print() const;
    bool isEmpty() const;
    void addFirst(int a);
    int deleteFirst();
    std::vector<int> toVector() const;

private:
    SElement* first;
};

#endif
