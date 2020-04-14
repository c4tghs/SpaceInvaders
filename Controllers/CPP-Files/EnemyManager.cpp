/**
 * CPP file for EnemyManager class
 */

#include "../Headers/EnemyManager.h"

//seed random number generator
std::random_device GameNs::EnemyManager::m_rd;

/**
 * Constructor
 */
GameNs::EnemyManager::EnemyManager() {}
/**
 *EnemyManager constructor
 * @param AF - abstract factory used to create instances of enemy ships
 * @param enemyShipPath - path to image of enemyShip
 * @param screenHeight - height of screen
 * @param screenWidth - width of screen
 */
GameNs::EnemyManager::EnemyManager(AbstractFactory *AF, int screenWidth, int screenHeight, BulletManager *bulletManager,
                                   Timer *timer)
{
    m_factory = AF;
    m_timer =timer;
    m_screenWidth = screenWidth;
    m_screenHeight = screenHeight;
    m_bulletManager = bulletManager;
    m_playerYPos = m_screenHeight-((m_screenHeight/10)+10);
    //get current time and add random between 1 and 3 to it
    m_nextMissile = m_timer->getTime()+ randomNumber(0, 0);
    //create 50 bullets
    m_bullets.reserve(100);
    createBullets();
    //create enemies
    createEnemies(30);

    //create player score
    m_score = AF->createScore();
    //set player score to 0
    m_score->setScores(0);

}
/**
 * Method used to create enemy instances
 * @param number - number of enemy instances to create
 */
void GameNs::EnemyManager::createEnemies(int number) {
    m_enemyShips.reserve(number);
    for(int y =0; y < number;y++)
    {
        int xPos = ((y%10)*70)+100;
        int yPos=((y/10)*50)+70;

        if(y < 10)
        {
            m_enemyShips.emplace_back(m_factory->createEnemyShip(m_enemyShipOctopusPath, xPos, yPos));
            //set enemy type
            m_enemyShips[y]->setEnemyType(Octopus);
        } else if (y >= 10 && y < 20)
        {
            m_enemyShips.emplace_back(m_factory->createEnemyShip(m_enemyShipCrabPath, xPos, yPos));
            //set enemy type
            m_enemyShips[y]->setEnemyType(Crab);
        } else
        {
            m_enemyShips.emplace_back(m_factory->createEnemyShip(m_enemyShipSquidPath, xPos, yPos));
            //set enemy type
            m_enemyShips[y]->setEnemyType(Squid);
        }

    }
}

/**
 * Method to update enemies, ie direction, rendering
 */
void GameNs::EnemyManager::updateEnemies() {
    moveEnemies();
    //update time
    m_timer->update();
    if(checkEnemyBoundaries())
    {
        for(auto & m_enemyShip : m_enemyShips)
        {
            int moveDirection = m_enemyShip->getMoveDirection();
            if(moveDirection==1)
            {
                moveDirection = -1;
            }
            else{
                moveDirection = 1;
            }
            m_enemyShip->setMoveDirection(moveDirection);
            m_enemyShip->setXPosition(m_enemyShip->getXPosition());
            m_enemyShip->setYPosition(m_enemyShip->getYPosition()+10);
        }
    }
    int i = 0;
    for(auto & m_enemyShip : m_enemyShips)
    {
        //check collision with player bullet
        if(m_bulletManager->getPlayerBulletFired())
        {
            if(CollisionManager::checkCollision(m_bulletManager->getPlayerBullet(), m_enemyShip->getXPosition(), m_enemyShip->getYPosition(), m_enemyShip->getWidth(), m_enemyShip->getHeight()))
            {
                //player score
                if(m_enemyShip->getEnemyType() == EnemyType::Squid)
                {
                    m_score->setScores(m_score->getScores()+1);
                } else if (m_enemyShip->getEnemyType() == EnemyType::Crab)
                {
                    m_score->setScores(m_score->getScores()+3);
                }
                else if(m_enemyShip->getEnemyType() == EnemyType::Octopus)
                {
                    m_score->setScores(m_score->getScores()+5);
                }

                //close enemy ship, ie destory texture
                m_enemyShip->close();

                //remove ship from vector
                m_enemyShips.erase(m_enemyShips.begin()+i);
                m_bulletManager->setPlayerBulletFired(false);
                m_bulletManager->setPlayerBulletCollision(true);
                return; //execute once
            }
        }

        i++;
        m_enemyShip->render();
    }
    //allow enemy to shoot
    enemyShoot();
    //show player score
    m_score->render();
 }
/**
 * Method to move enemies across screen
 */
void GameNs::EnemyManager::moveEnemies(){
    for(auto & m_enemyShip : m_enemyShips){
        m_enemyShip->setXPosition(m_enemyShip->getXPosition()+ m_timer->getDeltaTime()*m_enemyShip->getMoveDirection());
    }
}
/**
 * Method to check if an enemy has hit a boundary
 * @return True of False
 */
bool GameNs::EnemyManager::checkEnemyBoundaries() {
    for(auto & m_enemyShip : m_enemyShips) {
        if((m_enemyShip->getXPosition() <= 0 ) or (m_enemyShip->getXPosition() >= m_screenWidth-m_enemyShip->getWidth())){
            return true;
        }
    }
    return false;
}

/**
 * Method that allows an enemy to shoot
 */
void GameNs::EnemyManager::enemyShoot() {
    if(m_timer->getTime() < m_nextMissile/2)
    {
        return;
    }
    if(m_enemyShips.empty())
    {
        return;
    }
    //generate random number -> enemy to select
    int randomId = randomNumber(0,m_enemyShips.size());

    for(int i =0; i < m_bullets.size();)
    {
        m_bullets[i]->setXPosition(m_enemyShips[randomId]->getXPosition()+20);
        m_bullets[i]->setYPosition(m_enemyShips[randomId]->getYPosition());
        if(m_bulletManager->getEnemyBulletFired())
        {
            break;
        }
        m_bulletManager->setEnemyBulletFired(true);
        m_bulletManager->setEnemyBullet(m_bullets[i]);
        m_bullets.erase(m_bullets.begin()+i);
        break;
    }
    if(m_bullets.size()==1)
    {
        createBullets();
    }
    m_nextMissile = m_timer->getTime()+ randomNumber(0, 0);
}

void GameNs::EnemyManager::createBullets() {
    for(int i =0; i<50;i++)
    {
        m_bullets.emplace_back(m_factory->createBullet(m_bulletPath,i+50,i+50));
    }
}

void GameNs::EnemyManager::close() {
    for(auto & enemyShip : m_enemyShips)
    {
        enemyShip->close();
    }
}
/**
 * Method to generate random number
 * @return - the generated random number
 */
int GameNs::EnemyManager::randomNumber(int lowerBound, int higherBound) {
    std::mt19937 mt(m_rd());
    std::uniform_real_distribution<double> m_dist(lowerBound,higherBound);
    return m_dist(mt);
}




