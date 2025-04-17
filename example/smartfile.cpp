#include <iostream>
#include "../crispypp/smartfile.hpp"

int main() {
    crs::smartfile my_file("some_text.txt");

    my_file.clear();
    my_file.addwrite("This is some_text.txt file, ");
    my_file.addwrite("And this is too\n");

    std::cout << "Source: " << my_file.read()
    << "Size: " << my_file.size() << "\n"
    << "Sizeof my_file: " << sizeof(my_file) << "\n";
}