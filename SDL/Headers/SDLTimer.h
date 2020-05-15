//
// Created by cliff on 30/03/2020.
//

#ifndef PROJECT_SDLTIMER_H
#define PROJECT_SDLTIMER_H


#include "SDL2/SDL.h"
#include "../../Models/Headers/Timer.h"

namespace SDL
{
    class SDLTimer: public Abstract::Timer{
    public:
        SDLTimer();
        ~SDLTimer() override;
        void update() override ;
        void reset() override ;
        double getDeltaTime() override;
        float getTime() override;

    private:
        double m_deltaTime=0.0f;
        unsigned int m_startTicks =0;
        unsigned int m_elapsedTicks=0;
    };

}


#endif //PROJECT_SDLTIMER_H
