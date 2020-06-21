#include "../Headers/Bonus.h"

/**
 * Constructor
 * @param xPos - initial x position of bonus
 * @param yPos - initial y position of bonus
 * @param width - width of bonus
 * @param height - height of bonus
 */
Abstract::Bonus::Bonus(double xPos, double yPos, double width, double height) : Entity(xPos, yPos, width, height) {}
/**
 * Destructor
 */
Abstract::Bonus::~Bonus() {}


