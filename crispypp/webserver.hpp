//
// Created by z1w2 on 18.04.2025.
//

#ifndef WEBSERVER_HPP
#define WEBSERVER_HPP

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <functional>

#include "addexceptions.hpp"

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#else
#include <unistd.h>
#include <arpa/inet.h>
#endif

namespace crs {
    class httpconnection {
    public:
        explicit httpconnection(int socket) {}

        inline void send_message(const char* message, int flag) {
            send(socket, message, static_cast<int>(strlen(message)), flag);
        }
        inline void close_connection() {
            closesocket(socket);
        }
    private:
        int socket;
    };
    class webserver {
    public:
        int backlogs = 3;

        explicit webserver(int port) : port(port) {
#ifdef _WIN32
            WSADATA wsaData;
            if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
                throw InitializationException("Winsock initialization error");
            }
#endif

            server_fd = socket(AF_INET, SOCK_STREAM, 0);
            if (server_fd == -1) {
                throw CreatingException("Winsock creating error");
            }

            sockaddr_in address;
            address.sin_family = AF_INET;
            address.sin_addr.s_addr = INADDR_ANY;
            address.sin_port = htons(port);

            if (bind(server_fd, reinterpret_cast<struct sockaddr *>(&address), sizeof(address)) < 0) {
                throw SocketException("Bind socket error");
            }
        }
        void set_handler_on_message(std::function<void(httpconnection)> _handler) {
            _handler_on_message = _handler;
        }
        void run(std::function<std::string(int)> on_start_message = [](int x) {
            return "[SERVER] server run on port: " + std::to_string(x);
        }) {
            if (listen(server_fd, 3) < 0) {
                throw SocketException("Listen socket error");
            }

            std::cout << on_start_message(port) << std::endl;

            while (true) {
                int addrlen = sizeof(sockaddr_in);
                int new_socket = static_cast<int>(accept(server_fd, reinterpret_cast<struct sockaddr *>(&address), (socklen_t*)&addrlen));
                if (new_socket < 0) {
                    throw SocketException("Error accepting connection");
                    continue;
                }
                else if (new_socket >= 1){}
            }
        }

    private:
        int server_fd;
        int port;
        sockaddr_in address;
        std::function<void(httpconnection)> _handler_on_message;

        void handleRequest(int socket) {
            char buffer[1024] = {0};
            read(socket, buffer, sizeof(buffer));

            std::cout << "Получен запрос:\n" << buffer << std::endl;

            // Простой HTTP-ответ
            const char* response = "HTTP/1.1 200 OK\r\n"
                                   "Content-Type: text/plain\r\n"
                                   "Content-Length: 13\r\n"
                                   "Connection: close\r\n"
                                   "\r\n"
                                   "Hello, World!";
            send(socket, response, strlen(response), 0);
        }

        void close(int socket) {
#ifdef _WIN32
            closesocket(socket);
#else
            ::close(socket);
#endif
        }
    };
}

#endif //WEBSERVER_HPP
