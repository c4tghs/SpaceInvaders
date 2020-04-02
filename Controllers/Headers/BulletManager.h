//
// Created by cliff on 01/04/2020.
//

#ifndef PROJECT_BULLETMANAGER_H
#define PROJECT_BULLETMANAGER_H

#include <vector>
#include "../../Factories/AbstractFactory.h"
#include "../../SDL/Headers/SDLTimer.h"

namespace GameNs{
    class BulletManager {
    public:
        BulletManager();
        BulletManager(Bullet* bullet,std::string bulletPath,Timer* timer,int screenHeight);
        void update();
        void moveBullet();
        void setBullet(Bullet* bullet);
        void checkBulletBounds();
        void setMoveDirection(int direction);
        bool getBulletFired();
        void setBulletFired(bool isFired);

    private:
        bool m_bulletFired;
        int m_moveDirection;
        int m_maxBullets;
        Timer* m_timer;
        Bullet* m_bullet;
        std::string m_bulletPath;
        int m_height = 10;
        int m_width = 10;
        int m_screenHeight;

    };
}



#endif //PROJECT_BULLETMANAGER_H
