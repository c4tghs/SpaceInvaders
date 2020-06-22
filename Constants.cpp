#include <iostream>
#include "Constants.h"

int Constants::WINDOW_WIDTH = 1080;
int Constants::WINDOW_HEIGHT = 720;
int Constants::FRAME_RATE = 60;
int Constants::PLAYER_LIVES = 3;


double Constants::SCALE_X = (Constants::WINDOW_WIDTH+0.0) / Constants::DEFAULT_WINDOW_WIDTH;
double Constants::SCALE_Y = (Constants::WINDOW_HEIGHT+0.0) / Constants::DEFAULT_WINDOW_HEIGHT;

std::map<int,std::map<std::string,int>> Constants::LEVELS = {};

/**
 * Method used to rescale when configuration is read
 */
void Constants::rescale() {
    Constants::SCALE_X = (Constants::WINDOW_WIDTH+0.0) / Constants::DEFAULT_WINDOW_WIDTH;
    Constants::SCALE_Y = (Constants::WINDOW_HEIGHT+0.0) / Constants::DEFAULT_WINDOW_HEIGHT;
}

