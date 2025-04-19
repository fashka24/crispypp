//
// Created by z1w2 on 17.04.2025.
//

#ifndef ADDEXCEPTIONS_HPP
#define ADDEXCEPTIONS_HPP

#include <stdexcept>
#include <string>

namespace crs {
    class UnknownParameterException: public std::exception {
    public:
        explicit UnknownParameterException(const std::string &message): message(message) {}
        [[nodiscard]] const char* what() const noexcept override { return this->message.c_str(); }
    private: const std::string message;
    };
    class InitiliazationException: public std::exception {
    public:
        explicit InitiliazationException(const std::string &filepath): filepath(filepath) {}
        [[nodiscard]] const char* what() const noexcept override { return ("Not found file " + filepath).c_str(); }
    private: const std::string filepath;
    };
    class InitializationException: public std::exception {
    public:
        explicit InitializationException(const std::string &message): message(message) {}
        [[nodiscard]] const char* what() const noexcept override { return this->message.c_str(); }
    private: const std::string message;
    };
    class CreatingException: public std::exception {
    public:
        explicit CreatingException(const std::string &message): message(message) {}
        [[nodiscard]] const char* what() const noexcept override { return this->message.c_str(); }
    private: const std::string message;
    };
    class SocketException: public std::exception {
    public:
        explicit SocketException(const std::string &message): message(message) {}
        [[nodiscard]] const char* what() const noexcept override { return this->message.c_str(); }
    private: const std::string message;
    };
}

#endif //ADDEXCEPTIONS_HPP
