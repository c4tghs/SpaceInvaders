#include <fstream>
#include <iostream>
#include "Configuration.h"
#include "Constants.h"

/**
 * Method used to load configuration
 * @param path - path to configuration
 */
void Configuration::load() {
    json m_json;

    //Read JSON file
    std::ifstream i{m_filePath};

    //If file was opened successfully, extract data
    if(i.good())
    {
        i >> m_json;
        Constants::WINDOW_WIDTH =  m_json["settings"]["WINDOW_WIDTH"];
        Constants::WINDOW_HEIGHT =  m_json["settings"]["WINDOW_HEIGHT"];
        Constants::FRAME_RATE = m_json["settings"]["FRAME_RATE"];
        Constants::rescale();

        Constants::LEVELS[1]["ENEMYSPEED"] = m_json["levels"]["one"]["ENEMYSPEED"];
        Constants::LEVELS[1]["BULLETSPEED"] = m_json["levels"]["one"]["BULLETSPEED"];
        Constants::LEVELS[1]["PLAYERSPEED"] = m_json["levels"]["one"]["PLAYERSPEED"];
        Constants::LEVELS[1]["BONUSSPEED"] = m_json["levels"]["one"]["BONUSSPEED"];
        Constants::LEVELS[1]["ENEMIES"] = m_json["levels"]["one"]["ENEMIES"];

        Constants::LEVELS[2]["ENEMYSPEED"] = m_json["levels"]["one"]["ENEMYSPEED"];
        Constants::LEVELS[2]["BULLETSPEED"] = m_json["levels"]["one"]["BULLETSPEED"];
        Constants::LEVELS[2]["PLAYERSPEED"] = m_json["levels"]["one"]["PLAYERSPEED"];
        Constants::LEVELS[2]["BONUSSPEED"] = m_json["levels"]["one"]["BONUSSPEED"];
        Constants::LEVELS[2]["ENEMIES"] = m_json["levels"]["one"]["ENEMIES"];

        Constants::LEVELS[3]["ENEMYSPEED"] = m_json["levels"]["one"]["ENEMYSPEED"];
        Constants::LEVELS[3]["BULLETSPEED"] = m_json["levels"]["one"]["BULLETSPEED"];
        Constants::LEVELS[3]["PLAYERSPEED"] = m_json["levels"]["one"]["PLAYERSPEED"];
        Constants::LEVELS[3]["BONUSSPEED"] = m_json["levels"]["one"]["BONUSSPEED"];
        Constants::LEVELS[3]["ENEMIES"] = m_json["levels"]["one"]["ENEMIES"];

        Constants::PLAYER_LIVES = m_json["settings"]["LIVES"];

    }
    else
    {
        std::cerr <<"Path is " << m_filePath << "\n";
        throw std::runtime_error("Could not open configuration file");
    }
    i.close();
}
