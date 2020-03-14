//
// Created by cliff on 08/03/2020.
//

#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H


#include "../Factories/AbstractFactory.h"

class Game {
public:
    Game(AbstractFactory *AF);
    void run();

private:
    AbstractFactory* m_factory;

    string m_playerShipPath = "../assets/ship.png";
    int m_windowHeight = 960;
    int m_windowWidth = 640;
};


#endif //PROJECT_GAME_H
