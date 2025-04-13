#include "Linkedlist.h"


// linkedlist with undo: we keep track of the history of operations done and the value that got added or removed in a stack and by calling the undo method 
// we can recall the operation and the value and use them as we like :)


Node::Node(int data) {
    this->data = data;
    this->next = nullptr;
}

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    Node* current = head;
    Node* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void LinkedList::InsertFirst(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    history.push({ "InsertFirst", data });
}

void LinkedList::InsertLast(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    history.push({ "InsertLast", data });
}

void LinkedList::RemoveFirst() {
    if (head == nullptr) {
        cout << "List is empty Nothing to remove" << endl;
        return;
    }
    int data = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
    history.push({ "RemoveFirst", data });
}

void LinkedList::RemoveLast() {
    if (head == nullptr) {
        cout << "List is empty Nothing to remove" << endl;
        return;
    }
    int data;
    if (head->next == nullptr) {
        data = head->data;
        delete head;
        head = nullptr;
    }
    else {
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        data = temp->next->data;
        delete temp->next;
        temp->next = nullptr;
    }
    history.push({ "RemoveLast", data });
}

void LinkedList::Delete(int data) {
    if (head == nullptr) {
        cout << "List is empty Nothing to delete" << endl;
        return;
    }
    if (head->data == data) {
        RemoveFirst();
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != data) {
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        cout << "Element not found in the list" << endl;
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
    history.push({ "Delete", data });
}

void LinkedList::Undo(int UndoSteps = 1) {
    if (history.empty()) {
        cout << "No operations to undo" << endl;
        return;
    }

    if (UndoSteps <= 0) {
        cout << "Please provide a positive integer." << endl;
        return;
    }

    for (int i = 0; i < UndoSteps; ++i) {
        if (history.empty()) {
            cout << "No more operations to undo" << endl;
            return;
        }

        auto lastOperation = history.top();
        history.pop();
        string operation = lastOperation.first;
        int data = lastOperation.second;

        if (operation == "InsertFirst") {
            if (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
        else if (operation == "InsertLast") {
            if (head != nullptr) {
                if (head->next == nullptr) {
                    delete head;
                    head = nullptr;
                }
                else {
                    Node* temp = head;
                    while (temp->next->next != nullptr) {
                        temp = temp->next;
                    }
                    delete temp->next;
                    temp->next = nullptr;
                }
            }
        }
        else if (operation == "RemoveFirst") {
            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        }
        else if (operation == "RemoveLast") {
            Node* newNode = new Node(data);
            if (head == nullptr) {
                head = newNode;
            }
            else {
                Node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
        else if (operation == "Delete") {
            Node* newNode = new Node(data);
            if (head == nullptr) {
                head = newNode;
            }
            else {
                Node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        cout << "Undo successful: Reversed '" << operation << "' operation." << endl;
    }
}

void LinkedList::Display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

bool LinkedList::IsEmpty() {
    return (head == nullptr);
}