#ifndef SPACEINVADERS_CONSTANTS_H
#define SPACEINVADERS_CONSTANTS_H


#include <map>

enum BONUS_TYPE{
    LIFE, POINTS
};

enum ENEMY_TYPE{
    OCTOPUS,CRAB,SQUID
};

enum KEY{
    MOVE_LEFT, MOVE_RIGHT, PLAYER_SHOOT,NONE
};

enum BULLET_TYPE{
    PLAYER,ENEMY
};

enum SOUND_TYPE{
    SHOOT, HIT, INVADER_KILLED
};
enum SPRITE{
    PLAYERSHIP,ENEMY_BIG_OPEN,ENEMY_BIG_CLOSED,ENEMY_MEDIUM_OPEN,ENEMY_MEDIUM_CLOSED,ENEMY_SMALL_OPEN,ENEMY_SMALL_CLOSED,BONUS_POINTS,PLAYER_BULLET,ENEMY_BULLET,ENEMY_DEAD,BONUS_LIFE
};

enum MODE{
    PLAYING, GAME_OVER
};

class Constants
{
    public:
        static void rescale();
        static int WINDOW_WIDTH;
        static int WINDOW_HEIGHT;
        static const int DEFAULT_WINDOW_WIDTH = 940;
        static const int DEFAULT_WINDOW_HEIGHT = 720;
        static const int PLAYER_SIZE = 50;
        static const int ENEMY_SIZE = 50;
        static const int BULLET_SIZE = 50;
        static const int SPRITE_SIZE = 32;
        static const int BONUS_TIME = 30;
        constexpr static const double SPRITE_SCALE = (PLAYER_SIZE+0.0)/SPRITE_SIZE;
        static int FRAME_RATE;
        static int PLAYER_LIVES;
        static double SCALE_X;
        static double SCALE_Y;
        static std::map<int,std::map<std::string,int>> LEVELS;
};



#endif //SPACEINVADERS_CONSTANTS_H
