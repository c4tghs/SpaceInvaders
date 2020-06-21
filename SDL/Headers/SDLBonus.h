#ifndef SPACEINVADERS_SDLBONUS_H
#define SPACEINVADERS_SDLBONUS_H

#include "../../Models/Headers/Bonus.h"
#include "../../Models/Headers/Window.h"

namespace SDL
{
    class SDLBonus:public Abstract::Bonus {
        public:
            SDLBonus(double xPos, double yPos, double width, double height, Bonus_type type, Abstract::Window* window);
            ~SDLBonus();
            void render();
            Sprite getSpriteType();

        private:
            Abstract::Window* m_window;

    };

}


#endif //SPACEINVADERS_SDLBONUS_H
