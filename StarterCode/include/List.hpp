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
        const_iterator& operator--()
        {
            current = current->prev;
            return *this;
        }
        const_iterator operator++(int)
        {
            const_iterator old = *this;
            ++(*this);
            return old;
        }
        const_iterator operator--(int)
        {
            const_iterator old = *this;
            --(*this);
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
        iterator& operator--()
        {
            this->current = const_iterator::current->prev;
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
    //CONSTRUCTORS=&=DESTRUCTORS==============================
    List() : head(nullptr), tail(nullptr) {}

    List(T newData) {
        setupList();
        head->data = newData;
    }
    List(List& rhs) { 
        deleteListContents();
        head = rhs.head;
        tail = rhs.tail;
    }
    ~List() {
        deleteListContents();
    }
    //=========================================================

    bool  empty() {
        return (head == nullptr);
    }
    void push_front(T data) {
        Node* newNode = new Node();
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
        }
    }
    void push_back(T data) {
        Node* newNode = new Node();
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
        }
    }
    void pop_back() {
        Node* lastNode = tail;
        if (lastNode != nullptr) {
            tail = tail->prev;
            tail->next = nullptr;
            delete lastNode;
        }
    }
    T front() {
        if (!empty()) {
            return head->data;
        }
        else {
            // This is drastic, and should be handled using an exception handler
            std::cout << "Exception: list is empty." << std::endl;
            exit(1);
        }
    }
    T back() {
        if (!empty()) {
            return tail->data;
        }
        else {
            // This is drastic, and should be handled using an exception handler
            std::cout << "Exception: list is empty." << std::endl;
            exit(1);
        }
    }

    void traverse(void (*doIt)(T& data)) {
        Node* current = head;
        while (current != nullptr) {
            doIt(current->data);
            current = current->next;
        }
    }


    //Q3====================================================
    iterator insert(iterator pos, const T& data)
    {
        Node* newNode = pos.current;

        return { newNode->prev = newNode->prev->next = new Node{ data, newNode->prev, newNode } };
    }

    iterator erase(iterator pos)
    {
        Node* newNode = pos.current;
        iterator afterDel{ newNode->next };
        newNode->prev->next = newNode->next;
        newNode->next->prev = newNode->prev;
        delete newNode;

        return afterDel;
    }

    iterator erase(iterator from, iterator to)
    {
        for (iterator itr = from; itr != to; )
            itr = erase(itr);
        return to;
    }
    //=======================================================

    //Q2=====================================================
    iterator begin() { return head; }
    iterator end() { return tail->next; }
    const_iterator cbegin() const
  {
        return { head };
  }
    const_iterator cend() const
  {
      return {tail->next};
  }

    iterator rbegin() { return tail; }
    iterator rend() { return head->prev; }
    const_iterator crbegin() const
  {
      return tail;  //tail->prev?
  }
    const_iterator crend() const
  {
      return { head->prev};
  }
    //========================================================
};




