#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <socket/server_socket.h>
#include <system_manager/system_manager.h>

int main(int argc, char** argv) {
    if (argc < 4) {
        std::cout << "Please run program as follows: server_app <host> <port> <path_to_addresses>" << std::endl;
        return -1;
    }

    std::string host(argv[1]);
    std::string port(argv[2]);
    std::string path_to_addresses(argv[3]);

    ServerSocket server(host, std::stoi(port));

    std::ifstream is(path_to_addresses);
    auto json = nlohmann::json::parse(is);

    std::vector<Address> addresses;
    for (auto item : json) {
        addresses.push_back({ item["ip"].get<std::string>(), item["port"].get<int>() });
    }

    SystemManager system_manager;

    while (true) {
        auto c = server.Accept();

        auto response = system_manager.Explore(addresses);
        c.Send(response);
    }
}
