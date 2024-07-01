#pragma once

#include <iostream>
#include <vector>

class MyList {
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
	void print()const;
	bool isEmpty() const;
	void addFirst(int a);
	int deleteFirst();
	int Get(int) const;
	int Count() const;
	std::vector<int> toVector();
private:
	SElement* first;
};

class Iterator {
public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() const = 0;
	virtual int CurrentItem() const = 0;
protected:
	Iterator() = default;
};

class ListIterator : public Iterator {
public:
	ListIterator(const MyList* aList);
	virtual void First();
	virtual void Next();
	virtual bool IsDone() const;
	virtual int CurrentItem() const;
private:
	const MyList* _list;
	int _current;
};