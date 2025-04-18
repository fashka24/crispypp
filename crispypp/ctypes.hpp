//
// Created by z1w2 on 18.04.2025.
//

#ifndef CTYPES_HPP
#define CTYPES_HPP
#include <string>
#include "smartstring.hpp"

namespace crs {
#define C_TYPE_VOID "void"
#define C_TYPE_INT "int"
#define C_TYPE_UINT "unsigned int"
#define C_TYPE_DOUBLE "double"
#define C_TYPE_LONG_DOUBLE "long double"
#define C_TYPE_LONG "long"
#define C_TYPE_U_LONG "unsigned long"
#define C_TYPE_LONG_LONG "long long"
#define C_TYPE_U_LONG_LONG "unsigned long long"
   struct c_variable {
      const char* type_name{};
      const char* var_name {};
      const char* var_value{};
      bool  is_const = false;
      bool  is_ptr = false;
   };

   inline std::string build_c_var(c_variable _var) {
      stringbuilder builder;

      // =const type ptr = value;

      if (_var.is_const)
         builder.concat("const");
      builder.concat(_var.type_name);
      if (_var.is_ptr)
         builder.concat("*");
      builder
         .concat(_var.var_name)
         ->concat("=")
         ->concat(_var.var_value)
         ->concat(";");

      return builder.build();
   }
}

#endif //CTYPES_HPP
