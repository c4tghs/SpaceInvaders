//
// Created by cliff on 14/04/2020.
//

#ifndef PROJECT_BONUS_H
#define PROJECT_BONUS_H

#include "Entity.h"
#include "../../Constants.h"

namespace Abstract{

    class Bonus:public Entity {
        public:
            Bonus(double xPos, double yPos, double width, double height);
            virtual ~Bonus();
            virtual void render()=0;
            Bonus_type getBonusType();


        protected:
            Bonus_type m_bonusType=POINTS;
    };

}


#endif //PROJECT_BONUS_H
