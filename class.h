#pragma once

#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

template <class T>
class Vector
{
private:
	size_t _size = 0;
	size_t _capacity = 0;
	T* _vector = nullptr;
	

private:

	void clear()
	{
		this->_size = 0;
		this->_capacity = 0;
		delete[] this->_vector;
		this->_vector = nullptr;
	}

	void resize()
	{
		this->_capacity = std::max(this->_capacity*2,this->_size+1);
		T* temp_vector = new T[this->_capacity]{};
		for (size_t i = 0; i < this->_size; i++)
		{
			temp_vector[i] = this->_vector[i];
		}

		delete[] this->_vector;
		this->_vector = temp_vector;
	}

public:
	Vector() = default;

	Vector(size_t Capacity)
	{
		this->_capacity = Capacity;
		this->_vector = new T[this->_capacity]{};
	}

	Vector(const Vector& copy)
	{
		this->_capacity = copy._capacity;
		this->_size = copy._size;

		this->_vector = new T[this->_capacity]{};
		for (size_t i = 0; i < copy._size; i++)
		{
			this->_vector[i] = copy._vector[i];
		}
	}

	~Vector()
	{ 
		clear();
	}

	int Get_Size() const
	{
		return this->_size;
	}

	void push_back(const T& value)
	{
		if (this->_size >= this->_capacity)
			resize();

		this->_vector[this->_size++] = value;

	}

	T& operator[](const unsigned int index)
	{
		if (index >= this->_size)
		{
			throw std::invalid_argument("index is out of bounds");
		}

		return this->_vector[index];
	}

	const T& operator[](const size_t index) const
	{
		if (index >= this->_size)
		{
			throw std::invalid_argument("index is out of bounds");
		}

		return this->_vector[index];
	}

	void insert(T& value, const int index)
	{
		while (this->_size >= this->_capacity)
			resize();

		this->_vector[index] = value;
		this->_size = std::max(this->_size, index + 1);
	}

	istream& operator >> (istream& str)
	{
		while(this->_size < this->_capacity)
		{
			T temp;
			str >> temp;
			this->_vector[_size++] = temp;
		}
		return str;
	}

	ostream& operator <<(ostream& str)
	{
		int temp = 0;
		while (temp < this->_size)
		{
			str << this->_vector[temp] << " ";
			temp++;
		}
		 return str;
	}

	void set_size(int newsize) {
		while (newsize <  this->_capacity) {
			resize();
		}
		this->_size = newsize;
	}
};

template <class T>

void Random(Vector<T>& obj)
{
	srand(time(NULL));
	int temp = obj._capacity - obj._size;

	for (size_t i = 0; i < temp; i++)
	{
		obj.push_back(rand() % 100);
	}
}


template <class T>
void Random(Vector<T>& obj, const int size)
{
	srand(time(NULL));
	
	for (size_t i = 0; i < size; i++)
	{
		obj.push_back(rand() % 100);
	}
}