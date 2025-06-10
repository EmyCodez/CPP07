#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception> 

template <class T>
class Array {
private:
    T* _array;
    unsigned int _size;

public:

    // Custom exception class
       class ArrayOutOfBoundsException : public std::exception {
        public:
            const char* what() const throw() {
                return "Array index out of bounds";
            }
        };

    // Default constructor
    Array() : _array(NULL), _size(0) {}

    // Constructor with size
    Array(unsigned int n) : _array(new T[n]()), _size(n) {}

    // Copy constructor
    Array(const Array& other) : _array(new T[other._size]), _size(other._size) {
        for (unsigned int i = 0; i < _size; ++i)
            _array[i] = other._array[i];
    }

    // Assignment operator
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _array;
            _size = other._size;
            _array = new T[_size];
            for (unsigned int i = 0; i < _size; ++i)
                _array[i] = other._array[i];
        }
        return *this;
    }

    // Destructor
    ~Array() {
        delete[] _array;
    }

    // Subscript operator
    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw ArrayOutOfBoundsException();
        }
        return _array[index];
    }

    // Const subscript operator
    const T& operator[](unsigned int index) const {
        if (index >= _size) {
            throw ArrayOutOfBoundsException();
        }
        return _array[index];
    }

    // Size function
    unsigned int size() const {
        return _size;
    }
};

#endif
