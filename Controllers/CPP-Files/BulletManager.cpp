//
// Created by cliff on 01/04/2020.
//

#include "../Headers/BulletManager.h"
#include "../../SDL/Headers/SDLBullet.h"

GameNs::BulletManager::BulletManager() {}
GameNs::BulletManager::BulletManager(Bullet* bullet,std::string bulletPath,Timer* timer, int screenHeight) {
    m_bullet = bullet;
    m_timer = timer;
    m_bulletPath = bulletPath;
    m_bulletFired = false;
    m_screenHeight = screenHeight;
    //reload();
}
void GameNs::BulletManager::update() {
    if(!m_bulletFired)
    {
        return;
    }
    moveBullet();
    checkBulletBounds();
    m_bullet->render();
    //TODO collision detection
}
void GameNs::BulletManager::moveBullet() {
    m_bullet->setYPosition(m_bullet->getYPosition() + m_timer->getDeltaTime() * m_moveDirection*5);
}
void GameNs::BulletManager::checkBulletBounds() {
    if(m_bullet->getYPosition() < -m_height || m_bullet->getYPosition() > (m_screenHeight + m_height))
    {
        setBulletFired(false);
    }
}

void GameNs::BulletManager::setMoveDirection(int direction)
{
    m_moveDirection = direction;
}
bool GameNs::BulletManager::getBulletFired() {
    return m_bulletFired;
}

void GameNs::BulletManager::setBullet(Bullet* bullet){
    m_bullet = bullet;
}
void GameNs::BulletManager::setBulletFired(bool isFired) {
    m_bulletFired = isFired;
}

