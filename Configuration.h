#ifndef SPACEINVADERS_CONFIGURATION_H
#define SPACEINVADERS_CONFIGURATION_H

#include "nlohmann/json.hpp"

using json = nlohmann::json;
class Configuration {
public:
    static void load();

private:
    constexpr static const char* m_filePath = "../configuration.json";

};


#endif //SPACEINVADERS_CONFIGURATION_H
