//
// Created by cliff on 08/03/2020.
//

/**
 * Game class
 * Method to run game
 */
#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H


#include "../../Factories/AbstractFactory.h"
namespace GameNs{
    class Game {
    public:
        static Game* getInstance();
        static Game* getInstance(AbstractFactory *AF);

        void run();

    private:
        static Game* m_instance;
        Game(AbstractFactory *AF);
        Game();
        AbstractFactory* m_factory;

        std::string m_playerShipPath = "../assets/ship.png";
        std::string m_enemyShipPath = "../assets/alien1.png";
        std::string m_playerBulletPath = "../assets/playerBullet.png";
        const int m_windowHeight = 720 ;
        const int m_windowWidth = 1280;
    };

}


#endif //PROJECT_GAME_H
