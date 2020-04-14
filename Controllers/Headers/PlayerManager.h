//
// Created by cliff on 01/04/2020.
//

/**
 * PlayerManager class
 * Methods for managing a player
 */
#ifndef PROJECT_PLAYERMANAGER_H
#define PROJECT_PLAYERMANAGER_H

#include "../../Factories/AbstractFactory.h"
#include "../../SDL/Headers/SDLTimer.h"
#include "../../SDL/Headers/SDLKeyStates.h"
#include "../../SDL/Headers/SDLBullet.h"
#include "BulletManager.h"
#include "CollisionManager.h"

namespace GameNs{
    class PlayerManager {
    public:
        PlayerManager();
        PlayerManager(GameNs::AbstractFactory *AF, int screenHeight, int screenWidth, BulletManager *bulletManager,
                      Timer *timer);
        void checkPlayerBoundaries();
        void playerActions();
        void update();
        void close();
        void shoot();
        void createBullets();


    private:
        AbstractFactory* m_factory;
        std::string m_playerShipPath = "../assets/ship.png";
        //std::string m_bulletPath="../assets/playerBullet.png";
        std::string m_bulletPath="../assets/playerBullet.png";
        Timer *m_timer;
        BulletManager *m_bulletManager;
        SDLNs::SDLKeyStates* m_keyStates = nullptr;
        PlayerShip* m_playerShip;
        int m_screenHeight;
        int m_screenWidth;
        int m_playerStartPosX=0;

        std::vector<Bullet*> m_bullets;
        //Score* m_score;
        PlayerLife* m_playerLife;
    };
}



#endif //PROJECT_PLAYERMANAGER_H
