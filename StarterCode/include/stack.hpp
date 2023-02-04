#pragma once
#include "List.hpp"
template <typename  T>
class Stack
{
private:
	List<T> stackList;
public:
	Stack() {}
	Stack(Stack& rhQ) {}
	~Stack() {}

	bool empty(){ return stackList.empty(); }
	void push(T data) { stackList.push_back(data);}
	void pop() { stackList.pop_back(); }
	T top() { return stackList.back(); }
	void traverse(void (*doIt)(T& data))
	{
		stackList.traverse(doIt);
	}
};