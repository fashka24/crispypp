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
