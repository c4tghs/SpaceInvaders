//
// Created by cliff on 31/03/2020.
//

#ifndef PROJECT_ENEMYMANAGER_H
#define PROJECT_ENEMYMANAGER_H


#include "../Factories/AbstractFactory.h"
#include <vector>

// CREATE METHOD TO RETURN ALL ENEMIES AND RENDER THEM IN GAME LOOP

namespace GameNs
{
    class EnemyManager {
    public:
        EnemyManager();
        EnemyManager(AbstractFactory* AF,std::string enemyShipPath);
        void createEnemies(int number);
        std::vector<Ship *> getEnemies();
        void updateEnemies();


    private:

        AbstractFactory* m_factory;
        std::vector<Ship *> m_enemyShips;
        std::string m_enemyShipPath;
    };
}



#endif //PROJECT_ENEMYMANAGER_H
