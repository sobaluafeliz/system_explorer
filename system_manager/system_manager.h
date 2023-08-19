#pragma once

#include <string>
#include <vector>

#include "address.h"

class SystemManager {
public:
    std::string Explore(const std::vector<Address>& addresses);
};
