/**
 * BulletManager class
 * Methods to managing a bullet
 */

#ifndef PROJECT_BULLETMANAGER_H
#define PROJECT_BULLETMANAGER_H

#include <vector>
#include "../../Factories/AbstractFactory.h"
#include "../../SDL/Headers/SDLTimer.h"
#include "CollisionManager.h"

namespace GameNs{
    class BulletManager {
    public:
        static BulletManager* getInstance();
        static BulletManager* getInstance(Bullet* bullet,Timer* timer,int screenHeight);
        void update();
        void moveBullet();
        void setPlayerBullet(Bullet* bullet);
        void setEnemyBullet(Bullet* bullet);
        void checkBulletBounds();
        bool getPlayerBulletFired();
        bool getEnemyBulletFired();
        void setPlayerBulletFired(bool isFired);
        void setEnemyBulletFired(bool isFired);
        bool checkPlayerCollisions();
        void setEnemyShip(std::vector<Ship *> &enemyShips);


    private:
        static BulletManager* m_instance;
        BulletManager();
        BulletManager(Bullet *bullet, Timer *timer, int screenHeight);

        bool m_playerFired = false;
        bool m_enemyFired = false;
        Timer* m_timer= nullptr;
        Bullet* m_playerBullet = nullptr;
        Bullet* m_enemyBullet = nullptr;
        int m_screenHeight = 0;
        std::vector<Ship *> m_enemyShips;


    };
}



#endif //PROJECT_BULLETMANAGER_H
