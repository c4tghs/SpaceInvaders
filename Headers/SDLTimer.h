//
// Created by cliff on 30/03/2020.
//

#ifndef PROJECT_SDLTIMER_H
#define PROJECT_SDLTIMER_H


#include "Timer.h"
#include "SDL.h"

class SDLTimer: public Timer {
public:
     static SDLTimer* instance();
     void reset()=0;
     void timeScale()=0;
     void update()=0;
     float getDeltaTime();
     void setTimeScale(float t);
     float getTimeScale();

private:
    static SDLTimer* m_instance;
    unsigned int m_startTicks;
    unsigned int m_elapsedTicks;
    float m_deltaTime;
    float m_timeScale();
};


#endif //PROJECT_SDLTIMER_H
