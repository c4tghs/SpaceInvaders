//
// Created by cliff on 09/04/2020.
//

#ifndef PROJECT_PLAYERLIFE_H
#define PROJECT_PLAYERLIFE_H

namespace Abstract{
    class PlayerLife {
        public:
            PlayerLife();
            virtual ~PlayerLife();
            int getPlayerLife();
            void setPlayerLife(int life);
            virtual void render()=0;

        private:
            int m_playerLife = 0;
    };

}


#endif //PROJECT_PLAYERLIFE_H
