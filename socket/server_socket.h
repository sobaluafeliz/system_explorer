#pragma once

#include <string>
#include "client_socket.h"

class ServerSocket {
public:
    ServerSocket(const std::string& host, int port);
    ~ServerSocket();

    ClientSocket Accept();

private:
    int sockfd;
};
