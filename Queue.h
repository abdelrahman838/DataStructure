#pragma once
template<class T>
class Queue
{
public:
	int front;
	int rear;
	int size;
	int capacity;
	float expandFactor;
	T* arr;

	Queue();
	void Expand();
	void enQueue(T x);// push
	T deQueue();// pop
	T peek();// top
	bool isEmpty();
	bool isFull();
	int Size();

};

