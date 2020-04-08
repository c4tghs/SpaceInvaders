//
// Created by cliff on 14/03/2020.
//

#include "../Headers/SDLKeyStates.h"
/**
 * Constructor for SDLKeyStates
 */
SDLNs::SDLKeyStates::SDLKeyStates(){}
/**
 * Method to return the pressed key
 * @return - integer
 */
int SDLNs::SDLKeyStates::directions() {
    SDL_Event event;
    SDL_PollEvent(&event);

  const  Uint8* keystate = SDL_GetKeyboardState(nullptr);
  if(keystate[SDL_SCANCODE_LEFT])
  {
      return 1;
  }
  else if(keystate[SDL_SCANCODE_RIGHT]){
      return 2;
  }
  else if(keystate[SDL_SCANCODE_SPACE])
  {
      return 3;
  }
  return  0;
}