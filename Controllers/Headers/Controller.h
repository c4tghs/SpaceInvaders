#pragma once

#ifndef SPACEINVADERS_CONTROLLER_H
#define SPACEINVADERS_CONTROLLER_H

#include <vector>
#include "../../Constants.h"

namespace Abstract
{
    class Controller {
    public:
        Controller()=default;
        virtual ~Controller()=default;
        virtual void pollEvents()=0;
        virtual bool isPressed(Key key)=0;

        virtual bool isRunning()=0;



    };




}



#endif //SPACEINVADERS_CONTROLLER_H
