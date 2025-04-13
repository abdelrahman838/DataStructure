#include "Queue.h"
#include<iostream>
using namespace std;

template<class T>
Queue<T>::Queue()
{
	front = rear = -1;
	size = 0;
	capacity = 2;
	expandFactor = 1.5;
	arr = new T[capacity];

}

template<class T>
void Queue<T>::Expand()
{
	int prevcapacity = capacity;
	capacity *= expandFactor;
	T* newarr = new T[capacity];
	int idx = 0;

	while (front != rear)
	{
		newarr[idx] = arr[front];
		front = (front + 1) % prevcapacity;
		idx++;
	}

	newarr[idx] = arr[front];
	front = 0;
	rear = size - 1;
	delete[] arr;
	arr = newarr;
	newarr = nullptr;
}


template<class T>
void Queue<T>::enQueue(T x)
{
	if (isFull())
		Expand();

	if (isEmpty())
		front = 0;
	rear = (rear + 1) % capacity;
	arr[rear] = x;
	size++;
}


template<class T>
T Queue<T>::deQueue()
{
	if (isEmpty())
	{
		cout << "ERROR queue is empty";
		return T();
	}
	T temp = peek();
	front = (front + 1) % capacity;
	size--;

	if (isEmpty()) {
		front = rear = -1;
	}
	return temp;
}



template<class T>
T Queue<T>::peek()
{
	return arr[front];
}


template<class T>
bool Queue<T>::isEmpty()
{
	return (size == 0);
}


template<class T>
bool Queue<T>::isFull()
{
	return (rear == capacity - 1);
}

template<class T>
int Queue<T>::Size() {
	return size;
}