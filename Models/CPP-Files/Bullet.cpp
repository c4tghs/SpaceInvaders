//
// Created by cliff on 23/03/2020.
//

#include "../Headers/Bullet.h"
/**
 * Constructor for Bullet
 */
GameNs::Bullet::Bullet() {}
/**
 * Constructor for Bullet
 * @param xPos - x position of bullet
 * @param yPos - y position of bullet
 * @param width - width of bullet
 * @param height - height of bullet
 */
GameNs::Bullet::Bullet(int xPos, int yPos, int width, int height):GameNs::Entity(xPos,yPos,width,height) {}
/**
 * Destructor
 */
GameNs::Bullet::~Bullet() {}