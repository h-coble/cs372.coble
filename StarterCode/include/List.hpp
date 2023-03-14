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
        bool deleteState = 0;
    };
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
    int deletedNodes = 0;
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
            if (current!= nullptr)
                 delete current;
            current = temp;
        }
    }
public:
    int getSize() { return this->size; }
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
        size++;

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
        size++;
      
    }
    void pop_back() {
        Node* lastNode = tail;
        tail->deleteState = true;
        if (!empty())
        {
            if (head == tail)
            {
                
                head = nullptr;
                tail = nullptr;
            }
            else if (lastNode != nullptr) {

                tail = tail->prev;
                tail->next = nullptr;
                //delete lastNode
            }
            size--;

        }
        
        deletedNodes++;
        //delete lastNode;
        
    }
    void pop_front() {//same changes as pop_back
        Node* firstNode = head;
        head->deleteState = true;
        if (!empty())
        {
            if (head == tail)
            {
                head = nullptr;
                tail = nullptr;
            }

            else if (firstNode != nullptr) 
            {
                head = head->next;
                head->prev = nullptr;
                
            }
            size--;
      
        }
        

        deletedNodes++;
       
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
    T at(iterator pos)
    {
        Node* currentNode = pos.current;
        return currentNode->data;
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
        size++;

        return { newNode->prev = newNode->prev->next = new Node{ data, newNode->prev, newNode } };
        
    }

    iterator erase(iterator pos)
    {
        Node* newNode = pos.current;
        pos.current->deleteState = true
        iterator afterDel{ newNode->next };
        if (newNode != head)
            newNode->prev->next = newNode->next;
        else
            head = newNode->next;
        if (newNode != tail)
            newNode->next->prev = newNode->prev;
        else
            tail = newNode->prev;
        ;
        size--;

        deletedNodes++;
        return afterDel;        
    }

    iterator erase(iterator from, iterator to)
    {
        for (iterator itr = from; itr != to; )
            itr = erase(itr);
        return to;
    }

    iterator eraseLazy(iterator pos)
    {
        Node* newNode = pos.current;
        iterator afterDel = newNode->next;
        
        if (newNode->deleteState)
        {
            delete newNode;
            deletedNodes--;
        }
        
        return afterDel;

    }
    void freeLazy()
    {
        for (iterator itr = begin(); itr != end(); )
            itr = eraseLazy(itr);
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
        return { tail->next };
    }

    iterator rbegin() { return tail; }
    iterator rend() { return head->prev; }
    const_iterator crbegin() const
    {
        return tail;  //tail->prev?
    }
    const_iterator crend() const
    {
        return { head->prev };
    }
    //========================================================


    void displayNodeStats()
    {
        std::cout << "Active Nodes/Size: " << this->size << std::endl;
        std::cout << "Nodes to be deleted: " << this->deletedNodes << std::endl;
    }
};


//MIDTERM EXAM QUESTION ONE
template<typename T>
class SelfAdjustingList: public List<T>
{
public:
    T* find(T itemToFind)
    {
        T returnVal;
        bool foundFlag = 0;
        for (auto iter = this->begin(); iter != this->end(); ++iter)
        {
            if (this->at(iter) == itemToFind)
            {
                foundFlag = true;
                this->push_front(itemToFind);
                this->erase(iter);
                returnVal = this->front();
                return &returnVal;
            }
        }
        if (foundFlag)
        {
            std::cerr << "There is a logic error in the find method.\n";
        }
        else
        {
            std::cerr << itemToFind << " is not in this list.\n";
        }
        returnVal = this->front();
        return &returnVal;
    }
};




