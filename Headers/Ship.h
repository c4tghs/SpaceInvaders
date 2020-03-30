//
// Created by cliff on 04/03/2020.
//

#ifndef PROJECT_SHIP_H
#define PROJECT_SHIP_H


class Ship {
public:
    virtual int getXPosition()=0;
    virtual int getYPosition()=0;
    virtual void setXPosition(int x)=0;
    virtual void setYPosition(int y)=0;
    virtual void render() = 0;
    virtual void close() = 0;

};




#endif //PROJECT_SHIP_H
