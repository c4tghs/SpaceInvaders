//
// Created by cliff on 08/03/2020.
//

#ifndef PROJECT_PLAYERSHIP_H
#define PROJECT_PLAYERSHIP_H


#include "Ship.h"

class PlayerShip: public Ship {
public:
    PlayerShip();
    ~PlayerShip();
    void moveLeft();
    void moveRight();
    void shoot();
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    //virtual void draw(); //
private:
    int m_x;
    int m_y;
};


#endif //PROJECT_PLAYERSHIP_H
