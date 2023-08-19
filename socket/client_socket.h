#pragma once

#include <string>

class ClientSocket {
public:
    ClientSocket();
    ClientSocket(int fd);
    ~ClientSocket();

    void Connect(const std::string& host, int port);

    void Send(const std::string& data);
    std::string Receive();

private:
    int sockfd;
};
