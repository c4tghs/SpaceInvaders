#include <iostream>
#include "Game.h"
#include "Configuration.h"

//static variable
Game* Game::m_instance = nullptr;


/**
 * Method that returns instance of Game
 * @param AF - Abstract factory class
 * @return Game object instance
 */
Game* Game::getInstance(Abstract::Factory* AF) {
    if(m_instance == nullptr)
    {
        m_instance = new Game(AF);
    }
    return m_instance;
}

/**
 * Destructor
 */
Game::~Game() {
    //Deallocate memory
    delete m_timer;
    delete m_playerShip;
    delete m_playerBullet;
    delete m_bonusPoints;
    delete m_bonus;

    for(auto & enemyShip : m_enemyShips)
    {
        delete enemyShip;
    }
    for(auto &bullet:m_enemyBullets)
    {
        delete bullet;
    }
    delete m_controller;
    delete m_window;

}

/**
 * Method to destroy game instance
 */
void Game::destroyGame() {
    delete m_instance;
}
/**
 * Constructor
 * @param AF - abstract factory to create instances of objects
 */
Game::Game(Abstract::Factory* AF) {
    m_factory = AF;

    //Load configuration
    Configuration::load();

    //Create window
    m_window = m_factory->createWindow("Space invaders",Constants::WINDOW_WIDTH,Constants::WINDOW_HEIGHT);

    if(m_window->initialise())
    {
        if(m_window->loadMedia())
        {
            std::cout << "Initialised and loaded media successfully\n";
        }
        else{
            m_window->exit("Failed to load media");
        }
    }
    else
    {
        m_window->exit("Initialisation failed");
    }


}
/**
 * Method that holds the game's main loop
 */
void Game::run() {
    //Set game mode
    m_gameMode = playing;

    createStartObjects();

    while (m_controller->isRunning())
    {

        //Update timer
        m_timer->update();

        //If all enemies are killed
        if (m_levelCompleted)
        {
            m_levelCompleted = false;
            m_enemySpeedBoost = 0;
            m_currentGameLevel++;
            if(m_currentGameLevel <= 3)
            {
                createEnemies();
            }
            else
            {
                m_gameMode = gameOver;
            }
        }
        if(m_timer->getDeltaTime() >= 1.0/Constants::FRAME_RATE)
        {
            //Clear window -> show background
            m_window->refresh();

            if(m_gameMode == playing)
            {
                this->handlePlayerShip();
                this->moveBullets();
                this->handleEnemyShips();
                this->handleBonuses();
                this->handleCollision();

                m_window->showScore(m_playerShip->getScore());
                m_window->showLives(m_playerShip->getLives());
                m_window->showLevel(m_currentGameLevel);
            }
            else
            {
                //Game end. Show player total score
                m_window->showEndScore(m_playerShip->getScore());
            }

            // Draw everything on window
            m_window->render();

            //Reset timer
            m_timer->reset();
        }

        //Poll events
        m_controller->pollEvents();
    }

}

/**
 * Method used to create game start objects ie controller, enemies, player ship etc.
 */
void Game::createStartObjects() {
    //Create controller
    m_controller = m_factory->createController();
    //m_controller->setWindow(m_window);

    //Create timer
    m_timer = m_factory->createTimer();

    //Create enemies
    this->createEnemies();

    //Create playership
    m_playerShip = m_factory->createPlayerShip(Constants::WINDOW_WIDTH / 2.0, (Constants::WINDOW_HEIGHT - Constants::PLAYER_SIZE * Constants::SCALE_Y), Constants::PLAYER_SIZE * Constants::SCALE_X, Constants::PLAYER_SIZE * Constants::SCALE_Y, m_window);
    m_playerShip->setScore(0);
    m_playerShip->setLives(Constants::PLAYER_LIVES);

    //Next enemy bullet time
    m_nextEnemyBullet = m_timer->getTime()+Abstract::RandomNumber::getInstance().getRandomDouble(0,Constants::LEVELS[m_currentGameLevel]["ENEMY_SHOOT_TIME"]);

    //Next points bonus time
    m_nextPointBonus = m_timer->getTime() + Abstract::RandomNumber::getInstance().getRandomDouble(0, Constants::BONUS_TIME);

    //Next lives bonus time
    m_nextLivesBonus = m_timer->getTime() + Abstract::RandomNumber::getInstance().getRandomDouble(0, Constants::BONUS_TIME);
}

/**
 * Method to create enemies
 */
void Game::createEnemies() {
    m_enemyShips.reserve(Constants::LEVELS[m_currentGameLevel]["ENEMIES"]);

    for(int i=0; i < 10; i++)
    {

        m_enemyShips.emplace_back(m_factory->createEnemyShip(50 * i * Constants::SCALE_X, 50 * Constants::SCALE_Y,Constants::ENEMY_SIZE*Constants::SCALE_X, Constants::ENEMY_SIZE*Constants::SCALE_Y, m_window, Octopus));
        m_enemyShips.emplace_back(m_factory->createEnemyShip(50 * i * Constants::SCALE_X, 2 * 50 * Constants::SCALE_Y,Constants::ENEMY_SIZE*Constants::SCALE_X,Constants::ENEMY_SIZE*Constants::SCALE_Y, m_window, Crab));
        m_enemyShips.emplace_back(m_factory->createEnemyShip(50 * i * Constants::SCALE_X, 3 * 50 * Constants::SCALE_Y,Constants::ENEMY_SIZE*Constants::SCALE_X,Constants::ENEMY_SIZE*Constants::SCALE_Y, m_window, Squid));
        if(m_currentGameLevel>1)
        {
            if(m_currentGameLevel < 3 )
            {
                m_enemyShips.emplace_back(m_factory->createEnemyShip(50 * i * Constants::SCALE_X, 4 * 50 * Constants::SCALE_Y,Constants::ENEMY_SIZE*Constants::SCALE_X,Constants::ENEMY_SIZE*Constants::SCALE_Y, m_window, Squid));
            }
            else
            {
                m_enemyShips.emplace_back(m_factory->createEnemyShip(50 * i * Constants::SCALE_X, 4 * 50 * Constants::SCALE_Y,Constants::ENEMY_SIZE*Constants::SCALE_X,Constants::ENEMY_SIZE*Constants::SCALE_Y, m_window, Squid));
                m_enemyShips.emplace_back(m_factory->createEnemyShip(50 * i * Constants::SCALE_X, 5 * 50 * Constants::SCALE_Y,Constants::ENEMY_SIZE*Constants::SCALE_X,Constants::ENEMY_SIZE*Constants::SCALE_Y, m_window, Squid));

            }
        }
    }
}

/**
 * Method to handle enemies ie, shooting, moving, drawing
 */
void Game::handleEnemyShips() {
    //Move enemyships
    for(auto & enemyShip : m_enemyShips) {
        enemyShip->moveEntity(enemyShip->getXPosition() + (m_timer->getDeltaTime() * enemyShip->getMoveDirection() *  (Constants::LEVELS[m_currentGameLevel]["ENEMY_SPEED"]+m_enemySpeedBoost)* Constants::SCALE_X),enemyShip->getYPosition());
    }
    if(checkEnemyBoundaries())
    {
        for(auto & enemyShip : m_enemyShips)
        {

            int moveDirection = enemyShip->getMoveDirection();
            if(moveDirection==1)
            {
                moveDirection = -1;
            }
            else
            {
                moveDirection = 1;
            }
            enemyShip->setMoveDirection(moveDirection);
            enemyShip->moveEntity(enemyShip->getXPosition(),enemyShip->getYPosition()+(10*Constants::SCALE_Y));
        }
    }
    // Select random enemy
    int randomId = Abstract::RandomNumber::getInstance().getRandomInt(0,m_enemyShips.size());

    // Check if time for next enemy bullet has been surpassed
    if(m_timer->getTime() > m_nextEnemyBullet)
    {
        m_enemyBullets.emplace_back(m_factory->createBullet(m_enemyShips[randomId]->getXPosition(), m_enemyShips[randomId]->getYPosition(),Constants::BULLET_SIZE * Constants::SCALE_X, Constants::BULLET_SIZE * Constants::SCALE_Y, m_window, enemy));
        m_nextEnemyBullet = m_timer->getTime()+Abstract::RandomNumber::getInstance().getRandomDouble(0,Constants::LEVELS[m_currentGameLevel]["ENEMY_SHOOT_TIME"]);
    }
    // Render enemies
    for(auto & enemyShip : m_enemyShips)
    {
        enemyShip->render();
    }

    //Create point bonus
    if(m_timer->getTime() > m_nextPointBonus)
    {
        m_bonusPoints = m_factory->createBonus(0,25*Constants::SCALE_X,Constants::ENEMY_SIZE*Constants::SCALE_X, Constants::ENEMY_SIZE*Constants::SCALE_Y, m_window,POINTS);
        m_nextPointBonus = m_timer->getTime() + Abstract::RandomNumber::getInstance().getRandomDouble(0, Constants::BONUS_TIME);
    }

    //Create time bonus
    if(m_timer->getTime() > m_nextLivesBonus)
    {
        printf("-----------Time has passed-----------\n");
        int randomPosition = Abstract::RandomNumber::getInstance().getRandomInt(0,Constants::WINDOW_WIDTH-10);
        m_bonus = m_factory->createBonus(randomPosition,-1,20*Constants::SCALE_X, 20*Constants::SCALE_Y, m_window,LIFE);
        m_nextLivesBonus = m_timer->getTime() + Abstract::RandomNumber::getInstance().getRandomDouble(0, Constants::BONUS_TIME);
    }
}

/**
 * Method to check if an enemy has reached boundary of screen or not
 * @return boolean representing if an enemy has reached boundary of screen
 */
bool Game::checkEnemyBoundaries() {
    for(auto & enemyShip : m_enemyShips)
    {
        if((enemyShip->getXPosition() <= 0 ) or (enemyShip->getXPosition() > Constants::WINDOW_WIDTH-enemyShip->getWidth())){
            return true;
        }
    }
    return false;
}
/**
 * Method to handle player, ie moving, drawing
 */
void Game::handlePlayerShip() {
    //Player move left
    if(m_controller->isPressed(moveLeft))
    {
        //Player ship has reached right border
        if(m_playerShip->getXPosition() < 0)
        {
            m_playerShip->moveEntity(m_playerShip->getXPosition(), m_playerShip->getYPosition());
        }
        else
        {
            //200 pixels to move per second
            m_playerShip->moveEntity(m_playerShip->getXPosition() - (m_timer->getDeltaTime() * Constants::LEVELS[m_currentGameLevel]["PLAYER_SPEED"] * Constants::SCALE_X), m_playerShip->getYPosition());
        }
    }
    //Player move right
    if (m_controller->isPressed(moveRight))
    {
        //Player ship has reached right border
        if(m_playerShip->getXPosition() >= Constants::WINDOW_WIDTH - m_playerShip->getWidth())
        {
            m_playerShip->moveEntity(m_playerShip->getXPosition(), m_playerShip->getYPosition());
        }
        else
        {
            m_playerShip->moveEntity(m_playerShip->getXPosition() + (m_timer->getDeltaTime() * Constants::LEVELS[m_currentGameLevel]["PLAYER_SPEED"] * Constants::SCALE_X), m_playerShip->getYPosition());
        }
    }
    //Player shoot
    if (m_controller->isPressed(Key::playerShoot))
    {
        this->playerShoot();
    }
    //Render player ship
    m_playerShip->render();

}

/**
 * Method that allows player to shoot
 */
void Game::playerShoot() {
    //Create bullet if a bullet does not exist
    if(m_playerBullet == nullptr)
    {
        m_window->playSound(SHOOT);
        m_playerBullet = m_factory->createBullet(m_playerShip->getXPosition(), m_playerShip->getYPosition(), Constants::BULLET_SIZE * Constants::SCALE_X, Constants::BULLET_SIZE * Constants::SCALE_Y, m_window, player);
    }
}

/**
 * Method that is used to move and render player bullet
 */
void Game::moveBullets()
{
    if(m_playerBullet != nullptr)
    {
        //If bullet is out of view
        if(m_playerBullet->getYPosition() <= 0)
        {
            delete m_playerBullet;
            m_playerBullet = nullptr;
            return;
        }
        else
        {
            m_playerBullet->moveEntity(m_playerBullet->getXPosition(), m_playerBullet->getYPosition() - m_timer->getDeltaTime() * Constants::LEVELS[m_currentGameLevel]["BULLET_SPEED"] * Constants::SCALE_Y);
        }

        m_playerBullet->render();
    }

    Abstract::Bullet* bullet;
    for(int i =0; i < m_enemyBullets.size(); i++)
    {
        bullet = m_enemyBullets.at(i);
        if(bullet->getYPosition() > Constants::WINDOW_HEIGHT-bullet->getHeight())
        {
            delete bullet;
            m_enemyBullets.erase(m_enemyBullets.begin()+i);
            return;
        }
        else
        {
            bullet->moveEntity(bullet->getXPosition(),bullet->getYPosition()+ m_timer->getDeltaTime() * Constants::LEVELS[m_currentGameLevel]["BULLET_SPEED"] * Constants::SCALE_Y);
            bullet->render();
        }

    }
}

/**
 * Method used to handle collisions
 */
void Game::handleCollision()
{
    Abstract::EnemyShip* enemy;
    if(m_playerBullet != nullptr)
    {
        for(int i = 0; i< m_enemyShips.size();i++)
        {
            enemy = m_enemyShips.at(i);
            if(isCollision(m_playerBullet,enemy))
            {
                //Play sound
                m_window->playSound(INVADER_KILLED);
                //set player score based on enemy type
                switch (enemy->getEnemyType())
                {
                    case Octopus:
                        m_playerShip->setScore(m_playerShip->getScore() + 50);
                        break;
                    case Crab:
                        m_playerShip->setScore(m_playerShip->getScore() + 20);
                        break;
                    case Squid:
                        m_playerShip->setScore(m_playerShip->getScore() + 10);
                        break;
                    case Ufo:
                        m_playerShip->setScore(m_playerShip->getScore() + 100);
                        break;
                    default:
                        break;
                }
                delete enemy;
                m_enemyShips.erase(m_enemyShips.begin()+i);
                delete m_playerBullet;
                m_playerBullet = nullptr;

                if(m_enemyShips.empty())
                {
                    m_levelCompleted = true;
                }
                if(m_enemyShips.size() ==1)
                {
                    m_enemySpeedBoost +=150;
                }

                //Stop loop
                break;
            }
        }
    }
    Abstract::Bullet* bullet;
    for(int i=0; i < m_enemyBullets.size(); i++)
    {
        bullet = m_enemyBullets.at(i);
        if(isCollision(m_playerShip, bullet))
        {
            m_window->playSound(HIT);
            m_playerShip->setLives(m_playerShip->getLives() - 1);
            if(m_playerShip->getLives() <= 0)
            {
                m_gameMode = gameOver;
            }
            delete bullet;
            m_enemyBullets.erase(m_enemyBullets.begin()+i);
        }
        //Collision between player bullet and enemy bullet
        if(m_playerBullet != nullptr)
        {
            if(isCollision(bullet,m_playerBullet))
            {
                delete bullet;
                m_enemyBullets.erase(m_enemyBullets.begin()+i);
                delete m_playerBullet;
                m_playerBullet = nullptr;
            }
        }

    }
    if(m_bonus != nullptr)
    {
        if(isCollision(m_bonus,m_playerShip))
        {

        }
    }
}

/**
 * Method used to check for collision between two entities
 * @param one - entity one
 * @param two - entity two
 * @return - boolean that says if there is collision
 */
bool Game::isCollision(Abstract::Entity *one, Abstract::Entity *two) {

     double xScale = Constants::SCALE_X*Constants::SPRITE_SCALE;
     double yScale = Constants::SCALE_Y*Constants::SPRITE_SCALE;
     return one->getXPosition()+(Constants::SPRITE_SIZE*xScale) >= two->getXPosition() &&
           one->getXPosition() <= two->getXPosition() + (Constants::SPRITE_SIZE*xScale) &&
           one->getYPosition() + (Constants::SPRITE_SIZE*yScale) >= two->getYPosition() &&
           one->getYPosition() <= two->getYPosition() + (Constants::SPRITE_SIZE*yScale);
}

/**
 * Method used to handle bonuses
 */
void Game::handleBonuses() {
    //Move and render bonus points if it exists
    if(m_bonusPoints != nullptr)
    {
        if(m_bonusPoints->getXPosition() <= Constants::WINDOW_WIDTH-m_bonusPoints->getWidth())
        {
            m_bonusPoints->moveEntity(m_bonusPoints->getXPosition()+(m_timer->getDeltaTime()*Constants::LEVELS[m_currentGameLevel]["BONUS_SPEED"]*Constants::SCALE_X),m_bonusPoints->getYPosition());
            m_bonusPoints->render();
        }
        else
        {
            delete m_bonusPoints;
            m_bonusPoints = nullptr;
        }

    }
    //Move and render lives bonus if it exists
    if(m_bonus != nullptr)
    {
        if(m_bonus->getYPosition() <= Constants::WINDOW_HEIGHT)
        {
            m_bonus->moveEntity(m_bonus->getXPosition(),m_bonus->getYPosition()+(m_timer->getDeltaTime()*Constants::LEVELS[m_currentGameLevel]["BONUS_SPEED"]*Constants::SCALE_Y));
            m_bonus->render();
        }
        else
        {
            delete m_bonus;
            m_bonus = nullptr;
        }
    }

}





