#include <iostream>
#include <string>
#include "iter.hpp"

// ------------------------------------------------------------------------ //
// class Awesome
// {
//     public:
//     Awesome(void): _n(42) {return;}
//     int get(void) const {return this->_n;}
    
//     private:
//     int _n;
// };

// std::ostream &operator << (std::ostream &o, Awesome const &rhs) {o << rhs.get(); return o;}

// template<typename T>
// void print(T const &x) {std::cout << x<< std::endl; return; }

// int main(){
//     int tab[] ={0,1,2,3,4};
//     Awesome tab2[5];

//     iter(tab, 5, print);
//     iter(tab2, 5, print);

//     return 0;
// }

//---------------------------------------------------------------------------------

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
    iter(strArray, 3, print); // Only print, no increment for strings

    return 0;
}
