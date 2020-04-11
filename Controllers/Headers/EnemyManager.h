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
        EnemyManager(AbstractFactory *AF, int screenWidth);
        void createEnemies(int number);
        void updateEnemies();
        void moveEnemies();
        bool checkEnemyBoundaries();
        void enemyShoot();
        void createBullets();
        void close();
        static int randomNumber(int lowerBound=0, int higherBound=3);

    private:
        AbstractFactory* m_factory;
        std::vector<EnemyShip *> m_enemyShips;
        Timer *m_timer;
        int m_screenWidth;
        float m_nextMissile;
        std::string m_enemyShipOctopusPath = "../assets/octopus.png";
        std::string m_enemyShipCrabPath = "../assets/crab.png";
        std::string m_enemyShipSquidPath = "../assets/squid.png";
        std::string m_bulletPath = "../assets/bullet.jpeg";
        std::vector<Bullet*> m_bullets;
        static std::random_device m_rd;
        Score *m_score= nullptr;
    };
}



#endif //PROJECT_ENEMYMANAGER_H
