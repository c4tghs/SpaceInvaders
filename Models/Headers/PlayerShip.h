#ifndef PROJECT_PLAYERSHIP_H
#define PROJECT_PLAYERSHIP_H

#include "Entity.h"

namespace Abstract
{
    class PlayerShip: public Entity {
    public:
        PlayerShip(double xPos, double yPos, double width, double height);
        virtual ~PlayerShip();
        void setScore(int score);
        int getScore() const;
        void setLives(int lives);
        int getLives();
        virtual void render() = 0;

    private:
        int m_score;
        int m_lives;
    };

}


#endif //PROJECT_PLAYERSHIP_H
