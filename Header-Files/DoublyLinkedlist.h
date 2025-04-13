#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include <iostream>
using namespace std;

template<class T>
class DoublyLinkedList
{
	struct Node {
		T val;
		Node* next;
		Node* prev;
		Node(T val);
		Node();
	}*head, * tail;
	int length{ 0 };
public:
	DoublyLinkedList();
	void insertAt(int idx, T val);
	void deleteAt(int idx);
	void append(T val);
	T at(int idx);
	int Length();
	~DoublyLinkedList();
};

#include "DoublyLinkedList.cpp"
#endif

