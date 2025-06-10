#include <iostream>
#include "Array.hpp"

int main() {
    try {
        // Test default constructor
        Array<int> empty;
        std::cout << "Empty array size: " << empty.size() << std::endl;

        // Test constructor with size
        Array<int> arr(5);
        std::cout << "Array size: " << arr.size() << std::endl;

        // Test element access and modification
        for (unsigned int i = 0; i < arr.size(); i++) {
            arr[i] = i * 2;
        }

        // Test copy constructor
        Array<int> copy(arr);
        copy[0] = 42; // Modify copy
        std::cout << "Original[0]: " << arr[0] << ", Copy[0]: " << copy[0] << std::endl;

        // Test assignment operator
        Array<int> assign;
        assign = arr;
        assign[1] = 99; // Modify assigned array
        std::cout << "Original[1]: " << arr[1] << ", Assigned[1]: " << assign[1] << std::endl;

        // Test out of bounds access
        std::cout << arr[10] << std::endl; // Should throw exception
    }
    catch (const Array<int>::OutOfBoundsException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Standard exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "Unknown exception caught" << std::endl;
    }

    // Test with different type
    try {
        Array<std::string> strArr(3);
        strArr[0] = "Hello";
        strArr[1] = "World";
        strArr[2] = "!";
        for (unsigned int i = 0; i < strArr.size(); i++) {
            std::cout << strArr[i] << " ";
        }
        std::cout << std::endl;
    }
    catch (const Array<std::string>::OutOfBoundsException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}