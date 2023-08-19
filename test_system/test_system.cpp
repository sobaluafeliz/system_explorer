#include <iostream>
#include <chrono>
#include <random>
#include <cmath>
#include <socket/server_socket.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main(int argc, char** argv) {
    if (argc < 4) {
        std::cout << "Please run program as follows: test_system <name> <host> <port>" << std::endl;
        return -1;
    }

    std::string name(argv[1]);
    std::string host(argv[2]);
    std::string port(argv[3]);

    ServerSocket server(host, std::stoi(port));

    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);

    while (true) {
        auto c = server.Accept();

        auto rand_number = abs(static_cast<int64_t>(generator())) % 100;
        json system;
        system["name"] = name;
        system["status"] = (rand_number < 75 ?  "ok" : "bad");
        c.Send(system.dump());
    }
}
