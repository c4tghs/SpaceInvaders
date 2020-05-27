#include <iostream>
#include "Constants.h"
int Constants::WINDOW_WIDTH = 1080;
int Constants::WINDOW_HEIGHT = 720;
double Constants::PLAYER_SPEED = 200;
double Constants::ENEMY_SPEED = 100;
double Constants::BULLET_SPEED = 500;
int Constants::FRAME_RATE = 60;
int Constants::PLAYER_LIVES = 5;


double Constants::SCALE_X = (Constants::WINDOW_WIDTH+0.0) / Constants::DEFAULT_WINDOW_WIDTH;
double Constants::SCALE_Y = (Constants::WINDOW_HEIGHT+0.0) / Constants::DEFAULT_WINDOW_HEIGHT;

std::map<int,std::map<std::string,int>> Constants::LEVELS = {};

/**
 * Method used to rescale
 */
void Constants::rescale() {
    Constants::SCALE_X = (Constants::WINDOW_WIDTH+0.0) / Constants::DEFAULT_WINDOW_WIDTH;
    Constants::SCALE_Y = (Constants::WINDOW_HEIGHT+0.0) / Constants::DEFAULT_WINDOW_HEIGHT;
}

