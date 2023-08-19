#include "client_socket.h"
#include <stdexcept>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

ClientSocket::ClientSocket() {
    sockfd = socket(AF_INET,SOCK_STREAM, 0);
}

ClientSocket::ClientSocket(int fd) {
    sockfd = fd;
}

ClientSocket::~ClientSocket() {
    close(sockfd);
}

void ClientSocket::Connect(const std::string& host, int port){
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    inet_aton(host.c_str(), &addr.sin_addr);
    addr.sin_port = port;

    int result = connect(sockfd, (struct sockaddr*) &addr, sizeof(addr));
    if (result != 0) {
        throw std::runtime_error("failed to connect");
    }
}

void ClientSocket::Send(const std::string& data){
    send(sockfd, data.c_str(), data.size(), 0);
}

std::string ClientSocket::Receive(){
    std::string response;
    const size_t N = 128;
    char buf[N];

    while (true) {
        int read = recv(sockfd, buf, N, 0);
        std::string tmp(buf, read);
        response += tmp;
        if (read < N) {
            break;
        }
    }
    return response;
}
