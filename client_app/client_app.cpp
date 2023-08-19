#include <iostream>
#include <nlohmann/json.hpp>
#include <socket/client_socket.h>

using json = nlohmann::json;

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cout << "Please run program as follows: client_app <server_host> <server_port>" << std::endl;
        return -1;
    }

    std::string host(argv[1]);
    std::string port(argv[2]);

    ClientSocket c;
    c.Connect(host, std::stoi(port));

    json response = json::parse(c.Receive());
    for (auto item : response) {
        std::cout << item["name"] << ": " << item["status"] << std::endl;
    }
}