#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

typedef enum {NONE, UP, DOWN, LEFT, RIGHT} Direction;

typedef struct {
    SDL_Surface *m_image;
    SDL_Rect m_position;
    double m_x;
    double m_y;
    Direction m_direction;
} Player;

Player *player_make();
void player_update(Player *player, double t);
void player_draw(Player *player, SDL_Surface *window_surface);
void handle_events(Player *player, SDL_Event event);