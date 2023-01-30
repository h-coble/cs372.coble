#pragma once
#include <iostream>
template <typename T>
class SelfList
{
private:

    class Node {
    public:
        T  data;
        Node* prev;
        Node* next;
        bool isHidden = false;
    };

    Node* head = nullptr;
    Node* tail = nullptr;

    void setupList() {
        Node* newNode = new Node();
        newNode->next = nullptr;
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
    }
    void deleteListContents() {
        Node* temp = nullptr;
        Node* current = head;
        while (current != nullptr) {
            temp = current->next;
            delete current;
            current = temp;
        }
    }
public:
    SelfList()
    {
        head = new Node();
        head->isHidden = true;
        tail = new Node();
        tail->isHidden = true;
        head->prev = nullptr;
        head->next = tail;
        tail->prev = head;
        tail->next = nullptr;
    }
    SelfList(T newData) {
        setupList();
        head->data = newData;
    }
    SelfList(SelfList& rhs) { // copy constructor
        deleteSelfListContents();
        head = rhs.head;
        tail = rhs.tail;
    }
    ~SelfList() {
        deleteSelfListContents();
    }

    //PUSH & POP================================================
    void push_front(T data) {
        /*Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        newNode->prev = nullptr;
        if (empty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            head->prev = newNode;
            head = newNode;
        }*/
        
        if (this->empty())
        {
            setupList;
            Node* actualHead = head->next;
            actualHead->data = data;
        }
        else
        {
            Node* actualHead = head->next;
            Node* newNode = new Node();
            newNode->data = data;
            newNode->next = actualHead;
            actualHead->prev = newNode;
            newNode->prev = head;
            head->next = newNode;
        }
    }
    void push_back(T data) 
    {
        /*Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;
        if (empty()) {
            tail = newNode;
            head = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }*/

        if (this->empty())
        {
            setupList;
            Node* actualTail = tail->prev;
            actualTail->data = data;
        }
        else
        {
            Node* actualTail = tail->prev;
            Node* newNode = new Node();
            newNode->data = data;
            newNode->prev = actualTail;
            actualTail->next = newNode;
            newNode->next = tail;
            tail->prev = newNode;
        }
    }

    void pop_back() 
    {
        /*
        Node* lastNode = tail;
        if (lastNode != nullptr) {
            tail = tail->prev;
            tail->next = nullptr;
            delete lastNode;
        }*/

        Node* lastNode = tail->prev;
        tail->prev = lastNode->prev;
        Node* newLastNode = tail->prev;
        newLastNode->next = tail;

        delete lastNode;
        lastNode = nullptr;
    }
    void pop_front()
    {
        Node* firstNode = head->next;
        head->next = firstNode->next;
        Node* newFirstNode = head->next;
        newLastNode->prev = head;

        delete firstNode;
        firstNode = nullptr;
    }
    //==========================================================

    bool  empty() {
        return (head->next == tail);
    }

    T &front() 
    {
        Node* actualHead = head->next;
        return (actualHead->data);
    }

    T back() 
    {
        Node* actualTail = tail->prev;
        return (actualTail->data);
    }

    void traverse(std::function<void (T &data)> doIt)
    {
        Node* current = head->next;
        while (current != tail) {
            doIt(current->data);
            current = current->next;
        }
    }

};

