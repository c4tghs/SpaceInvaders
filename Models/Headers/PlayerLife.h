//
// Created by cliff on 09/04/2020.
//

#ifndef PROJECT_PLAYERLIFE_H
#define PROJECT_PLAYERLIFE_H

namespace GameNs{
    class PlayerLife {
        public:
            PlayerLife();
            int getPlayerLife();
            void setPlayerLife(int life);
            virtual void close()=0;
            virtual void render()=0;

        private:
            int m_playerLife = 5;
    };

}


#endif //PROJECT_PLAYERLIFE_H
