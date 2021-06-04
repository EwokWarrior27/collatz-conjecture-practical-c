#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "application.h"
#include "player.h"
#include "helpers.h"

Player *player_make(void) {
    Player *player = malloc(sizeof(Player));
    
    player->m_image = load_surface("player.bmp");
    player->m_position.x = 0;
    player->m_position.y = 60;
    player->m_position.w = 30;
    player->m_position.h = 30;
    player->m_x = 0.0;
    player->m_y = 0.0;

    return player;
}

void handle_events(Player *player, SDL_Event event) {
    switch(event.type) {
        case SDL_KEYDOWN: {
            const Uint8 *keys = SDL_GetKeyboardState(NULL);
            if(keys[SDL_SCANCODE_UP]) player->m_direction = UP;
            else if(keys[SDL_SCANCODE_DOWN]) player->m_direction = DOWN;
            else if(keys[SDL_SCANCODE_LEFT]) player->m_direction = LEFT;
            else if(keys[SDL_SCANCODE_RIGHT]) player->m_direction = RIGHT;
            break;
        }
        case SDL_KEYUP: {
            player->m_direction = NONE;
        }
    }
}

void player_update(Player *player, double t) {
    switch(player->m_direction)
    {
        case NONE:
            player->m_x += 0.0;
            player->m_y += 0.0;
            break;
        case UP:
            player->m_y -= (5.0 * t);
            break;
        case DOWN:
            player->m_y += (5.0 * t);
            break;
        case LEFT:
            player->m_x -= (5.0 * t);
            break;
        case RIGHT:
            player->m_x += (5.0 * t);
            break;
    }

    player->m_position.x = player->m_x;
    player->m_position.y = player->m_y;
}

void player_draw(Player *player, SDL_Surface *window_surface) {
    SDL_BlitSurface(player->m_image, NULL, window_surface, &player->m_position);
}