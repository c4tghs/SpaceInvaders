//
// Created by cliff on 08/03/2020.
//

#ifndef PROJECT_ENEMYSHIP_H
#define PROJECT_ENEMYSHIP_H

#include <SDL2/SDL_rect.h>
#include "Entity.h"

#define SPRITES_FRAMES 2

namespace GameNs
{
    enum EnemyType{Octopus,Crab,Squid};

    class EnemyShip: public Entity {
    public:
        EnemyShip();
        EnemyShip(int xPos, int yPos, int width, int height);
        virtual void render() = 0;
        virtual void close() = 0;
        virtual int getMoveDirection()=0;
        virtual void setMoveDirection(int direction)=0;
        virtual void setRect(SDL_Rect rects[])=0;
        void setEnemyType(EnemyType type);
        void setEnemySpeed(int speed);
        int getEnemySpeed();
        EnemyType getEnemyType();

    private:
        EnemyType  m_enemyType= Squid;
        int m_enemySpeed=0;
    };
}



#endif //PROJECT_ENEMYSHIP_H
