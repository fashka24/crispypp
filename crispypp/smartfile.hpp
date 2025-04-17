//
// Created by z1w2 on 17.04.2025.
//

#ifndef SMART_FILE_HPP
#define SMART_FILE_HPP

#include <string>
#include <fstream>
#include <sstream>

#include "addexceptions.hpp"

namespace crs {
    inline std::string
#ifdef _WIN32
    os_name = "nt";
#elif _POSIX
    os_name = "posix";
#else
    os_name = "other";
#endif

    class smartfile {
    public:
        explicit smartfile(const std::string& path): path(path) {}
        void write(const std::string &_text) {
            this->de_file.open(this->path, std::ios_base::out);

            if (!this->de_file.is_open()) {
                throw NotFoundFileException(this->path);
            }

            this->de_file << _text;
            this->de_file.close();
        }
        void addwrite(const std::string &_text) {
            this->de_file.open(this->path, std::ios_base::app);

            if (!this->de_file.is_open()) {
                throw NotFoundFileException(this->path);
            }

            this->de_file << _text;
            this->de_file.close();
        }
        std::string read() {
            this->de_file.open(this->path, std::ios_base::in);

            std::string _result;
            {
                std::stringstream _buf;
                if (this->de_file.is_open()) {
                    _buf << this->de_file.rdbuf();
                }
                else {
                    throw NotFoundFileException(this->path);
                    return "";
                }
                _result = _buf.str();
            }

            this->de_file.close();

            return _result;
        }
        void clear() {
            write("");
        }
        int size() {
            std::fstream file(this->path, std::ios::in | std::ios::binary);

            if (!file.is_open()) {
                throw NotFoundFileException(this->path);
            }

            file.seekg(0, std::ios::end);
            const int _size = static_cast<int>(file.tellg());
            file.seekg(0, std::ios::beg);

            return _size;
        }
        void operator<<(const std::string& _text) {
            write(_text);
        }
        void operator>>(std::string& _text) {
            _text = read();
        }
    private:
        std::fstream de_file;
        std::string path;
    };
}


#endif //SMART_FILE_HPP
