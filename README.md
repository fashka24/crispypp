# Crispy++

A multi-purpose C++ library for working with network protocols, file operations, and mathematical computations.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Examples](#examples)

## Features

- Smart workers with files and strings
- Support for various network protocols (soon)
- Mathematical functions and algorithms
- Portability and cross-platform compatibility

## Installation

1. Clone the repository:
```bash
git clone https://github.com/fashka24/crispypp.git
cd crispypp
```
2. You can compile library to one file:
```bash
cpp crispypp/all.hpp -o crispypp.hpp
```
3. Or you can move/copy folder crispypp/ to your project

## Examples

All examples you can see in folder example/

### example/smartfile.cpp
```c++
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
```
### example/bananalogger.cpp
```c++
#include <iostream>
#include "../crispypp/bananalogger.hpp"

int main() {
    // "my_logger" -> "[my_logger] ..."
    crs::bananalogger my_logger("banana-logs.txt", "my_logger");

    // clearing all logs
    my_logger.clearlogs();

    my_logger.log("This is my first log!");
    // quiet log NOT print text to stdout
    my_logger.quietlog("This is quiet... log...!");
}
```
### example/smartstring.cpp
```c++
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
```
### example/ctypes.cpp
```c++
#include <iostream>
#include "../crispypp/ctypes.hpp"

int main() {
    auto my_function = new crs::c_function();
    auto func_ret_type = new crs::c_type();
    auto var1_type = new crs::c_type();
    auto var1 = new crs::c_variable();

    func_ret_type->type_name = C_TYPE_VOID;
    var1_type->is_const = true;
    var1_type->type_name = C_TYPE_INT;

    my_function->return_type_name = func_ret_type;
    my_function->func_name = "my_function";
    var1->type = var1_type;
    var1->var_name = "var1";
    var1->var_value = "123";

    my_function->statements.push_back(var1);

    std::cout << my_function->build();

    // Clean up dynamically allocated memory
    delete my_function;
    delete func_ret_type;
    delete var1_type;
    delete var1;

    return 0;
}

```