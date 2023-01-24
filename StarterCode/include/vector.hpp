#pragma once
#include<iostream>



template <typename T>
class Vector
{
public:
	
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

private:
	T* arr = new T[1];
	int vCapacity = 1;
	int length = 1;
};
