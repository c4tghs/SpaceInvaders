#include <fstream>
#include <iostream>
#include "Configuration.h"
#include "Constants.h"

/**
 * Method used to load configuration
 */
void Configuration::load() {
    json m_json;

    //Read JSON file
    std::ifstream i{m_filePath};

    //If file was opened successfully, extract data
    if(i.good())
    {
        //Parse json
        i >> m_json;

        Constants::WINDOW_WIDTH =  m_json["settings"]["WINDOW_WIDTH"];
        Constants::WINDOW_HEIGHT =  m_json["settings"]["WINDOW_HEIGHT"];
        Constants::FRAME_RATE = m_json["settings"]["FRAME_RATE"];

        Constants::rescale();

        Constants::LEVELS[1]["ENEMY_SPEED"] = m_json["levels"]["one"]["ENEMY_SPEED"];
        Constants::LEVELS[1]["BULLET_SPEED"] = m_json["levels"]["one"]["BULLET_SPEED"];
        Constants::LEVELS[1]["PLAYER_SPEED"] = m_json["levels"]["one"]["PLAYER_SPEED"];
        Constants::LEVELS[1]["BONUS_SPEED"] = m_json["levels"]["one"]["BONUS_SPEED"];
        Constants::LEVELS[1]["ENEMIES"] = m_json["levels"]["one"]["ENEMIES"];
        Constants::LEVELS[1]["ENEMY_SHOOT_TIME"] = m_json["levels"]["one"]["ENEMY_SHOOT_TIME"];

        Constants::LEVELS[2]["ENEMY_SPEED"] = m_json["levels"]["two"]["ENEMY_SPEED"];
        Constants::LEVELS[2]["BULLET_SPEED"] = m_json["levels"]["two"]["BULLET_SPEED"];
        Constants::LEVELS[2]["PLAYER_SPEED"] = m_json["levels"]["two"]["PLAYER_SPEED"];
        Constants::LEVELS[2]["BONUS_SPEED"] = m_json["levels"]["two"]["BONUS_SPEED"];
        Constants::LEVELS[2]["ENEMIES"] = m_json["levels"]["two"]["ENEMIES"];
        Constants::LEVELS[2]["ENEMY_SHOOT_TIME"] = m_json["levels"]["two"]["ENEMY_SHOOT_TIME"];

        Constants::LEVELS[3]["ENEMY_SPEED"] = m_json["levels"]["three"]["ENEMY_SPEED"];
        Constants::LEVELS[3]["BULLET_SPEED"] = m_json["levels"]["three"]["BULLET_SPEED"];
        Constants::LEVELS[3]["PLAYER_SPEED"] = m_json["levels"]["three"]["PLAYER_SPEED"];
        Constants::LEVELS[3]["BONUS_SPEED"] = m_json["levels"]["three"]["BONUS_SPEED"];
        Constants::LEVELS[3]["ENEMIES"] = m_json["levels"]["three"]["ENEMIES"];
        Constants::LEVELS[3]["ENEMY_SHOOT_TIME"] = m_json["levels"]["three"]["ENEMY_SHOOT_TIME"];

        Constants::PLAYER_LIVES = m_json["settings"]["LIVES"];

    }
    else
    {
        std::cerr <<"Path is " << m_filePath << "\n";
        throw std::runtime_error("Could not open configuration file");
    }

    // Close file
    i.close();
}
