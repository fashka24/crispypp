#include <iostream>
#include "../crispypp/incodevm.hpp"

void my_print_for_vm(std::string text, crs::incodevm_program& program) {
    for (auto& c : text) {
        program.move(c, ICV_RI);
        program.syscall(ICV_PRINT_SYSCALL);
    }
}

int main() {
    crs::incodevm_program my_program;

    my_print_for_vm("This is incodevm print!!!\n", my_program);
}
