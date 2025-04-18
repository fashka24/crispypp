//
// Created by z1w2 on 18.04.2025.
//

#ifndef SMARTSTRING_HPP
#define SMARTSTRING_HPP

#include <algorithm>
#include <string>
#include <vector>

namespace crs {
    inline std::string toString(int x) { return std::to_string(x); }
    inline std::string toString(float x) { return std::to_string(x); }
    inline std::string toString(double x) { return std::to_string(x); }
    inline std::string toString(char x) {
        std::string s{x};
        return s;
    }
    inline std::string toString(std::string x) { return x; }

    class smartstring {
    public:
        explicit smartstring(const std::string &str)
            : str_(str) {}
        explicit smartstring() {}

        std::vector<std::string> split(const std::string& delimiter) {
            std::vector<std::string> tokens;
            size_t pos = 0;
            std::string token;
            std::string tempStr = str_;

            while ((pos = tempStr.find(delimiter)) != std::string::npos) {
                token = tempStr.substr(0, pos);
                tokens.push_back(token);
                tempStr.erase(0, pos + delimiter.length());
            }
            tokens.push_back(tempStr);

            return tokens;
        }
        const char* c_str() {
            return this->str_.c_str();
        }
        void ltrim() {
            str_.erase(str_.begin(), std::find_if(str_.begin(), str_.end(), [](unsigned char ch) {
                return !std::isspace(ch);
            }));
        }
        void rtrim() {
            str_.erase(std::find_if(str_.rbegin(), str_.rend(), [](unsigned char ch) {
                return !std::isspace(ch);
            }).base(), str_.end());
        }
        void trim() {
            ltrim();
            rtrim();
        }
        operator const char*() {
            return c_str();
        }
        std::string str() {
            return str_;
        }
        std::string operator+(std::string s) {
            return str_ + s;
        }
        std::string operator+(smartstring s) {
            return s.str();
        }
        std::string operator*(int x) {
            std::string s_;

            for (int i = 0; i < x; ++i) {
                s_ += this->str_;
            }

            return s_;
        }



    private:
        std::string str_;
    };

    inline std::string toString(smartstring x) { return x.str(); }
    template <typename T_>
    inline std::string toString(std::vector<T_> x) {
        std::string result = "{";
        for (auto& cc_ : x) {
            if (cc_ != x[x.size() - 1]) result += toString(cc_) + ", ";
            else result += toString(cc_);
        }
        result += "}";

        return result;
    }

    class stringbuilder {
    public:
        explicit stringbuilder(): delimiter(' ') {}
        explicit stringbuilder(char delimiter): delimiter(delimiter) {}

        stringbuilder* concat(std::string s) {
            this->str_ += s + delimiter;
            return this;
        }
        std::string build() {
            this->str_.pop_back();
            return this->str_;
        }
    private:
        std::string str_;
        char delimiter;
    };
}
#endif //SMARTSTRING_HPP
