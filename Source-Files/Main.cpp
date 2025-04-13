#include "Queue.cpp"
#include "Deque.cpp"
#include "CircularLinkedlist.h"
#include "DoublyLinkedlist.h"
#include<string>
#include<iostream>
using namespace std;

int main() {
	DoublyLinkedList<int> arr;
	arr.insertAt(0, 6);
	arr.insertAt(1, 5);

	for (int i = 0; i < arr.Length(); i++)
	{
		cout << arr.at(i) << " ";
	}
}