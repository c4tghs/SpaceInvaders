//
// Created by cliff on 24/04/2020.
//

#include "../Headers/LevelController.h"

/**
 * Constructor
 */
GameNs::LevelController::LevelController() {}

/**
 * Destructor
 */
GameNs::LevelController::~LevelController() {}

/**
 * Constructor
 * @param AF - abstract factory object
 * @param timer - timer object
 * @param collisionDetector - collision detector object
 * @param configHandler - configuration handler object
 */
GameNs::LevelController::LevelController(AbstractFactory *AF, Timer *timer, CollisionDetector *collisionDetector,
                                         ConfigHandler *configHandler) {
    m_factory = AF;
    m_timer = timer;
    m_configHandler = configHandler;
    m_collisionDetector = collisionDetector;
}


/**
 * Method to set current game level
 * @param level - level
 */
void GameNs::LevelController::setLevel(int level) {
    m_currentLevel = level;
}

/**
 * Update method
 */
void GameNs::LevelController::update() {
    m_playerManager->update();
    m_enemyManager->update();
    m_bulletManager->update();
    m_bonusManager->update();
    m_playerScore->render();
}

/**
 * Method to start new level
 */
void GameNs::LevelController::startLevel() {
    /*switch (m_currentLevel){
        case 1:
            m_configHandler->setLevelParameters("one");
            createObjects();
            break;
        case 2:
            m_configHandler->setLevelParameters("two");
            createObjects();
            break;
        case 3:
            m_configHandler->setLevelParameters("three");
            createObjects();
            break;
        default:
            //Level 3 completed
            m_factory->setRunningState(false);
            break;
    }*/
    if(m_currentLevel == 1)
    {
        m_configHandler->setLevelParameters("one");
        createObjects();
    }
    else if (m_currentLevel == 2)
    {
        m_configHandler->setLevelParameters("two");
        createObjects();
    }
    else if (m_currentLevel == 3)
    {
        m_configHandler->setLevelParameters("three");
        createObjects();
    }
    else{
        //Level 3 completed
        m_factory->setRunningState(false);
    }


}

/**
 * Method to delete objects after completion of level
 */
void GameNs::LevelController::clean() {
    m_playerCurrentScore = m_playerScore->getScores();
    delete m_playerScore;
    delete m_bulletManager;
    delete m_playerManager;
    delete m_enemyManager;
    delete m_bonusManager;
}
/**
 * Method to create objects
 */
void GameNs::LevelController::createObjects() {
    //Create player score
    m_playerScore = m_factory->createScore();
    m_playerScore->setScores(m_playerCurrentScore);
    //Create bullet manager
    m_bulletManager = new BulletManager(m_timer, m_collisionDetector, m_configHandler);
    //Create player manager
    m_playerManager = new PlayerManager(m_factory, m_timer, m_collisionDetector, m_configHandler, m_bulletManager);
    //Create enemy manager
    m_enemyManager = new EnemyManager(m_factory, m_timer, m_collisionDetector, m_configHandler, m_bulletManager,m_playerScore);
    //Create bonus manager
    m_bonusManager = new BonusManager(m_factory, m_timer, m_collisionDetector, m_configHandler, m_playerManager,m_playerScore);
}
