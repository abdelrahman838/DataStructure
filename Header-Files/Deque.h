#pragma once
template<class T>
class Deque
{
public:
	int front;
	int rear;
	int size;
	int capacity;
	float expandFactor;
	T* arr;

	Deque();
	void Expand();
	void enQueuefront(T x);
	void enQueueback(T x);
	T deQueuefront();
	T deQueueback();
	T frontE();
	T backE();
	bool isEmpty();
	bool isFull();
	int Size();
};

