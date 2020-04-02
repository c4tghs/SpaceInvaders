//
// Created by cliff on 23/03/2020.
//

#ifndef PROJECT_BULLET_H
#define PROJECT_BULLET_H

namespace GameNs
{
    class Bullet {
    public:
        virtual void close()=0;
        virtual void render()=0;
        virtual int getXPosition()=0;
        virtual int getYPosition()=0;
        virtual void setXPosition(int x)=0;
        virtual void setYPosition(int y)=0;
    };
}



#endif //PROJECT_BULLET_H
