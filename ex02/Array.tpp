#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

// Default constructor
template <class T>
Array<T>::Array() : _elements(NULL), _size(0) {}

// Constructor with size
template <class T>
Array<T>::Array(unsigned int n) : _elements(new T[n]()), _size(n) {}

// Copy constructor
template <class T>
Array<T>::Array(const Array& other) : _elements(new T[other._size]()), _size(other._size) {
    for (unsigned int i = 0; i < _size; i++) {
        _elements[i] = other._elements[i];
    }
}

// Assignment operator
template <class T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        delete[] _elements;
        _size = other._size;
        _elements = new T[_size]();
        for (unsigned int i = 0; i < _size; i++) {
            _elements[i] = other._elements[i];
        }
    }
    return *this;
}

// Destructor
template <class T>
Array<T>::~Array() {
    delete[] _elements;
}

// Subscript operator
template <class T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size) {
        throw OutOfBoundsException();
    }
    return _elements[index];
}

template <class T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size) {
        throw OutOfBoundsException();
    }
    return _elements[index];
}

// Size function
template <class T>
unsigned int Array<T>::size() const {
    return _size;
}

#endif