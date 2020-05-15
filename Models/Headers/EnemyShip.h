//
// Created by cliff on 08/03/2020.
//

#ifndef PROJECT_ENEMYSHIP_H
#define PROJECT_ENEMYSHIP_H

#include <SDL2/SDL_rect.h>
#include "Entity.h"
#include "../../Enums.h"

namespace Abstract
{
    class EnemyShip: public Entity {
    public:
        EnemyShip(double xPos, double yPos, double width, double height);
        virtual ~EnemyShip()=default;
        virtual void render() = 0;
        int getMoveDirection() const;
        void setMoveDirection(int direction);
        void setEnemyType(ENEMY_TYPE type);
        ENEMY_TYPE getEnemyType();
        SPRITE getSpriteType();

    private:
        ENEMY_TYPE  m_enemyType= SQUID;
        int m_moveDirection;
    };
}



#endif //PROJECT_ENEMYSHIP_H
