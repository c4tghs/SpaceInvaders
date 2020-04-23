//
// Created by cliff on 14/04/2020.
//

#ifndef PROJECT_BONUS_H
#define PROJECT_BONUS_H

#include "Entity.h"

namespace GameNs{
    enum BonusType{SPEED,LIFE, POINTS};

    class Bonus:public Entity {
        public:
            Bonus();
            Bonus(int xPos, int yPos, int width, int height, BonusType bonusType);
            virtual void render()=0;
            virtual void close()=0;
            BonusType getBonusType();
            void setBonusType(BonusType bonusType);

        private:
            BonusType m_bonusType=POINTS;
    };

}


#endif //PROJECT_BONUS_H
