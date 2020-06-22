#ifndef PROJECT_ENEMYSHIP_H
#define PROJECT_ENEMYSHIP_H

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
        ENEMY_TYPE getEnemyType();

    private:
        int m_moveDirection;
    protected:
        ENEMY_TYPE m_enemyType;

    };
}



#endif //PROJECT_ENEMYSHIP_H
