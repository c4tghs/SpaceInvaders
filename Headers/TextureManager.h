//
// Created by cliff on 08/03/2020.
//

#ifndef PROJECT_TEXTUREMANAGER_H
#define PROJECT_TEXTUREMANAGER_H

#endif //PROJECT_TEXTUREMANAGER_H

#include "Graphics.h"
class TextureManager{
public:
    static SDL_Texture* LoadTexture(const char* filename,SDL_Renderer* ren);
};