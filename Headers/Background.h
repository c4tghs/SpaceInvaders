//
// Created by cliff on 14/03/2020.
//

#ifndef PROJECT_BACKGROUND_H
#define PROJECT_BACKGROUND_H

namespace GameNs
{
    class Background {
    public:
        Background();
        virtual void render()=0;
        virtual void close()=0;
    };
}



#endif //PROJECT_BACKGROUND_H
