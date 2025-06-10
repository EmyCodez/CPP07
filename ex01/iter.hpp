#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

// iter for non-const arrays and functions
template <typename T>
void iter(T* array, size_t length, void (*func)(T &)) {
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}

// iter for const arrays and functions taking
template <typename T>
void iter(T const* array, size_t length, void (*func)(T const&)) {
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}

#endif


