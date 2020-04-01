//
// Created by cliff on 30/03/2020.
//

#ifndef PROJECT_SDLTIMER_H
#define PROJECT_SDLTIMER_H


#include "SDL.h"
#include "Timer.h"

namespace SDLNs
{
    class SDLTimer: public GameNs::Timer{
    public:
        SDLTimer();
        void update();
        float getDeltaTime();
        void reset();

    private:
        float m_deltaTime;
        unsigned int m_startTicks;
        unsigned int m_elapsedTicks;
    };

}


#endif //PROJECT_SDLTIMER_H
