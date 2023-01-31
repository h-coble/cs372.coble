#pragma once
#include<iostream>
template <typename T>
class Vector
{
public:
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

	Vector()
	{
		arr = new T[1];
		vCapacity = 1;
		length = 0;
	}

	~Vector()
	{
		delete[] arr;
		arr = nullptr;
	};

	Vector(Vector& obj)
	{
		this->arr = new T[obj.capacity()];
		for (int i = 0; i < obj.size(); i++)
		{
			this->put(obj.at(i),i);
		}
	}
	void put(T data, int index)
	{
		if (index == vCapacity)
			push_back(data);
		else
			arr[index] = data;
	}

	void expand(int newCapacity)
	{
		if (newCapacity > vCapacity)
		{
			T* temp = new T[newCapacity];
			for (int i = 0; i < length; i++)
				temp[i] = arr[i];
			delete[] arr;
			vCapacity = newCapacity;
			arr = temp;
		}
		else
		{
			std::cerr << "Vector::expand: the new capacity is less or equal to the current capacity\n";
		}
	}
	void shrink()
	{
			T* temp = new T[vCapacity -1];
			for (int i = 0; i < length - 1; i++)
				temp[i] = arr[i];
			delete[] arr;
			vCapacity -= 1;
			length -= 1;
			arr = temp;
			/*for (int i = 0i < length-1; i++)
			{
				if (i < index)
					temp[i] = arr[i];
				else
					temp[i] = arr[i + 1];
			}
			delete[] arr;
			vCapacity -= 1;
			length -= 1;
			arr = temp;*/
	}

	void push_back(T data)
	{
		if (length == vCapacity)
			expand(2 * vCapacity);
		arr[length] = data;
		length++;
	}
	
	T &at(int index)
	{
		if (index < 0 || index > length)
		{
			std::cerr << "Vector: Index out of bounds" << std::endl;
			exit(1);
		}
		else
			return arr[index];
	}
	T& at(iterator pos)
	{
		return *pos;
	}
	T& at(const_iterator pos)
	{
		return *pos;
	}

	int size()
	{
		return length;
	}
	int capacity()
	{
		return vCapacity;
	}
	void traverse()
	{
		for (int i = 0; i < length; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}

	Vector& operator=( Vector& source)
	{
		if (this == &source)
		{
			return *this;
		}

		delete[] arr;
		arr = new T[1];

		vCapacity = 1;
		length = 0;
		for (int i = 0; i < source.size(); i++)
		{
			push_back(source.at(i));
		}
		return *this;
	}

	iterator begin() { return &arr[0]; }
	iterator end() { return &arr[length]; }
	iterator rbegin(){ return &arr[length-1]; }
	iterator rend() { return &arr[-1]; }

	const_iterator cbegin() { return &arr[0]; }
	const_iterator cend() { return &arr[length]; }
	const_iterator crbegin() { return &arr[length - 1]; }
	const_iterator crend() { return &arr[-1]; }

	iterator insert(iterator pos, const T& data)
	{
		int index = length-1;
		auto iter = rbegin();
		for (iter; iter != pos; --iter)
		{
			if (iter == rbegin())
			{
				push_back(arr[length-1]);
			}
				arr[index] = arr[index-1];
			index--;
		}		
		arr[index] = data;

		//Return doesn't work properly, but insert functions well
		//=========================================================
		auto iterReturn = begin();
		for (int i = 0; i < index; i++)
			++iterReturn;
		return --iterReturn;
		//iterator must be reset outside of member function to work
		//=========================================================
	}
private:
	T* arr = new T[1];
	int vCapacity = 1;
	int length = 1;
};
