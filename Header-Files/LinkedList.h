#pragma once
#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data);
};

class LinkedList {
private:
    Node* head;
    stack<pair<string, int>> history;

public:
    LinkedList();
    ~LinkedList();

    void InsertFirst(int);
    void InsertLast(int);
    void RemoveFirst();
    void RemoveLast();
    void Delete(int);
    void Undo(int);
    void Display();
    bool IsEmpty();
};



