//
// Created by cliff on 23/03/2020.
//

#ifndef PROJECT_BULLET_H
#define PROJECT_BULLET_H

namespace GameNs
{
    class Bullet {
    public:
        virtual void fire()=0;
        virtual void reload()=0;
        virtual void render()=0;
    };
}



#endif //PROJECT_BULLET_H
