#ifndef CIRCULAR_LINKED_LIST_CPP
#define CIRCULAR_LINKED_LIST_CPP

#include "CircularLinkedlist.h"
template<class T>
CircularLinkedList<T>::Node::Node(T val)
{
	this->val = val;
	next = nullptr;
}

template<class T>
CircularLinkedList<T>::Node::Node()
{
	next = nullptr;
	val = T();
}

template<class T>
CircularLinkedList<T>::CircularLinkedList()
{
	head = tail = nullptr;
}

template<class T>
void CircularLinkedList<T>::insertAt(int idx, T val)
{
	if (idx<0 || idx>length)
		return void(cout << "out of range" << endl);
	Node* newNode = new Node(val);
	length++;
	if (idx == 0) {
		newNode->next = head;
		head = newNode;
		if (length == 1)
			tail = newNode;
		tail->next = head;
		return;
	}
	if (idx == length - 1) {
		newNode->next = head;
		tail->next = newNode;
		tail = newNode;
		return;
	}
	Node* temp = head;
	int i = 0;
	while (i < idx - 1) {
		i++;
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}

template<class T>
void CircularLinkedList<T>::deleteAt(int idx)
{
	if (idx < 0 || idx >= length)
	{
		cout << "out of range" << endl;
		return;
	}
	length--;
	Node* temp = head;
	if (idx == 0) {
		if (!length) {
			delete head;
			head = tail = nullptr;
			return;
		}
		head = head->next;
		tail->next = head;
		delete temp;
		return;
	}
	int i = 0;
	while (i < idx - 1) {
		i++;
		temp = temp->next;
	}
	Node* del = temp->next;
	temp->next = del->next;
	if (idx == length)
	{
		tail = temp;
		temp->next = head;
	}
	delete del;
}

template<class T>
void CircularLinkedList<T>::append(T val)
{
	Node* newNode = new Node(val);
	length++;
	if (length == 1)
	{
		tail = head = newNode;
		tail->next = head;
		return;
	}
	tail->next = newNode;
	tail = newNode;
	tail->next = head;
}

template<class T>
T CircularLinkedList<T>::at(int idx)
{
	if (idx < 0 || idx >= length)
	{
		cout << "out of range" << endl;
		return T();
	}
	Node* temp = head;
	int i = 0;
	while (i < idx) {
		i++;
		temp = temp->next;
	}
	return temp->val;
}

template<class T>
int CircularLinkedList<T>::Length()
{
	return length;
}

template<class T>
CircularLinkedList<T>::~CircularLinkedList()
{
	Node* tmp;
	while (length--) {
		tmp = head->next;
		delete head;
		head = tmp;
	}
}
#endif
