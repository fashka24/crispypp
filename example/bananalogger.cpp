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