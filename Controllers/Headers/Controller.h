#pragma once

#ifndef SPACEINVADERS_CONTROLLER_H
#define SPACEINVADERS_CONTROLLER_H

#include <vector>
#include "../../Enums.h"
#include "../../Models/Headers/Window.h"

namespace Abstract
{
    class Controller {
    public:
        Controller()=default;
        virtual ~Controller()=default;
        virtual bool isRunning()=0;
        virtual PLAYER_ACTION getEvent()=0;
        void setWindow(Abstract::Window* window);
        Abstract::Window* getWindow();

    private:
        Abstract::Window* m_window= nullptr;

    };



}



#endif //SPACEINVADERS_CONTROLLER_H
