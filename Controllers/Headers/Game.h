//
// Created by cliff on 08/03/2020.
//

#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H


#include "../../Factories/AbstractFactory.h"
namespace GameNs{
    class Game {
    public:
        Game(AbstractFactory *AF);
        void run();

    private:
        AbstractFactory* m_factory;

        std::string m_playerShipPath = "../assets/ship.png";
        std::string m_enemyShipPath = "../assets/alien1.png";
        std::string m_playerBulletPath = "../assets/playerBullet.png";
        int m_windowHeight = 720 ;
        int m_windowWidth = 1280;
    };

}


#endif //PROJECT_GAME_H
