#pragma once


#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H


#include "Factories/Factory.h"

class Game {
public:
    static Game* getInstance(Abstract::Factory *AF);
    void run();
    static void destroyGame();

private:
    void createStartObjects();
    Game(Abstract::Factory *AF);
    void createEnemies();
    void moveEnemies();
    bool checkEnemyBoundaries();
    void playerActions();
    void playerShoot();
    void movePlayerBullet();
    void handleCollision();
    bool isCollision(Abstract::Entity* one,Abstract::Entity* two);
    ~Game();
private:
    static Game* m_instance;

    Abstract::Factory* m_factory = nullptr;
    Abstract::Controller* m_controller= nullptr;
    Abstract::Timer* m_timer=nullptr;
    Abstract::Window* m_window= nullptr;
    Abstract::PlayerShip* m_playership= nullptr;
    std::vector<Abstract::EnemyShip *> m_enemyShips;
    Abstract::Bullet* m_playerBullet = nullptr;
    int m_currentGameLevel=1;
    bool m_levelCompleted=false;
};






#endif //PROJECT_GAME_H
