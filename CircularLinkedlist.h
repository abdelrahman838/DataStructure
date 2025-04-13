#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H
#include <iostream>
using namespace std;

template<class T>
class CircularLinkedList
{
	struct Node {
		T val;
		Node* next;
		Node(T val);
		Node();
	}*head, * tail;
	int length{ 0 };
public:
	CircularLinkedList();
	void insertAt(int idx, T val);
	void deleteAt(int idx);
	void append(T val);
	T at(int idx);
	int Length();
	void print();
	~CircularLinkedList();
};

#include "CircularLinkedList.cpp"
#endif

