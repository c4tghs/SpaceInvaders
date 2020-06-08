#include <iostream>
#include "Game.h"
#include "Configuration.h"

//static variable
Game* Game::m_instance = nullptr;


/**
 * Method that returns instance of Game
 * @param AF - Abstract factory class
 * @return Game object
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
    delete m_playership;
    delete m_playerBullet;

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
    createStartObjects();
    while (m_controller->isRunning())
    {

        //Update timer
        m_timer->update();
        if(m_playership->getLives() <= 0)
        {
            //show end score
        }
        else if (m_levelCompleted)
        {
            m_levelCompleted = false;
            m_enemySpeedBoost = 0;
            m_currentGameLevel++;
            if(m_currentGameLevel <= 3)
            {
                m_enemyShips.clear();
                createEnemies();
            }
            else
            {
                 // show end score
            }
        }
        if(m_timer->getDeltaTime() >= 1.0/Constants::FRAME_RATE)
        {
            m_window->refresh();
            this->handlePlayerShip();
            this->moveBullets();
            this->handleEnemyShips();
            this->handleCollision();

            m_window->showScore(m_playership->getScore());
            m_window->showLives(m_playership->getLives());
            m_window->showLevel(m_currentGameLevel);
            m_window->render();

            //Reset timer
            m_timer->reset();
        }
        m_controller->pollEvents();
    }

}

/**
 * Method used to create game start objects ie controller, enemies, player ship etc.
 */
void Game::createStartObjects() {
    //Create controller
    m_controller = m_factory->createController();
    m_controller->setWindow(m_window);

    //Create timer
    m_timer = m_factory->createTimer();

    //Create enemies
    this->createEnemies();

    //Create playership
    m_playership = m_factory->createPlayerShip(Constants::WINDOW_WIDTH / 2.0, (Constants::WINDOW_HEIGHT - Constants::PLAYER_SIZE * Constants::SCALE_Y), Constants::PLAYER_SIZE * Constants::SCALE_X, Constants::PLAYER_SIZE * Constants::SCALE_Y, m_window);
    m_playership->setScore(0);
    m_playership->setLives(Constants::PLAYER_LIVES);

    m_nextEnemyBullet = m_timer->getTime()+Abstract::RandomNumber::getInstance().getRandomDouble(0,2);
}

/**
 * Method to create enemies
 */
void Game::createEnemies() {
    m_enemyShips.reserve(Constants::LEVELS[m_currentGameLevel]["ENEMIES"]);

    for(int i=0; i < 10; i++)
    {

        m_enemyShips.emplace_back(m_factory->createEnemyShip(50 * i * Constants::SCALE_X, 50 * Constants::SCALE_Y,Constants::ENEMY_SIZE*Constants::SCALE_X, Constants::ENEMY_SIZE*Constants::SCALE_Y, m_controller->getWindow(), OCTOPUS));
        m_enemyShips.emplace_back(m_factory->createEnemyShip(50 * i * Constants::SCALE_X, 2 * 50 * Constants::SCALE_Y,Constants::ENEMY_SIZE*Constants::SCALE_X,Constants::ENEMY_SIZE*Constants::SCALE_Y, m_controller->getWindow(), CRAB));
        m_enemyShips.emplace_back(m_factory->createEnemyShip(50 * i * Constants::SCALE_X, 3 * 50 * Constants::SCALE_Y,Constants::ENEMY_SIZE*Constants::SCALE_X,Constants::ENEMY_SIZE*Constants::SCALE_Y, m_controller->getWindow(), SQUID));
        if(m_currentGameLevel>1)
        {
            if(m_currentGameLevel < 3 )
            {
                m_enemyShips.emplace_back(m_factory->createEnemyShip(50 * i * Constants::SCALE_X, 4 * 50 * Constants::SCALE_Y,Constants::ENEMY_SIZE*Constants::SCALE_X,Constants::ENEMY_SIZE*Constants::SCALE_Y, m_controller->getWindow(), SQUID));
            }
            else
            {
                m_enemyShips.emplace_back(m_factory->createEnemyShip(50 * i * Constants::SCALE_X, 4 * 50 * Constants::SCALE_Y,Constants::ENEMY_SIZE*Constants::SCALE_X,Constants::ENEMY_SIZE*Constants::SCALE_Y, m_controller->getWindow(), SQUID));
                m_enemyShips.emplace_back(m_factory->createEnemyShip(50 * i * Constants::SCALE_X, 5 * 50 * Constants::SCALE_Y,Constants::ENEMY_SIZE*Constants::SCALE_X,Constants::ENEMY_SIZE*Constants::SCALE_Y, m_controller->getWindow(), SQUID));

            }
        }
    }
}

/**
 * Method to move enemies
 */
void Game::handleEnemyShips() {
    //Move enemyships
    for(auto & enemyShip : m_enemyShips) {
        enemyShip->moveEntity(enemyShip->getXPosition() + (m_timer->getDeltaTime() * enemyShip->getMoveDirection() *  (Constants::ENEMY_SPEED+m_enemySpeedBoost)* Constants::SCALE_X),enemyShip->getYPosition());
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
    int randomId = Abstract::RandomNumber::getInstance().getRandomInt(0,m_enemyShips.size());
    if(m_timer->getTime() > m_nextEnemyBullet)
    {
        m_enemyBullets.emplace_back(m_factory->createBullet(m_enemyShips[randomId]->getXPosition(),m_enemyShips[randomId]->getYPosition(),Constants::BULLET_SIZE * Constants::SCALE_X, Constants::BULLET_SIZE * Constants::SCALE_Y, m_controller->getWindow(), ENEMY));
        m_nextEnemyBullet = m_timer->getTime()+Abstract::RandomNumber::getInstance().getRandomInt(0,2);
    }
    for(auto & enemyShip : m_enemyShips)
    {
        enemyShip->render();
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
 * Method to handle player
 */
void Game::handlePlayerShip() {
    //Player move left
    if(m_controller->isPressed(MOVE_LEFT))
    {
        //Player ship has reached right border
        if(m_playership->getXPosition() < 0)
        {
            m_playership->moveEntity(m_playership->getXPosition(),m_playership->getYPosition());
        }
        else
        {
            //200 pixels to move per second
            m_playership->moveEntity(m_playership->getXPosition()-(m_timer->getDeltaTime()*Constants::PLAYER_SPEED*Constants::SCALE_X),m_playership->getYPosition());
        }
    }
    //Player move right
    if (m_controller->isPressed(MOVE_RIGHT))
    {
        //Player ship has reached right border
        if(m_playership->getXPosition() >= Constants::WINDOW_WIDTH-m_playership->getWidth())
        {
            m_playership->moveEntity(m_playership->getXPosition(),m_playership->getYPosition());
        }
        else
        {
            m_playership->moveEntity(m_playership->getXPosition()+(m_timer->getDeltaTime()*Constants::PLAYER_SPEED*Constants::SCALE_X),m_playership->getYPosition());
        }
    }
    //Player shoot
    if (m_controller->isPressed(PLAYER_SHOOT))
    {
        this->playerShoot();
    }
    //Render player ship
    m_playership->render();

}

/**
 * Method that allows player to shoot
 */
void Game::playerShoot() {
    //Create bullet if a bullet does not exist
    if(m_playerBullet == nullptr)
    {
        m_window->playSound(SHOOT);
        m_playerBullet = m_factory->createBullet(m_playership->getXPosition(), m_playership->getYPosition(), Constants::BULLET_SIZE * Constants::SCALE_X, Constants::BULLET_SIZE * Constants::SCALE_Y, m_controller->getWindow(), PLAYER);
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
            m_playerBullet->moveEntity(m_playerBullet->getXPosition(), m_playerBullet->getYPosition() - m_timer->getDeltaTime() * Constants::BULLET_SPEED * Constants::SCALE_Y);
        }

        m_playerBullet->render();
    }
    int a=0;
    for(auto &bullet:m_enemyBullets)
    {
        if(bullet->getYPosition() > Constants::WINDOW_HEIGHT-bullet->getHeight())
        {
            printf("Y position is bigger\n");
            delete bullet;
            m_enemyBullets.erase(m_enemyBullets.begin()+a);
            return;
        }
        else
        {
            bullet->moveEntity(bullet->getXPosition(),bullet->getYPosition()+ m_timer->getDeltaTime() * Constants::BULLET_SPEED * Constants::SCALE_Y);
            bullet->render();
        }
        a++;
    }
}

/**
 * Method used to handle collisions
 */
void Game::handleCollision()
{
    int a=0;
    if(m_playerBullet != nullptr)
    {
        for(auto &enemyShip:m_enemyShips)
        {
            if(isCollision(m_playerBullet,enemyShip))
            {
                //Play sound
                m_window->playSound(INVADER_KILLED);
                //set player score based on enemy type
                switch (enemyShip->getEnemyType())
                {
                    case OCTOPUS:
                        m_playership->setScore(m_playership->getScore()+50);
                        break;
                    case CRAB:
                        m_playership->setScore(m_playership->getScore()+20);
                        break;
                    case SQUID:
                        m_playership->setScore(m_playership->getScore()+10);
                        break;
                    case UFO:
                        m_playership->setScore(m_playership->getScore()+100);
                        break;
                    default:
                        break;
                }
                delete enemyShip;
                m_enemyShips.erase(m_enemyShips.begin()+a);
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
            a++;


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





