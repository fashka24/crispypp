//
// Created by z1w2 on 18.04.2025.
//

#ifndef CTYPES_HPP
#define CTYPES_HPP

#include <string>
#include <vector>
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

class c_statement {
public:
    virtual std::string build() noexcept = 0;
};

class c_type : public c_statement {
public:
    std::string type_name;
    bool is_const = false;
    bool is_ptr = false;

    c_type() = default;

    std::string build() noexcept override {
        stringbuilder builder;

        if (is_const)
            builder.concat("const");
        builder.concat(type_name);
        if (is_ptr)
            builder.concat("*");

        return builder.build();
    }
};

class c_variable : public c_statement {
public:
    c_type* type = nullptr;
    std::string var_name;
    std::string var_value;

    c_variable() = default;

    std::string build() noexcept override {
        stringbuilder builder;

        builder
            .concat(type->build())
            ->concat(var_name)
            ->concat("=")
            ->concat(var_value)
            ->concat(";");

        return builder.build();
    }
};

class c_parameter : public c_statement {
public:
    c_type* type = nullptr;
    std::string var_name;

    c_parameter() = default;

    std::string build() noexcept override {
        stringbuilder builder;

        builder
            .concat(type->build())
            ->concat(var_name);

        return builder.build();
    }
};

class c_function : public c_statement {
public:
    c_type* return_type_name = nullptr;
    std::string func_name;
    std::vector<c_parameter> parameters;
    std::vector<c_statement*> statements;

    c_function() = default;

    std::string build() noexcept override {
        stringbuilder builder;

        builder
            .concat(return_type_name->build())
            ->concat(func_name)
            ->concat("(");

        for (size_t j = 0; j < parameters.size(); j++) {
            builder.concat(parameters[j].build());
            if (j != parameters.size() - 1) {
                builder.concat(", ");
            }
        }

        builder
            .concat(") {\n");

        for (auto stat : statements) {
            builder
                .concat(stat->build())
                ->concat("\n");
        }

        builder.concat("}");

        return builder.build();
    }
};

} // namespace crs

#endif // CTYPES_HPP

