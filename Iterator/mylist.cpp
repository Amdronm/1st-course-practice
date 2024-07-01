#include "mylist.h"

MyList::MyList() {
	first = nullptr;
}

MyList::MyList(int a) {
	first = new SElement(a, nullptr);
}

MyList::MyList(int a, int b, int c) {
	first = new SElement(a, new SElement(b, new SElement(c, nullptr)));
}

MyList::~MyList() {
	int res;
	while (first != nullptr) {
		res = this->deleteFirst();
	}
}

void MyList::print() const {
	for (SElement* tmp = first; tmp != nullptr; tmp = tmp->next) {
		std::cout << tmp->data << " ";
	}
}

bool MyList::isEmpty() const {
	return first == nullptr;
}

void MyList::addFirst(int a) {
	SElement* tmp = new SElement(a, first);
	first = tmp;
}

int MyList::deleteFirst() {
	int res = first->data;
	SElement* tmp = first->next;
	delete first;
	first = tmp;
	return res;
}

int MyList::Get(int n) const {
	SElement* el = first;
	for (int i = 0; i < n; i++) {
		el = el->next;
	}
	return el->data;
}

int MyList::Count() const {
	if (isEmpty()) {
		return 0;
	}
	int res = 0;
	SElement* el = first;
	while (el != nullptr) {
		el = el->next;
		res++;
	}
	return res;
}

std::vector<int> MyList::toVector() {
	std::vector<int> v;
	for (SElement* tmp = first; tmp != nullptr; tmp = tmp->next) {
		v.push_back(tmp->data);
	}
	return v;
}

ListIterator::ListIterator(const MyList* aList): 
_list(aList),
_current(0) {}

void ListIterator::First() {
	_current = 0;
}

void ListIterator::Next() {
	_current++;
}

bool ListIterator::IsDone() const {
	return _current >= _list->Count();
}

int ListIterator::CurrentItem() const {
	return _list->Get(_current);
}