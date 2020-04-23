//
// Created by cliff on 31/03/2020.
//

#ifndef PROJECT_TIMER_H
#define PROJECT_TIMER_H

//constant used to make sure speed is constant
const float TARGET_DELTATIME = 1.5f;

namespace GameNs
{
    class Timer {
    public:
        virtual double getDeltaTime()=0;
        virtual void update()=0;
        virtual void reset()=0;
        virtual float getTime()=0;

    };
}


#endif //PROJECT_TIMER_H
