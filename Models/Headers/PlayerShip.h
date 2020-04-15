//
// Created by cliff on 08/03/2020.
//

#ifndef PROJECT_PLAYERSHIP_H
#define PROJECT_PLAYERSHIP_H


#include "Entity.h"

namespace GameNs
{
    class PlayerShip: public Entity {
    public:
        PlayerShip();
        PlayerShip(int xPos, int yPos, int width, int height);
        virtual void render() = 0;
        virtual void close() = 0;
        void setPlayerSpeed(float speed);
        float getPlayerSpeed();

    private:
        float m_playerSpeed=5.0f;
    };

}


#endif //PROJECT_PLAYERSHIP_H
