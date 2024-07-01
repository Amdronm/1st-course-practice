#pragma once

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
	void print();
	bool isEmpty();
	void addFirst(int a);
	int deleteFirst();
	std::vector<int> toVector();
private:
	SElement* first;
};