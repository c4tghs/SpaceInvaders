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

namespace GameNs
{
    class EnemyManager {
    public:
        EnemyManager();
        EnemyManager(AbstractFactory* AF,std::string enemyShipPath, int screenWidth);
        void createEnemies(int number);
        void updateEnemies();
        void moveEnemies();
        bool checkEnemyBoundaries();
        void enemyShoot();
        void createBullets();
        void close();

    private:
        AbstractFactory* m_factory;
        std::vector<Ship *> m_enemyShips;
        std::string m_enemyShipPath;
        Timer *m_timer;
        int m_screenWidth;
        float m_nextMissile;
        std::string m_bulletPath = "../assets/bullet.jpeg";
        std::vector<Bullet*> m_bullets;
    };
}



#endif //PROJECT_ENEMYMANAGER_H
