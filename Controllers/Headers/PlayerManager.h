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
#include "CollisionDetector.h"
#include "ConfigHandler.h"

namespace GameNs{
    class PlayerManager {
    public:
        PlayerManager();
        PlayerManager(GameNs::AbstractFactory *AF, BulletManager *bulletManager, Timer *timer,
                      CollisionDetector *collisionDetector, ConfigHandler *configHandler);
        ~PlayerManager();
        void checkPlayerBoundaries();
        void movePlayer();
        void update();
        void shoot();
        void createBullets();
        PlayerLife* getPlayerLife();
        PlayerShip* getPlayerShip();



    private:
        AbstractFactory* m_factory=nullptr;
        std::string m_playerShipPath = "../assets/ship.png";
        std::string m_bulletPath="../assets/laser.png";
        Timer* m_timer=nullptr;
        BulletManager* m_bulletManager=nullptr;
        SDLNs::SDLKeyStates* m_keyStates = nullptr;
        PlayerShip* m_playerShip=nullptr;
        CollisionDetector* m_collisionDetector= nullptr;
        int m_screenHeight=0;
        int m_screenWidth=0;
        std::vector<Bullet*> m_bullets;
        PlayerLife* m_playerLife= nullptr;
    };
}



#endif //PROJECT_PLAYERMANAGER_H
