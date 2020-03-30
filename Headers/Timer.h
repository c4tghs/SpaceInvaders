//
// Created by cliff on 30/03/2020.
//

#ifndef PROJECT_TIMER_H
#define PROJECT_TIMER_H

#include <Chrono>

class Timer {
public:
    //virtual void start()=0;
    virtual void reset()=0;
    virtual void timeScale()=0;
    virtual void update()=0;
};


#endif //PROJECT_TIMER_H
