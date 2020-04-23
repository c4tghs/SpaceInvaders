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
