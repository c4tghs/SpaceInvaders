//
// Created by cliff on 08/03/2020.
//

#include "../Headers/PlayerShip.h"

/**
 * Constructor for PlayerShip
 * @param xPos - x position of ship
 * @param yPos - y position of ship
 * @param width - width of ship
 * @param height - height of ship
 */
Abstract::PlayerShip::PlayerShip(double xPos, double yPos, double width, double height): Entity(xPos, yPos, width, height) {}

/**
 * Destructor
 */
Abstract::PlayerShip::~PlayerShip(){}

