//
// Created by cliff on 08/03/2020.
//

#ifndef PROJECT_ENEMYSHIP_H
#define PROJECT_ENEMYSHIP_H

#include <SDL2/SDL_rect.h>
#include "Entity.h"
#include "../../Constants.h"

namespace Abstract
{
    class EnemyShip: public Entity {
    public:
        EnemyShip(double xPos, double yPos, double width, double height);
        virtual ~EnemyShip(){};
        virtual void render() = 0;
        int getMoveDirection() const;
        void setMoveDirection(int direction);
        Enemy_type getEnemyType();

    private:
        int m_moveDirection;
    protected:
        Enemy_type m_enemyType;

    };
}



#endif //PROJECT_ENEMYSHIP_H
