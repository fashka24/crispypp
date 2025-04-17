# Library Name

A brief description of your library and its purpose. For example: "A multi-purpose C++ library for working with network protocols, file operations, and mathematical computations."

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
git clone https://github.com/your_username/your_repository.git
cd your_repository
```
2. You can compile library to one file:
```bash
cpp crispypp/all.hpp -o crispypp.hpp
```
3. Or you can move/copy folder crispypp/ to your project

## Examples

All examples you can see in folder example/

### example/smartfile.hpp
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
### example/bananalogger.hpp
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