//
// Created by cliff on 23/04/2020.
//

#include <fstream>
#include <iostream>
#include "../Headers/ConfigHandler.h"

/**
 * Constructor
 */
GameNs::ConfigHandler::ConfigHandler() {
    //Read configuration
    readConfiguration();
}

/**
 * Method to open configuration file
 */
void GameNs::ConfigHandler::readConfiguration() {
    //Read JSON file
    std::ifstream i{m_configFile};
    //If file was opened successfully, extract data
    if(i.good())
    {
        //m_json = json::parse(i);
        i >> m_json;
        setStartParameters();
        setFiles();
        storeParameters();
    }
    else
    {
        std::cerr<<"Could not open configuration file" << std::endl;
        exit(1);
    }
    i.close();
}

/**
 * Method to set game start parameters
 */
void GameNs::ConfigHandler::setStartParameters() {
    m_screenHeight = m_json["start"]["SCREENHEIGHT"];
    m_screenWidth = m_json["start"]["SCREENWIDTH"];
    m_playerLives = m_json["start"]["LIVES"];

    m_playerShipWidth = m_screenWidth / 10;
    m_playerShipHeight = m_screenHeight / 10;
    m_playerShipYPos = m_screenHeight-(m_playerShipHeight + 10);
    m_playerShipXPos = (m_screenWidth/2)-50;
    m_enemyShipWidth = m_screenWidth/25;
    m_enemyShipHeight =  m_screenHeight/25;

}

/**
 * Method to used to store level parameters in map
 */
void GameNs::ConfigHandler::storeParameters() {
    m_levels["one"]["ENEMYSPEED"] = m_json["levels"]["one"]["ENEMYSPEED"];
    m_levels["one"]["BULLETSPEED"] = m_json["levels"]["one"]["BULLETSPEED"];
    m_levels["one"]["PLAYERSPEED"] = m_json["levels"]["one"]["PLAYERSPEED"];
    m_levels["one"]["BONUSSPEED"] = m_json["levels"]["one"]["BONUSSPEED"];
    m_levels["one"]["ENEMIES"] = m_json["levels"]["one"]["ENEMIES"];

    m_levels["two"]["ENEMYSPEED"] = m_json["levels"]["two"]["ENEMYSPEED"];
    m_levels["two"]["BULLETSPEED"] = m_json["levels"]["two"]["BULLETSPEED"];
    m_levels["two"]["PLAYERSPEED"] = m_json["levels"]["two"]["PLAYERSPEED"];
    m_levels["two"]["BONUSSPEED"] = m_json["levels"]["two"]["BONUSSPEED"];
    m_levels["two"]["ENEMIES"] = m_json["levels"]["two"]["ENEMIES"];

    m_levels["three"]["ENEMYSPEED"] = m_json["levels"]["three"]["ENEMYSPEED"];
    m_levels["three"]["BULLETSPEED"] = m_json["levels"]["three"]["BULLETSPEED"];
    m_levels["three"]["PLAYERSPEED"] = m_json["levels"]["three"]["PLAYERSPEED"];
    m_levels["three"]["BONUSSPEED"] = m_json["levels"]["three"]["BONUSSPEED"];
    m_levels["three"]["ENEMIES"] = m_json["levels"]["three"]["ENEMIES"];

}

/**
 * Method to set path of image files
 */
void GameNs::ConfigHandler::setFiles() {
    m_pathBonusPoints = m_json["images"]["BONUSPOINTS"];
    m_pathBonusSpeed = m_json["images"]["BONUSSPEED"];
    m_pathBonusLife = m_json["images"]["BONUSLIFE"];
    m_pathPlayerShip = m_json["images"]["PLAYERSHIP"];
    m_pathEnemyShip = m_json["images"]["ENEMYSHIP"];
    m_pathPlayerBullet = m_json["images"]["PLAYERBULLET"];
    m_pathEnemyBullet = m_json["images"]["ENEMYBULLET"];

}


/**
 * Method that returns player speed
 * @return - integer representing player speed
 */
int GameNs::ConfigHandler::getPlayerSpeed() {
    return m_playerSpeed;
}

/**
 * Method that returns screen width
 * @return integer representing screen width
 */
int GameNs::ConfigHandler::getScreenWidth() {
    return m_screenWidth;
}

/**
 * Method that returns screen height
 * @return integer representing screen height
 */
int GameNs::ConfigHandler::getScreenHeight() {
    return m_screenHeight;
}

/**
 * Method that returns enemy speed
 * @return integer representing enemy speed factor
 */
int GameNs::ConfigHandler::getEnemySpeed() {
    return m_enemySpeed;
}

/**
 * Method that returns bonus speed
 * @return integer representing bonus speed factor
 */
int GameNs::ConfigHandler::getBonusSpeed() {
    return m_bonusSpeed;
}

/**
 * Method that returns bullet speed
 * @return integer representing bullet speed factor
 */
int GameNs::ConfigHandler::getBulletSpeed() {
    return m_bulletSpeed;
}

/**
 * Method that returns maximum player lives
 * @return integer representing maximum player lives
 */
int GameNs::ConfigHandler::getPlayerLives() {
    return m_playerLives;
}

/**
 * Method that returns player ship height
 * @return integer representing player ship height on screen
 */
int GameNs::ConfigHandler::getPlayerShipHeight() {
    return m_playerShipHeight;
}

/**
 * Method that returns player ship width
 * @return integer representing player ship width on screen
 */
int GameNs::ConfigHandler::getPlayerShipWidth() {
    return m_playerShipWidth;
}

/**
 * Method that returns player ship initial y position
 * @return integer representing player ship y position
 */
int GameNs::ConfigHandler::getPlayerShipYPos() {
    return m_playerShipYPos;
}

/**
 * Method that returns player ship initial x position
 * @return integer representing player ship x position
 */
int GameNs::ConfigHandler::getPlayerShipXPos() {
    return m_playerShipXPos;
}

/**
 * Method that returns enemy ship width
 * @return integer representing enemy ship width on screen
 */
int GameNs::ConfigHandler::getEnemyShipWidth() {
    return m_enemyShipWidth;
}

/**
 * Method that returns enemy ship width
 * @return integer representing enemy ship width on screen
 */
int GameNs::ConfigHandler::getEnemyShipHeight() {
    return m_enemyShipHeight;
}

/**
 * Method that returns path to image of player ship
 * @return string representing path to player ship
 */
std::string GameNs::ConfigHandler::getPathPlayerShip() {
    return m_pathPlayerShip;
}

/**
 * Method that returns path to bonus type life
 * @return string representing path to bonus
 */
std::string GameNs::ConfigHandler::getPathBonusLife() {
    return m_pathBonusLife;
}

/**
 * Method that returns path to bonus type speed
 * @return string representing path to bonus
 */
std::string GameNs::ConfigHandler::getPathBonusSpeed() {
    return m_pathBonusSpeed;
}

/**
 * Method that returns path to bonus type points
 * @return string representing path to bonus
 */
std::string GameNs::ConfigHandler::getPathBonusPoints() {
    return m_pathBonusPoints;
}

/**
 * Method that returns path to image of player bullet
 * @return string representing path to player bullet
 */
std::string GameNs::ConfigHandler::getPathPlayerBullet() {
    return m_pathPlayerBullet;
}

/**
 * Method that returns path to image of enemy ship
 * @return string representing path to enemy ship
 */
std::string GameNs::ConfigHandler::getPathEnemyShip() {
    return m_pathEnemyShip;
}

/**
 * Method that returns path to image of enemy bullet
 * @return string representing path to enemy bullet
 */
std::string GameNs::ConfigHandler::getPathEnemyBullet() {
    return m_pathEnemyBullet;
}

/**
 * Method to set parameters for level
 * @param level
 */
void GameNs::ConfigHandler::setLevelParameters(const std::string &level) {
    m_bulletSpeed  = m_levels[level]["BULLETSPEED"];
    m_playerSpeed  = m_levels[level]["PLAYERSPEED"];
    m_enemySpeed  = m_levels[level]["ENEMYSPEED"];
    m_enemyAmount  = m_levels[level]["ENEMIES"];
    m_bonusSpeed  = m_levels[level]["BONUSSPEED"];
}

/**
 * Method that returns amount of enemies for a level
 * @return integer representing amount of enemies
 */
int GameNs::ConfigHandler::getEnemyAmount() {
    return m_enemyAmount;
}


