//
// Created by cliff on 14/04/2020.
//

#ifndef PROJECT_BONUSMANAGER_H
#define PROJECT_BONUSMANAGER_H

#include "../../Factories/AbstractFactory.h"
#include "PlayerManager.h"

namespace GameNs{
    class BonusManager {
        BonusManager();
        BonusManager(AbstractFactory *AF,PlayerManager* playerManager);
        void update();

    };
}



#endif //PROJECT_BONUSMANAGER_H
