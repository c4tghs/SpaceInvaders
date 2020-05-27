#include "../Headers/Bullet.h"

/**
 * Constructor for Bullet
 * @param xPos - x position of bullet
 * @param yPos - y position of bullet
 * @param width - width of bullet
 * @param height - height of bullet
 */
Abstract::Bullet::Bullet(double xPos, double yPos, double width, double height): Abstract::Entity(xPos, yPos, width, height) {}
/**
 * Destructor
 */
Abstract::Bullet::~Bullet() {}