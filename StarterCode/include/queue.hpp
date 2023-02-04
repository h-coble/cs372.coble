#pragma once
#include "List.hpp"
template <typename  T>
class Queue
{
private:
	List<T> qList;
public:
	Queue() {}
	Queue(Queue& rhQ) {}
	~Queue() {}

	bool empty(){ return qList.empty(); }
	void push(T data) { qList.push_back(data);}
	void pop() { qList.pop_front(); }
	T front() { return qList.front(); }
	T back() { return qList.back(); }
	int size() { return qList.getSize(); }
	void traverse(void (*doIt)(T& data))
	{
		qList.traverse(doIt);
	}
};