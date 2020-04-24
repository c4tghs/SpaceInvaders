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
    //Read JSON file
    std::ifstream i{m_configFile};
    //If file was opened successfully, extract data
    if(i.good())
    {
        i >> m_json;
        m_screenHeight = m_json.find("configuration")->find("SCREENHEIGHT")->get<int>();
        m_screenWidth = m_json.find("configuration")->find("SCREENWIDTH")->get<int>();
        m_enemySpeed = m_json.find("configuration")->find("ENEMYSPEED")->get<int>();
        m_bonusSpeed = m_json.find("configuration")->find("BONUSSPEED")->get<int>();
        m_bulletSpeed = m_json.find("configuration")->find("BULLETSPEED")->get<int>();
        m_playerLives = m_json.find("configuration")->find("LIVES")->get<int>();
        m_playerSpeed = m_json.find("configuration")->find("PLAYERSPEED")->get<int>();
        m_playerShipWidth = m_screenWidth / 10;
        m_playerShipHeight = m_screenHeight / 10;
        m_playerShipYPos = m_screenHeight-(m_playerShipHeight + 10);
        m_playerShipXPos = (m_screenWidth/2)-50;
        m_enemyShipWidth = m_screenWidth/25;
        m_enemyShipHeight =  m_screenHeight/25;
        i.close();
    }
    else
    {
        std::cerr<<"Could not open configuration file" << std::endl;
        exit(1);
    }

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
