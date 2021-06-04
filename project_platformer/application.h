#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "player.h"

typedef struct {
    Player *player;
    SDL_Window *m_window;
    SDL_Surface *m_window_surface;
    SDL_Event m_window_event;
} Application;

Application *app_make();
void app_loop(Application *app);
void app_update(Application *app, double t);
void app_draw(Application *app);