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
            BonusManager(AbstractFactory *AF, Timer *timer, CollisionDetector *collisionDetector,
                         ConfigHandler *configHandler,PlayerManager *playerManager, Score *score);
            ~BonusManager();
            void update();
            void render();
            void createBonuses();
            void moveBonus();
            void selectBonus();
            void checkCollisions();


        private:
            Timer* m_timer= nullptr;
            PlayerShip* m_playerShip= nullptr;
            std::vector<Bonus *> m_bonuses;
            AbstractFactory* m_factory=nullptr;
            int m_screenWidth=0;
            int m_screenHeight=0;
            float m_nextBonus=0.0;
            bool m_moveBonus = false;
            int m_bonusSpeed=0;
            int m_randomId=0;
            PlayerLife* m_playerLife=nullptr;
            Score* m_playerSCore=nullptr;
            CollisionDetector* m_collisionDetector= nullptr;
            ConfigHandler* m_configHandler= nullptr;
            std::string m_pathBonusLife="../assets/life.jpg";
            std::string m_pathBonusSpeed="../assets/speed.jpg";
            std::string m_pathBonusPoints="../assets/points.png";

    };
}



#endif //PROJECT_BONUSMANAGER_H
