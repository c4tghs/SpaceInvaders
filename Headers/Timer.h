//
// Created by cliff on 31/03/2020.
//

#ifndef PROJECT_TIMER_H
#define PROJECT_TIMER_H


class Timer {
public:
    virtual float getDeltaTime()=0;
    virtual void update()=0;
    virtual void reset()=0;

};


#endif //PROJECT_TIMER_H
