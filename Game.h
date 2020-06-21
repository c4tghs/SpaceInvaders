#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H

#include "Factories/Factory.h"
#include "Models/Headers/RandomNumber.h"


class Game {
public:
    static Game* getInstance(Abstract::Factory *AF);
    void run();
    static void destroyGame();

private:
    void createStartObjects();
    Game(Abstract::Factory *AF);
    void createEnemies();
    void handleEnemyShips();
    bool checkEnemyBoundaries();
    void handleBonuses();
    void handlePlayerShip();
    void playerShoot();
    void moveBullets();
    void handleCollision();
    static bool isCollision(Abstract::Entity* one,Abstract::Entity* two);
    ~Game();
private:
    static Game* m_instance;
    Mode m_gameMode;
    Abstract::Factory* m_factory = nullptr;
    Abstract::Controller* m_controller= nullptr;
    Abstract::Timer* m_timer=nullptr;
    Abstract::Window* m_window= nullptr;
    Abstract::PlayerShip* m_playerShip= nullptr;
    std::vector<Abstract::EnemyShip *> m_enemyShips;
    Abstract::Bullet* m_playerBullet = nullptr;
    std::vector<Abstract::Bullet* > m_enemyBullets;
    Abstract::Bonus* m_bonusPoints = nullptr;
    Abstract::Bonus* m_bonus = nullptr;
    double m_nextEnemyBullet=0;
    double m_nextPointBonus=0;
    double m_nextLivesBonus=0;
    int m_currentGameLevel=1;
    int m_enemySpeedBoost=0;
    bool m_levelCompleted=false;
};






#endif //PROJECT_GAME_H
