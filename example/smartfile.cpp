#include <iostream>
#include "../crispypp/smartfile.hpp"

int main() {
     // create smartfile exampler
    crs::smartfile my_file("some_text.txt");

    // clearing
    my_file.clear();
    // additional text writing
    my_file.addwrite("This is some_text.txt file, ");
    my_file.addwrite("And this is too\n");

    // getting info
    std::cout << "Source: " << my_file.read()
    << "Size: " << my_file.size() << "\n"
    << "Sizeof my_file: " << sizeof(my_file) << "\n";
}