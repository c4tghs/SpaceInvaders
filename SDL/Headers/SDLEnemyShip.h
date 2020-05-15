#ifndef SPACEINVADERS_SDLENEMYSHIP_H
#define SPACEINVADERS_SDLENEMYSHIP_H

#include "../../Models/Headers/EnemyShip.h"
#include "../../Models/Headers/Window.h"

namespace SDL
{
    class SDLEnemyShip: public Abstract::EnemyShip {
    public:
        SDLEnemyShip(Abstract::Window* window,double xPos, double yPos, double width, double height);
        ~SDLEnemyShip();
        void render();

    private:
        Abstract::Window* m_window;

    };
}



#endif //SPACEINVADERS_SDLENEMYSHIP_H
