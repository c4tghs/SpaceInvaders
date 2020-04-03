/**
 * EnemyManager class
 * Method for managing enemies
 */

#ifndef PROJECT_ENEMYMANAGER_H
#define PROJECT_ENEMYMANAGER_H


#include "../../Factories/AbstractFactory.h"
#include "../../SDL/Headers/SDLTimer.h"
#include <vector>

namespace GameNs
{
    class EnemyManager {
    public:
        EnemyManager();
        EnemyManager(AbstractFactory* AF,std::string enemyShipPath, int screenWidth);
        void createEnemies(int number);
        std::vector<Ship *> getEnemies();
        void updateEnemies();
        void moveEnemies();
        bool checkEnemyBoundaries();

    private:
        AbstractFactory* m_factory;
        std::vector<Ship *> m_enemyShips;
        std::string m_enemyShipPath;
        Timer *m_timer;
        int m_screenWidth;
    };
}



#endif //PROJECT_ENEMYMANAGER_H
