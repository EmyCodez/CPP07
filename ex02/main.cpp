#include <iostream>
#include "Array.hpp"

int main() {
    try {
        Array<int> empty;
        std::cout << "Empty array size: " << empty.size() << std::endl;

        Array<int> numbers(5);
        for (unsigned int i = 0; i < numbers.size(); ++i)
            numbers[i] = i * 10;

        std::cout << "Numbers array: ";
        for (unsigned int i = 0; i < numbers.size(); ++i)
            std::cout << numbers[i] << " ";
        std::cout << std::endl;

        // Test copy constructor
        Array<int> copy = numbers;
        numbers[0] = 100;
        std::cout << "Original[0] = " << numbers[0] << ", Copy[0] = " << copy[0] << std::endl;

        // Test out of bounds
        std::cout << "Accessing out of bounds..." << std::endl;
        std::cout << numbers[10] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
