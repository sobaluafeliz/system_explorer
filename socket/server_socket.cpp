#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdexcept>
#include "server_socket.h"

ServerSocket::ServerSocket(const std::string& host, int port) {
    sockfd = socket(AF_INET,SOCK_STREAM, 0);

    int value = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &value, sizeof(int));

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    inet_aton(host.c_str(), &addr.sin_addr);
    addr.sin_port = port;

    int bind_result = bind(sockfd, (struct sockaddr*) &addr, sizeof(addr));
    if (bind_result != 0) {
        throw std::runtime_error("failed to bind");
    }

    listen(sockfd, 0);
}

ServerSocket::~ServerSocket() {
    close(sockfd);
}

ClientSocket ServerSocket::Accept() {
    int clientfd = accept(sockfd, NULL, NULL);
    return ClientSocket(clientfd);
}
