#ifdef LINUX
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//#include <SDL2/SDL_ttf.h>
//#include <SDL2/SDL_mixer.h>
#endif

#ifdef WINDOWS
#include "SDL_win\SDL.h"
#include "SDL_win\SDL_image.h"
#endif

#include <stdio.h>
#include <time.h> //for time to seed rand
#include <stdlib.h> //for rand

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

//needed for Windows
#ifdef main
#undef main
#endif 

int main() {
    SDL_Window *Window = NULL;

    SDL_Renderer *WindowRenderer = NULL;
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize: %s\n", SDL_GetError());
        return -1;
    }
    
    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        printf("Linear tecture filtering not enabled.\n");
    }

    Window = SDL_CreateWindow("Space Murder",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);

    if(NULL == Window) {
        printf("Window could not be created: %s\n", SDL_GetError());
        return -1;
    }

    WindowRenderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(NULL == WindowRenderer) {
        printf("Renderer could not be created: %s\n", SDL_GetError());
        return -1;
    }

    SDL_SetRenderDrawColor(WindowRenderer, 0, 0, 0, 0xFF);

    int imgFlags = IMG_INIT_PNG;
    if(!(IMG_Init(imgFlags) & imgFlags)) {
        printf("SDL_image cuold not initialize: %s\n", IMG_GetError());
        return -1;
    }

    int keep_going = 1;
    SDL_Event Event;

    while(keep_going) {
        while(SDL_PollEvent(&Event) != 0) {
            if(Event.type == SDL_QUIT) {
                keep_going = 0;
            }
            else if(Event.type == SDL_KEYDOWN && Event.key.repeat == 0) {
                switch(Event.key.keysym.sym) {

                }
            }
            //If a key was released
            else if(Event.type == SDL_KEYUP && Event.key.repeat == 0) {
                //Adjust the velocity
                switch(Event.key.keysym.sym) {

                }
            }
        }
        
        SDL_RenderClear(WindowRenderer);       
        
        SDL_RenderPresent(WindowRenderer);
    }
    
    return 0;
}
