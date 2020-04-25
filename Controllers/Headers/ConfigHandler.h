//
// Created by cliff on 23/04/2020.
//
#pragma once

#ifndef PROJECT_CONFIGHANDLER_H
#define PROJECT_CONFIGHANDLER_H

#include "../../nlohmann/json.hpp"
#include <string>

using json = nlohmann::json;
namespace GameNs{
    class ConfigHandler {
        public:
            ConfigHandler();
            void setStartParameters();
            void setFiles();
            void setLevelParameters(const std::string &level);
            void readConfiguration();
            void storeParameters();

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
            int getEnemyAmount();

            std::string getPathPlayerShip();
            std::string getPathBonusLife();
            std::string getPathBonusSpeed();
            std::string getPathBonusPoints();
            std::string getPathPlayerBullet();
            std::string getPathEnemyShip();
            std::string getPathEnemyBullet();

        private:
            int m_playerSpeed=0;
            int m_enemySpeed = 0;
            int m_bonusSpeed=0;
            int m_bulletSpeed=0;

            int m_screenWidth=0;
            int m_screenHeight=0;

            int m_playerLives=0;
            int m_enemyAmount=0;
            int m_playerShipHeight=0;
            int m_playerShipWidth=0;
            int m_playerShipYPos=0;
            int m_playerShipXPos=0;
            int m_enemyShipHeight=0;
            int m_enemyShipWidth=0;

            std::string m_configFile = "../configuration.json";
            std::string m_pathBonusLife;
            std::string m_pathBonusSpeed;
            std::string m_pathBonusPoints;
            std::string m_pathPlayerShip;
            std::string m_pathPlayerBullet;
            std::string m_pathEnemyShip;
            std::string m_pathEnemyBullet;
            json m_json= nullptr;
            std::map<std::string,std::map<std::string,int>> m_levels;
    };
}



#endif //PROJECT_CONFIGHANDLER_H
