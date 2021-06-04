#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "application.h"
#include "helpers.h"
#include "player.h"

Application *app_make(void) {
    Application *app = malloc(sizeof(Application));
    
    app->m_window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680, 480, 0);

    if(!app->m_window)
    {
        printf("Failed to create window\n");
        printf("SDL2 Error: %p\n", SDL_GetError());
        return app;
    }

    app->m_window_surface = SDL_GetWindowSurface(app->m_window);
    if(!app->m_window_surface)
    {
        printf("Failed to get window's surface\n");
        printf("SDL2 Error: %p\n", SDL_GetError());
        return app;
    }
    app->player = player_make();
    return app;
}

void app_loop(Application *app) {
    bool keep_window_open = true;
    while(keep_window_open)
    {
        while(SDL_PollEvent(&app->m_window_event) > 0) {
            handle_events(app->player, app->m_window_event);
            switch(app->m_window_event.type) {
                case SDL_QUIT:
                    keep_window_open = false;
                    break;
                    SDL_FreeSurface(app->m_window_surface);
                    SDL_DestroyWindow(app->m_window);
            }
        }
        app_update(app, 1.0/60.0);
        app_draw(app);
    }
}

void app_update(Application *app, double t) {
    player_update(app->player, t);
}

void app_draw(Application *app) {
    SDL_FillRect(app->m_window_surface, NULL, SDL_MapRGB(app->m_window_surface->format, 0, 0, 0));
    player_draw(app->player, app->m_window_surface);
    SDL_UpdateWindowSurface(app->m_window);
}