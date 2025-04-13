#include "Deque.h"
#include<iostream>
using namespace std;

template<class T>
Deque<T>::Deque()
{
	front = rear = -1;
	size = 0;
	capacity = 2;
	expandFactor = 1.5;
	arr = new T[capacity];

}

template<class T>
void Deque<T>::Expand()
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
void Deque<T>::enQueuefront(T x)
{
	if (isFull())
		Expand();

	front = ((front - 1) % capacity + capacity) % capacity;
	arr[front] = x;
	if (isEmpty())
		rear = front;
	size++;
}

template<class T>
void Deque<T>::enQueueback(T x)
{
	if (isFull())
		Expand();

	rear = (rear + 1) % capacity;
	arr[rear] = x;
	if (isEmpty())
		front = rear;
	size++;
}


template<class T>
T Deque<T>::deQueuefront()
{
	if (isEmpty())
	{
		cout << "ERROR queue is empty";
		return T();
	}
	T temp = frontE();
	front = (front + 1) % capacity;
	size--;

	if (isEmpty()) {
		front = rear = -1;
	}
	return temp;
}

template<class T>
T Deque<T>::deQueueback()
{
	if (isEmpty())
	{
		cout << "ERROR queue is empty";
		return T();
	}
	T temp = backE();
	rear = ((rear - 1) % capacity+capacity) %capacity;
	size--;

	if (isEmpty()) {
		front = rear = -1;
	}
	return temp;
}

template<class T>
T Deque<T>::backE()
{
	return arr[rear];
}

template<class T>
T Deque<T>::frontE()
{
	return arr[front];
}


template<class T>
bool Deque<T>::isEmpty()
{
	return (size == 0);
}


template<class T>
bool Deque<T>::isFull()
{
	return (rear == capacity - 1);
}

template<class T>
int Deque<T>::Size() {
	return size;
}
