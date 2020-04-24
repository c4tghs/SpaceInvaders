//
// Created by cliff on 23/04/2020.
//

#ifndef PROJECT_CONFIGHANDLER_H
#define PROJECT_CONFIGHANDLER_H

#include "../../nlohmann/json.hpp"
#include <string>
#include <direct.h>

using json = nlohmann::json;
namespace GameNs{
    class ConfigHandler {
        public:
            ConfigHandler();
            int getPlayerSpeed();
            int getScreenWidth();
            int getScreenHeight();
            int getEnemySpeed();
            int getBonusSpeed();
            int getBulletSpeed();
            int getPlayerLives();
            int getPlayerShipHeight();
            int getPlayerShipWidth();
            int getPlayerShipYPos();
            int getPlayerShipXPos();
            int getEnemyShipWidth();
            int getEnemyShipHeight();

        private:
            int m_playerSpeed=0;
            int m_screenWidth=0;
            int m_screenHeight=0;
            int m_enemySpeed = 0;
            int m_bonusSpeed=0;
            int m_bulletSpeed=0;
            int m_playerLives=0;
            int m_playerShipHeight=0;
            int m_playerShipWidth=0;
            int m_playerShipYPos=0;
            int m_playerShipXPos=0;
            int m_enemyShipHeight=0;
            int m_enemyShipWidth=0;
            std::string m_configFile = "../configuration.json";
            json m_json= nullptr;

    };
}



#endif //PROJECT_CONFIGHANDLER_H
