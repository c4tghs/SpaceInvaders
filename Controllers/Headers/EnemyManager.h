/**
 * EnemyManager class
 * Method for managing enemies
 */

#ifndef PROJECT_ENEMYMANAGER_H
#define PROJECT_ENEMYMANAGER_H


/**
 * TODO add method to set and get enemy type
 *
 */


#include "../../Factories/AbstractFactory.h"
#include "../../SDL/Headers/SDLTimer.h"
#include "CollisionManager.h"
#include "BulletManager.h"
#include <vector>
#include <random>

namespace GameNs
{
    class EnemyManager {
    public:
        EnemyManager();
        EnemyManager(AbstractFactory* AF, int screenWidth, int screenHeight, BulletManager* bulletManager, Timer* timer,
                     Score* score);
        void createEnemies(int number);
        void updateEnemies();
        void moveEnemies();
        bool checkEnemyBoundaries();
        void enemyShoot();
        void createBullets();
        void close();

    private:
        AbstractFactory* m_factory=nullptr;
        std::vector<EnemyShip *> m_enemyShips;
        Timer* m_timer=nullptr;
        BulletManager* m_bulletManager= nullptr;
        int m_screenWidth=0;
        int m_screenHeight=0;
        int m_playerYPos=0;
        float m_nextMissile=0.0;
        bool m_playerReached = false;
        std::string m_enemyShipOctopusPath = "../assets/octopus.png";
        std::string m_enemyShipCrabPath = "../assets/crab.png";
        std::string m_enemyShipSquidPath = "../assets/squid.png";
        std::string m_bulletPath = "../assets/bullet.jpeg";
        std::vector<Bullet*> m_bullets;
        Score* m_score= nullptr;
    };
}



#endif //PROJECT_ENEMYMANAGER_H
