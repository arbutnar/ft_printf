#pragma once
#include <iostream>
#include <string>

template <typename T>
class Array {

	private:
		int size;
		T *elements;

	public:
		Array()
			: size (0), elements (NULL) {
			//std::cout << "default constructor called\n";
		}
		Array(unsigned int n)
			: size (n), elements (NULL) {
			std::cout << "one-arg constructor called\n";
			this->elements = new T[n];
			for (int i = 0; i < n; i++)
				elements[i] = 0;
		}
		Array<T>(const Array<T> &src)
		{
			std::cout << "copy constructor called\n";
			*this = src;
		}
		Array<T> &operator=(const Array<T> &src)
		{
			if (this == &src)
				return (*this);
			delete[] elements;
			this->size = src.size;
			this->elements = new T[this->size];
			for (int i = 0; i < this->size; i++)
				this->elements[i] = src.elements[i];
			return (*this);
		}
		T &operator[](int index)
		{
			if (elements[index] < 0)
				throw std::runtime_error("Element at index is nullptr");
			else if (index < 0 || index >= this->size)
				throw std::out_of_range("Index out of bounds");
			return (elements[index]);
		}
		~Array()
		{
			//std::cout << "deconstructor called\n";
			if (this->elements)
				delete[] elements;
		}

		int	getSize()
		{
			return (this->size);
		}
		void setElements(T value)
		{
			for (int i = 0; i < this->size; i++)
				elements[i] = value;
		}
		void displayElements()
		{
			for (int i = 0; i < this->size; i++)
				std::cout << elements[i] << " ";
			std::cout << std::endl;
		}
};

