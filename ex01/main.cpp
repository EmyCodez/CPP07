#include <iostream>
#include <string>
#include "iter.hpp"

// Print function (const reference)
template <typename T>
void print(T const& value) {
    std::cout << value << std::endl;
}

// Increment function (non-const reference, templated)
template <typename T>
void increment(T& value) {
    ++value;
}

int main() {
    std::cout << "=== Integer array ===" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};

    std::cout << "Before increment:" << std::endl;
    iter(intArray, 5, print);

    iter(intArray, 5, increment);

    std::cout << "After increment:" << std::endl;
    iter(intArray, 5, print);

    std::cout << "\n=== Float array ===" << std::endl;
    float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f};

    std::cout << "Before increment:" << std::endl;
    iter(floatArray, 4, print);

    iter(floatArray, 4, increment);

    std::cout << "After increment:" << std::endl;
    iter(floatArray, 4, print);

    std::cout << "\n=== String array ===" << std::endl;
    std::string strArray[] = {"apple", "banana", "cherry"};
    iter(strArray, 3, print);

    return 0;
}
