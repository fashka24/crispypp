#include <iostream>
#include "../crispypp/smartstring.hpp"

int main() {
    crs::smartstring my_str("This is my string!");

    auto v = my_str.split(" ");


    std::cout << crs::toString(v) << "\n";
    std::cout << my_str + "2" << "\n";
    std::cout << my_str * 3 << "\n";
    std::cout << my_str << "\n";
}