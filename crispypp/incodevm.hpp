//
// Created by z1w2 on 19.04.2025.
//

#ifndef INCODEVM_HPP
#define INCODEVM_HPP

// main register
#define ICV_RX 0
// register input
#define ICV_RI 1
// register buffer
#define ICV_RB 2
#define ICV_PRINT_SYSCALL 1
#define ICV_INPUT_SYSCALL 2
#include <iostream>

namespace crs {
    class incodevm_program {
    public:
        explicit incodevm_program() {
            registers = new int[registers_size];

            for (int i = 0; i < registers_size; ++i)
                registers[i] = 0;
        }

        void move(const int x, const int r) const {
            registers[r] = x;
        }
        void copy(const int x, const int r) const {
            registers[r] = registers[x];
        }
        void clear(const int r) const {
            registers[r] = 0;
        }
        void syscall(const int num) const {
            switch (num) {
                case ICV_PRINT_SYSCALL: {std::cout << static_cast<char>(registers[ICV_RI]); break;}
                case ICV_INPUT_SYSCALL: {
                    int _temp = 0;
                    std::cin >> _temp;
                    registers[ICV_RX] = _temp;
                    break;
                }
                default:
                    break;
            }
        }
    private:
        static constexpr int registers_size = 3;
        int* registers;
    };
}

#endif //INCODEVM_HPP
