#include "system_manager.h"
#include <socket/client_socket.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::string SystemManager::Explore(const std::vector<Address>& addresses) {
    json response;
    for (const auto& address : addresses) {
        ClientSocket system;
        system.Connect(address.host, address.port);

        response.push_back(json::parse(system.Receive()));
    }

    return response.dump();
}
