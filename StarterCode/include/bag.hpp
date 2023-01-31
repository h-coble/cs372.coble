#pragma once
#include<iostream>
#include "vector.hpp"

template <typename Thing>
class Bag 
{
private:
	Vector<Thing> bagVec;
	int bagSize = 0;
public:
	Bag()
	{
		//Vector<Thing> bagVec;
		bagSize = 0;
	}

	class const_iterator {
	protected:
		T* current;
		T& retrieve() const { return *current; }
		const_iterator(T* arr) : current(arr) { }
		friend class Vector<T>;
	public:
		const_iterator() : current(nullptr) { }

		T& operator *() const
		{
			return retrieve();
		}

		const_iterator& operator++()
		{
			current++;
			return *this;
		}
		const_iterator& operator--()
		{
			current--;
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
		iterator(T* arr) : const_iterator(arr) {}
		friend class Vector<T>;
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
			current++;
			return *this;
		}
		iterator& operator--()
		{
			current--;
			return *this;
		}

		iterator operator++ (int)
		{
			iterator old = *this;
			**(*this);
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
	iterator begin() { return &bagVec.arr[0]; }
	iterator end() { return &bagVec.arr[length]; }
	iterator rbegin() { return &bagVec.arr[length - 1]; }
	iterator rend() { return &bagVec.arr[-1]; }

	const_iterator cbegin() { return &bagVec.arr[0]; }
	const_iterator cend() { return &bagVec.arr[length]; }
	const_iterator crbegin() { return &bagVec.arr[length - 1]; }
	const_iterator crend() { return &bagVec.arr[-1]; }
	void insert(Thing item)
	{
		bagVec.push_back(item);
		bagSize++;		
	}
	Thing pop()
	{
		Thing item;
		if (bagVec.size() > 0)
		{
			item = bagVec.at(bagSize - 1);
			return item;
			//item = last item in vector
		}
		else
			std::cerr << "Bag is empty and cannot pop an item" << std::endl;
		return bagSize;
	}
	int size()
	{
		return bagSize;
	}
	int count(Thing item)
	{
		int itemCount = 0;
		for (int i = 0; i < bagSize; i++)
		{
			if (bagVec.at(i) == item)
				itemCount++;
		}
		return itemCount;
	}

};