#ifndef PROJECT_PLAYERSHIP_H
#define PROJECT_PLAYERSHIP_H

#include "Entity.h"

namespace Abstract
{
    class PlayerShip: public Entity {
    public:
        PlayerShip(double xPos, double yPos, double width, double height);
        virtual ~PlayerShip();
        virtual void render() = 0;

    };

}


#endif //PROJECT_PLAYERSHIP_H
