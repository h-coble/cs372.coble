#pragma once
#include <iostream>
template <typename T>
class List
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

    //NESTED CLASSES==========================================
    class const_iterator {
    protected:
        Node* current;
        T& retrieve() const { return current->data; }
        const_iterator(Node* p) : current(p) { }
        friend class List <T>;
    public:
        const_iterator() : current(nullptr) { }

        T& operator *() const
        {
            return retrieve();
        }

        const_iterator& operator++()
        {
            current = current->next;
            return *this;
        }

        const_iterator operator++(int)
        {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const const_iterator& rhs) const
        {
            return current == rhs.current;
        }
        bool operator!=(const_iterator& rhs) const
        {
            return !(*this == rhs);
        }
    };
    class iterator : public const_iterator
    {
    protected:
        iterator(Node* p) : const_iterator(p) {}
        friend class List<T>;
    public:
        iterator() {}

        T& operator*()
        {
            return const_iterator::retrieve();
        }

        const T& operator*()const
        {
            return const_iterator::operator*();
        }

        iterator& operator++()
        {
            this->current = const_iterator::current->next;
            return *this;
        }

        iterator operator++ (int)
        {
            iterator old = *this;
            **(*this);
            return old;
        }
    };
    //========================================================


    //CONSTRUCTORS AND DESTRUCTOR=============================
    List()
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
    List(T newData) {
        setupList();
        head->data = newData;
    }
    List(List& rhs) { // copy constructor
        deleteListContents();
        head = rhs.head;
        tail = rhs.tail;
    }
    ~List() {
        deleteListContents();
    }
    //========================================================

    //GET=====================================================
    bool  empty()
    {
        return (head->next == tail);
    }
    T& front()
    {
        Node* actualHead = head->next;
        return (actualHead->data);
    }
    T back()
    {
        Node* actualTail = tail->prev;
        return (actualTail->data);
    }
    iterator begin() { return head->next; }
    iterator end() { return tail; }
    const_iterator cbegin() const
    {
        return head->next;
    }
    const_iterator cend() const
    {
        return { tail };
    }
    //========================================================

    //DO======================================================
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
            setupList();
            Node* actualHead = head->next;    //head-> next = nullptr
            actualHead->data = data;


            //actualHead = new Node?
            //head->data = data?
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
            setupList();
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

    //void traverse( std::function<void(T&)> doIt)
    void traverse(void (*doIt)(T& data))
    {
        Node* current = head->next;
        while (current != tail) {
            doIt(current->data);
            current = current->next;
        }
    }
    //========================================================

};

