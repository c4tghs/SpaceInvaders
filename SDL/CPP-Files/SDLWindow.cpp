#include <iostream>
#include "../Headers/SDLWindow.h"

/**
 * Constructor
 */
SDL::SDLWindow::SDLWindow(const char *title, int screenWidth, int screenHeight) : m_textureManager(nullptr) {
    //m_instance = nullptr;
    m_title = title;
    m_windowHeight = screenHeight;
    m_windowWidth = screenWidth;
}

/**
 * Destructor
 */
SDL::SDLWindow::~SDLWindow() {

    //Destory fonts
    TTF_CloseFont(m_font);

    delete m_textureManager;
    delete m_playerScore;
    delete m_playerLives;
    delete m_level;
    delete m_endScore;

    //Destroy Renderer
    SDL_DestroyRenderer(m_renderer);

    //Destroy background texture
    SDL_DestroyTexture(m_background);

    //Destory Window
    SDL_DestroyWindow(m_window);

    for(auto& iter: m_sounds)
    {
        //free chunk
        Mix_FreeChunk(iter.second);
    }
    //close sound
    Mix_CloseAudio();
    Mix_Quit();


    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

/**
 * Method used to initialise the window
 * @return boolean indicating if window was initialised
 */
bool SDL::SDLWindow::initialise()
{
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) !=0)
    {
        std::cerr << "Failed to initialise SDL: "<< SDL_GetError() << "\n";
        return false;
    }
    else
    {
        //Create window
        m_window = SDL_CreateWindow(m_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_windowWidth, m_windowHeight, SDL_WINDOW_SHOWN);
        //Check if window was created successfully
        if(m_window == nullptr)
        {
            std::cerr << "Failed to create Window." << "\n";
            return false;
        }
        else
        {
            //Create renderer
            m_renderer = SDL_CreateRenderer(m_window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            //Check if renderer was created successfully
            if(m_renderer == nullptr)
            {
                std::cerr << "Failed to create Renderer."<< "\n";
                return false;
            }
            else
            {
                //Initialise PNG, JPG loading
                int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
                if(!(IMG_Init(imgFlags) & imgFlags))
                {
                    std::cerr << "Failed to initialise SDL_image: "<< IMG_GetError() << "\n";
                    return false;
                }

                //Initialise TTF
                if(TTF_Init() < 0)
                {
                    std::cerr << "Unable to initialise TTF library: "<< TTF_GetError() << "\n";
                    return false;
                }

                //Initialise Mixer
                if(Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,2048) <0)
                {
                    std::cerr << "Unable to initialise Mixer: "<< Mix_GetError() << "\n";
                    return false;
                }
            }

        }
    }
    return true;
}

/**
 * Update screen
 */
void SDL::SDLWindow::render() {
    SDL_RenderPresent(m_renderer);
}

/**
 * Method to load media, ie images, sounds, font
 * @return boolean representing successfulness
 */
bool SDL::SDLWindow::loadMedia() {
    //Texture manager for sprite sheet
    m_textureManager = new TextureManager(m_renderer);

    m_bonusLivesTexture = new TextureManager(m_renderer);

    //Text manager for player score
    m_playerScore = new TextManager(m_renderer);

    //Text manager for player lives
    m_playerLives = new TextManager(m_renderer);

    //Text manager for player level
    m_level = new TextManager(m_renderer);

    //Text manager for end score
    m_endScore = new TextManager(m_renderer);

     //Background
    SDL_Surface* backgroundSurface = IMG_Load("../assets/background.png");
    if(backgroundSurface == nullptr)
    {
        std::cout << "Could not load background image. " << IMG_GetError() << "\n";
        return false;
    }
    else
    {
        m_background = SDL_CreateTextureFromSurface(m_renderer,backgroundSurface);
        if(m_background == nullptr)
        {
            std::cout << "Could not create back ground. " << SDL_GetError() << "\n";
        }
        SDL_FreeSurface(backgroundSurface);
    }
    //Load sprite sheet
    if(m_textureManager->loadTexture("../assets/invaders_sheet.png"))
    {
        //Sprite positions and dimensions in sprite sheet
        m_sprites[ENEMY_BIG_CLOSED].x = 160;
        m_sprites[ENEMY_BIG_CLOSED].y = 0;
        m_sprites[ENEMY_BIG_CLOSED].w = 32;
        m_sprites[ENEMY_BIG_CLOSED].h = 32;

        m_sprites[ENEMY_BIG_OPEN].x = 128;
        m_sprites[ENEMY_BIG_OPEN].y = 0;
        m_sprites[ENEMY_BIG_OPEN].w = 32;
        m_sprites[ENEMY_BIG_OPEN].h = 32;

        m_sprites[ENEMY_MEDIUM_CLOSED].x = 96;
        m_sprites[ENEMY_MEDIUM_CLOSED].y = 0;
        m_sprites[ENEMY_MEDIUM_CLOSED].w = 32;
        m_sprites[ENEMY_MEDIUM_CLOSED].h = 32;

        m_sprites[ENEMY_MEDIUM_OPEN].x = 64;
        m_sprites[ENEMY_MEDIUM_OPEN].y = 0;
        m_sprites[ENEMY_MEDIUM_OPEN].w = 32;
        m_sprites[ENEMY_MEDIUM_OPEN].h = 32;

        m_sprites[ENEMY_SMALL_CLOSED].x = 32;
        m_sprites[ENEMY_SMALL_CLOSED].y = 0;
        m_sprites[ENEMY_SMALL_CLOSED].w = 32;
        m_sprites[ENEMY_SMALL_CLOSED].h = 32;

        m_sprites[ENEMY_SMALL_OPEN].x = 0;
        m_sprites[ENEMY_SMALL_OPEN].y = 0;
        m_sprites[ENEMY_SMALL_OPEN].w = 32;
        m_sprites[ENEMY_SMALL_OPEN].h = 32;

        m_sprites[PLAYERSHIP].x = 160;
        m_sprites[PLAYERSHIP].y = 32;
        m_sprites[PLAYERSHIP].w = 32;
        m_sprites[PLAYERSHIP].h = 32;

        m_sprites[PLAYER_BULLET].x = 32;
        m_sprites[PLAYER_BULLET].y = 32;
        m_sprites[PLAYER_BULLET].w = 32;
        m_sprites[PLAYER_BULLET].h = 32;

        m_sprites[ENEMY_BULLET].x = 64;
        m_sprites[ENEMY_BULLET].y = 32;
        m_sprites[ENEMY_BULLET].w = 32;
        m_sprites[ENEMY_BULLET].h = 32;

        m_sprites[BONUS_POINTS].x = 192;
        m_sprites[BONUS_POINTS].y = 0;
        m_sprites[BONUS_POINTS].w = 64;
        m_sprites[BONUS_POINTS].h = 32;

        m_sprites[ENEMY_DEAD].x = 128;
        m_sprites[ENEMY_DEAD].y = 32;
        m_sprites[ENEMY_DEAD].w = 32;
        m_sprites[ENEMY_DEAD].h = 32;
    }
    else
    {
        return false;
    }

    if(!m_bonusLivesTexture->loadTexture("../assets/life.jpg"))
    {
        return false;
    }

    //player shoot sound
    m_sounds[SHOOT] = Mix_LoadWAV("../assets/Sounds/player.wav");
    if(m_sounds[SHOOT] == nullptr)
    {
        std::cerr << "Could not load player shoot sound effect: " << Mix_GetError() << "\n";
        return false;
    }

    //enemy shoot sound
    m_sounds[HIT] = Mix_LoadWAV("../assets/Sounds/enemy.wav");
    if(m_sounds[HIT] == nullptr)
    {
        std::cerr << "Could not load enemy shoot sound effect: " << Mix_GetError() << "\n";
        return false;
    }

    //invader killed sound
    m_sounds[INVADER_KILLED] =Mix_LoadWAV("../assets/Sounds/invader_killed.wav");
    if(m_sounds[INVADER_KILLED] == nullptr)
    {
        std::cerr << "Could not load enemy killed sound effect: " << Mix_GetError() << "\n";
        return false;
    }


    //font
    m_font = TTF_OpenFont("../assets/Font/space_invaders.ttf",23);
    if(m_font == nullptr)
    {
        std::cerr << "Unable to create font: "<< TTF_GetError() << "\n";
        return false;
    }

    m_fontEndScore = TTF_OpenFont("../assets/Font/space_invaders.ttf",50);
    if(m_fontEndScore == nullptr)
    {
        std::cerr << "Unable to create font: "<< TTF_GetError() << "\n";
        return false;
    }

    SDL_RenderClear(m_renderer);
    return true;
}

/**
 * Method to render objects
 * @param sprite  - the sprite type to render
 */
void SDL::SDLWindow::drawRect(Sprite sprite, double xPos, double yPos, double width, double height) {

    if(sprite == BONUS_LIFE)
    {
        m_bonusLivesTexture->renderTexture(xPos,yPos,width,height, nullptr);
    }
    else
    {
        m_textureManager->renderTexture(xPos,yPos,width,height,&m_sprites[sprite]);
    }

}

void SDL::SDLWindow::refresh() {
    SDL_RenderClear(m_renderer);

    //Show background
    SDL_RenderCopy(m_renderer,m_background,nullptr,nullptr);
}

/**
 * Method to player a sound
 * @param sound - the sound to play
 */
void SDL::SDLWindow::playSound(Sound_type sound) {
    //-1: choose appropriate channel
    Mix_PlayChannel(-1, m_sounds[sound], 0);
}

/**
 * Method executed when SDL, window and other elements are not initialised successfully;
 */
void SDL::SDLWindow::exit(const char *message) {
    SDL_Quit();
    throw std::runtime_error(message);
}

/**
 * Method used to show player score
 * @param score - integer representing player score
 */
void SDL::SDLWindow::showScore(int score) {
    SDL_Color color = {255,255,255};

    //Load texture
    if(!(m_playerScore->loadTextTexture(m_font,"SCORE "+std::to_string(score),color)))
    {
        std::cerr << "Failed to load score texture" << "\n";
    }
    m_playerScore->renderText(static_cast<int>(10*Constants::SCALE_X), 0);
}

/**
 * Method used to show player lives
 * @param lives - integer representing player remaining lives
 */
void SDL::SDLWindow::showLives(int lives) {
    SDL_Color color = {255,0,0};

    //Load texture
    if(!(m_playerLives->loadTextTexture(m_font,"Lives "+std::to_string(lives),color)))
    {
        std::cerr << "Failed to load lives texture" << "\n";
    }
    m_playerLives->renderText(static_cast<int>(Constants::WINDOW_WIDTH-(m_playerLives->getSurfaceWidth()*Constants::SCALE_X)), 0);

}
/**
 * Method used to show current game level
 * @param level - integer representing current game level
 */
void SDL::SDLWindow::showLevel(int level) {
    SDL_Color color= {173,255,47};
    if(!m_level->loadTextTexture(m_font,"Level "+std::to_string(level),color))
    {
        std::cerr << "Failed to load level texture" << "\n";
    }
    m_level->renderText(static_cast<int>(Constants::WINDOW_WIDTH/2), 0);
}

/**
 * Method used to score end score
 * @param score - integer representing the score to show
 */
void SDL::SDLWindow::showEndScore(int score)
{
    SDL_Color  color = {255,0,0};
    if(!m_endScore->loadTextTexture(m_fontEndScore,"SCORE "+std::to_string(score),color))
    {
        std::cerr << "Failed to load end score texture" << "\n";
    }
    m_endScore->renderText(static_cast<int>((Constants::WINDOW_WIDTH/2)-((m_endScore->getSurfaceWidth()/2)*Constants::SCALE_X)),Constants::WINDOW_HEIGHT/2);
}





