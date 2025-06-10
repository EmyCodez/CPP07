#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <class T>
class Array {
private:
    T* _elements;
    unsigned int _size;

public:
    
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();
    
    // Subscript operator
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    // Member functions
    unsigned int size() const;

    // Exception class
    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Index out of bounds";
        }
    };
};

#include "Array.tpp"

#endif