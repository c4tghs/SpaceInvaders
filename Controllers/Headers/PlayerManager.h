//
// Created by cliff on 01/04/2020.
//

#ifndef PROJECT_PLAYERMANAGER_H
#define PROJECT_PLAYERMANAGER_H

#include "../../Factories/AbstractFactory.h"
#include "../../SDL/Headers/SDLTimer.h"
#include "../../SDL/Headers/SDLKeyStates.h"

namespace GameNs{
    class PlayerManager {
    public:
        PlayerManager();
        PlayerManager(GameNs::AbstractFactory *AF,std::string playerShipPath,int screenHeight, int screenWidth);
        void checkPlayerBoundaries();
        void movePlayer();
        void update();
        void close();

    private:
        AbstractFactory* m_factory;
        std::string m_playerShipPath;
        SDLNs::SDLTimer *m_timer;
        SDLNs::SDLKeyStates* m_keyStates;
        Ship* m_playerShip;
        int m_screenHeight;
        int m_screenWidth;
        int m_shipHeight;
        int m_shipWidth;
    };
}



#endif //PROJECT_PLAYERMANAGER_H
