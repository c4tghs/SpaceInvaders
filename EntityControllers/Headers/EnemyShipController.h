#ifndef SPACEINVADERS_ENEMYSHIPCONTROLLER_H
#define SPACEINVADERS_ENEMYSHIPCONTROLLER_H


#include "../../Factories/Factory.h"
#include "../../Models/Headers/EnemyShip.h"

class EnemyShipController {
public:
    EnemyShipController(Abstract::Factory* factory, Abstract::Controller* controller, Abstract::Timer* timer);
    ~EnemyShipController();
    void update();
    void createEnemies();
    bool checkBoundaries();

private:
    Abstract::Factory* m_factory= nullptr;
    Abstract::Controller* m_controller= nullptr;
    Abstract::Timer* m_timer = nullptr;
    std::vector<Abstract::EnemyShip *> m_enemyShips;
};


#endif //SPACEINVADERS_ENEMYSHIPCONTROLLER_H
