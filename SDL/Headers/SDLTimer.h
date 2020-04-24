//
// Created by cliff on 30/03/2020.
//

#ifndef PROJECT_SDLTIMER_H
#define PROJECT_SDLTIMER_H


#include "SDL2/SDL.h"
#include "../../Models/Headers/Timer.h"

namespace SDLNs
{
    class SDLTimer: public GameNs::Timer{
    public:
        SDLTimer();
        ~SDLTimer();
        void update();
        double getDeltaTime();
        void reset();
        float getTime();

    private:
        double m_deltaTime=0.0f;
        unsigned int m_startTicks =0;
        unsigned int m_elapsedTicks=0;
    };

}


#endif //PROJECT_SDLTIMER_H
