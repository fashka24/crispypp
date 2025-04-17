//
// Created by z1w2 on 17.04.2025.
//

#ifndef BANANALOGGER_HPP
#define BANANALOGGER_HPP

#include <string>
#include <iostream>
#include "smartfile.hpp"

namespace crs {
    class bananalogger {
    public:
        explicit bananalogger(const std::string& path, const std::string& worker = "BananaLogger"): path(path), worker(worker) {}
        explicit bananalogger(): path("bananalog.txt"), worker("BananaLogger") {}

        void quietlog(const std::string& _text) {
            smartfile _file(this->path);

            _file.addwrite("[" + this->worker + "] " + _text + "\n");
        }
        void log(const std::string& _text) {
            smartfile _file(this->path);

            std::cout << "[" << this->worker << "] " << _text << "\n";
            _file.addwrite("[" + this->worker + "] " + _text + "\n");
        }
        void clearlogs() {
            smartfile _file(this->path);

            _file.clear();
        }
    private:
        std::string path, worker;
    };
}

#endif //BANANALOGGER_HPP
