#pragma once


#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H


#include "Factories/Factory.h"
#include "EntityControllers/Headers/PlayerShipController.h"
#include "EntityControllers/Headers/EnemyShipController.h"

class Game {
public:
    static Game* getInstance(Abstract::Factory *AF);
    void run();
    static void destroyGame();

private:
    void createStartObjects();
    Game(Abstract::Factory *AF);
    ~Game();
private:
    static Game* m_instance;

    Abstract::Factory* m_factory = nullptr;
    Abstract::Controller* m_controller= nullptr;
    PlayerShipController* m_playerShipController=nullptr;
    EnemyShipController* m_enemyShipController=nullptr;
    Abstract::Timer* m_timer=nullptr;
    Abstract::Window* m_window;

    int m_currentGameLevel=1;
    bool m_levelCompleted=false;

    const int FRAME_RATE = 60;
};






#endif //PROJECT_GAME_H
