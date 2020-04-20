/**
 * CPP file of PlayerManager class
 */

#include "../Headers/PlayerManager.h"

/**
 * Method to create instance of PlayerManager
 */
GameNs::PlayerManager::PlayerManager() {}

/**
 * Method to create an instance of PlayerManager
 * @param AF - abstract factory
 * @param playerShipPath - path of player ship image
 * @param bulletPath - path of bullet image
 * @param screenHeight - screen height
 * @param screenWidth - screen width
 */
GameNs::PlayerManager::PlayerManager(GameNs::AbstractFactory *AF, int screenHeight, int screenWidth,
                                     BulletManager *bulletManager,
                                     Timer *timer, PlayerLife *playerLife, CollisionDetector *collisionDetector) {
    m_factory = AF;
    m_timer = timer;
    m_bulletManager = bulletManager;
    m_playerLife = playerLife;
    m_screenHeight = screenHeight;
    m_screenWidth = screenWidth;
    m_collisionDetector = collisionDetector;

    //Create playerShip;
    m_playerShip  = m_factory->createPlayerShip(m_playerShipPath);

    //Reserve memory for 10 bullets
    m_bullets.reserve(10);

    //Create 10 bullets
    createBullets();
}
/**
 * update method
 */
void GameNs::PlayerManager::update() {
    //Move player
    movePlayer();
    //Update timer
    m_timer->update();
    checkPlayerBoundaries();
    //Render player
    m_playerShip->render();
}
/**
 * Method to check what button has pressed and chnage position of player ship
 */
void GameNs::PlayerManager::movePlayer() {
    int direction = m_keyStates->directions();
    int xPos;
    switch(direction)
    {
        case 1:
            //Move player ship left
            xPos = m_playerShip->getXPosition() - m_timer->getDeltaTime() *m_playerShip->getPlayerSpeed();
            m_playerShip->setXPosition(xPos);
            break;
        case 2:
            //Move player ship right
            xPos = m_playerShip->getXPosition() + m_timer->getDeltaTime() *m_playerShip->getPlayerSpeed();
            m_playerShip->setXPosition(xPos);
            break;
        case 3:
            shoot();
            break;
        default:
            break;
    }
}
/**
 * Method used to check player boundaries and collision with enemy bullet
 */
void GameNs::PlayerManager::checkPlayerBoundaries() {
    if(m_playerShip->getXPosition() < 0)
    {
        m_playerShip->setXPosition(0);
    }
    else if(m_playerShip->getXPosition() > m_screenWidth - m_playerShip->getWidth())
    {
        m_playerShip->setXPosition(m_screenWidth - m_playerShip->getWidth());

    }
    //Check collision with enemy bullet, if an enemy bullet has been fired.
    if(m_bulletManager->isEnemyBulletFired())
    {
        if(m_collisionDetector->checkBulletCollision(m_bulletManager->getEnemyBullet(), m_playerShip->getXPosition(),
                                                   m_playerShip->getYPosition(), m_playerShip->getWidth(),
                                                   m_playerShip->getHeight()))
        {
            m_playerLife->setPlayerLife(m_playerLife->getPlayerLife()-1);
            m_bulletManager->setEnemyBulletFired(false);

        }
    }
}
/**
 * Method to destroy player texture and bullets
 */
void GameNs::PlayerManager::close() {
    for(auto & m_bullet : m_bullets)
    {
        m_bullet->close();
    }
    m_playerShip->close();

}
/**
 * Method that allows a player to shoot
 */
void GameNs::PlayerManager::shoot() {
    if(m_bulletManager->isPlayerBulletFired())
    {
        return;
    }

    m_bullets[0]->setXPosition(m_playerShip->getXPosition()+60);
    m_bullets[0]->setYPosition(m_playerShip->getYPosition());
    m_bulletManager->setPlayerBullet(m_bullets[0]);
    m_bulletManager->setPlayerBulletFired(true);

    //Remove bullet from vector
    m_bullets.erase(m_bullets.begin());

    //Create bullets if there're no more bullets left.
    if(m_bullets.empty())
    {
        createBullets();
    }
}

/**
 * Method to create bullets
 */
void GameNs::PlayerManager::createBullets() {
    for(int i =0; i<10;i++)
    {
        //Create bullet and add it to vector.
        m_bullets.emplace_back(m_factory->createBullet(m_bulletPath, m_playerShip->getXPosition(),
                m_playerShip->getYPosition(), 25, 25));

    }
}
/**
 * Method that returns playerShip
 * @return - playerShip
 */
GameNs::PlayerShip *GameNs::PlayerManager::getPlayerShip() {
    return m_playerShip;
}


