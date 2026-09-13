#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array {
private:
	T*           _elements;
	unsigned int _size;

public:
	// default constructor: creates empty array
	Array() : _elements(nullptr), _size(0) {}

	// parameterized constructor: allocates n elements
	// the () in new T[n]() forces default initialization for primitive types.
	Array(unsigned int n) : _elements(new T[n]()), _size(n) {}

	// copy constructor: Deep copy
	Array(const Array& other) : _elements(new T[other._size]()), _size(other._size) {
		for (unsigned int i = 0; i < _size; ++i) {
			_elements[i] = other._elements[i];
		}
	}

	// assignment operator: Deep copy with self-assignment guard
	Array& operator=(const Array& rhs) {
		if (this != &rhs) 
        {
			delete[] _elements; // Free existing memory first
			_size = rhs._size;
			_elements = new T[_size]();
			for (unsigned int i = 0; i < _size; ++i) {
				_elements[i] = rhs._elements[i];
			}
		}
		return *this;
	}

	// destructor
	~Array() {
		delete[] _elements;
	}

	//subscript operator for modifying elements
	T& operator[](unsigned int index) {
		if (index >= _size)
			throw OutOfBoundsException();
		return _elements[index];
	}

	// subscript operator for read-only access on const objects
	const T& operator[](unsigned int index) const {
		if (index >= _size)
			throw OutOfBoundsException();
		return _elements[index];
	}

	// size function: must not modify instance (const)
	unsigned int size() const {
		return _size;
	}

	// custom exception class for out of bounds
	class OutOfBoundsException : public std::exception {
	public:
		virtual const char* what() const noexcept {
			return "Index is out of bounds";
		}
	};
};

#endif