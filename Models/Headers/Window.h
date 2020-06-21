#ifndef SPACEINVADERS_WINDOW_H
#define SPACEINVADERS_WINDOW_H

#include "../../Constants.h"

namespace Abstract
{
    class Window{
    public:
        Window()= default;
        virtual ~Window()= default;;
        virtual bool initialise()=0;
        virtual bool loadMedia()=0;
        virtual void render()=0;
        virtual void refresh()=0;
        virtual void drawRect(Sprite sprite, double xPos, double yPos, double width, double height) =0;
        virtual void playSound(Sound_type sound)=0;
        virtual void exit(const char* message) =0;
        virtual void showScore(int score)=0;
        virtual void showLives(int lives)=0;
        virtual void showLevel(int level)=0;
        virtual void showEndScore(int score)=0;
    };
}

#endif //SPACEINVADERS_WINDOW_H
