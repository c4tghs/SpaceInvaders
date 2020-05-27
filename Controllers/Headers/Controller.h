#pragma once

#ifndef SPACEINVADERS_CONTROLLER_H
#define SPACEINVADERS_CONTROLLER_H

#include <vector>
#include "../../Constants.h"
#include "../../Models/Headers/Window.h"

namespace Abstract
{
    class Controller {
    public:
        Controller()=default;
        virtual ~Controller()=default;
        virtual void pollEvents()=0;
        virtual bool isPressed(KEY key)=0;
        void setWindow(Abstract::Window* window);
        virtual bool isRunning()=0;
        Abstract::Window* getWindow();

    private:
        Abstract::Window* m_window= nullptr;
    protected:
        //bool m_isRunning = true;

    };




}



#endif //SPACEINVADERS_CONTROLLER_H
