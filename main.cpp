#include <iostream>
#include "crispypp/ctypes.hpp"

int main() {
     crs::c_variable my_var;

     my_var.is_const  = true;
     my_var.is_ptr    = true;
     my_var.type_name = C_TYPE_DOUBLE;
     my_var.var_name  = "my_var";
     my_var.var_value = "12.7";

     std::cout
     << crs::build_c_var(my_var) // const double * my_var = 12.7;
     << "\n";
     /*
     * This is file for testing new functions in library
     *
     * You can compile all files to one:
     *   cpp crispypp/all.hpp -o crispypp.hpp
     */
}