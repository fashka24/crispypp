cmake_minimum_required(VERSION 3.30)
project(crispypp)

set(CMAKE_CXX_STANDARD 20)

add_executable(crispypp main.cpp
        crispypp/smartfile.hpp
        crispypp/addexceptions.hpp
        crispypp/bananalogger.hpp
        crispypp/all.hpp
        crispypp/smartstring.hpp
        crispypp/ctypes.hpp
        crispypp/webserver.hpp
        crispypp/htmlgen.hpp)
