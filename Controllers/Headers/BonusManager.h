//
// Created by cliff on 14/04/2020.
//

#ifndef PROJECT_BONUSMANAGER_H
#define PROJECT_BONUSMANAGER_H

#include "../../Factories/AbstractFactory.h"
#include "PlayerManager.h"

namespace GameNs{
    class BonusManager {
        public:
            BonusManager();
            BonusManager(AbstractFactory* AF, PlayerManager* playerManager, PlayerLife* playerLife, Score* score,
                         Timer* timer,
                         int screenWidth, int screenHeight);
            void update();
            void render();
            void createBonuses();
            void moveBonus();
            void selectBonus();
            void checkCollisions();
            void close();


        private:
            Timer* m_timer= nullptr;
            PlayerShip* m_playerShip= nullptr;
            std::vector<Bonus *> m_bonuses;
            AbstractFactory* m_factory=nullptr;
            int m_screenWidth=0;
            int m_screenHeight=0;
            float m_nextBonus=0.0;
            bool m_moveBonus = false;
            int m_randomId=0;
            PlayerLife* m_playerLife=nullptr;
            Score* m_playerSCore=nullptr;
            std::string m_bonusLife="../assets/life.jpg";
            std::string m_bonusSpeed="../assets/speed.jpg";
            std::string m_bonusPoints="../assets/points.png";

    };
}



#endif //PROJECT_BONUSMANAGER_H
