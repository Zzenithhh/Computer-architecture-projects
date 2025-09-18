#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <stdio.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 200

const char *file_name = "/Users/arikmirnij/Downloads/audio.mp3";
int main() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    TTF_Init();
    TTF_Font* font = TTF_OpenFont("/Users/arikmirnij/Downloads/Arial.ttf", 24);

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    SDL_Window* window = SDL_CreateWindow("My Audio player",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Mix_Music* music = Mix_LoadMUS(file_name);

    Mix_PlayMusic(music, 0);

    int is_paused = 0;
    int is_running = 1;
    SDL_Event event;

    while (is_running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                is_running = 0;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int mouse_x, mouse_y;
                SDL_GetMouseState(&mouse_x, &mouse_y);
                SDL_Rect button_rect = {WINDOW_WIDTH/2 - 50, 120, 100, 50};

                if (mouse_x >= button_rect.x && mouse_x <= button_rect.x + button_rect.w &&
                    mouse_y >= button_rect.y && mouse_y <= button_rect.y + button_rect.h) {
                    if (is_paused) {
                        Mix_ResumeMusic();
                        is_paused = 0;
                    } else {
                        Mix_PauseMusic();
                        is_paused = 1;
                    }
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 240, 240, 240, 255);
        SDL_RenderClear(renderer);

        SDL_Color text_color = {0, 0, 0, 255};
        SDL_Surface* text_surface = TTF_RenderText_Solid(font, file_name, text_color);
        SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);

        SDL_Rect text_rect = {
            50, // x
            50, // y
            text_surface->w,
            text_surface->h
        };

        SDL_RenderCopy(renderer, text_texture, NULL, &text_rect);

        SDL_Rect button_rect = {WINDOW_WIDTH/2 - 50, 120, 100, 50};
        SDL_SetRenderDrawColor(renderer, is_paused ? 100 : 200, is_paused ? 200 : 100, 100, 255);
        SDL_RenderFillRect(renderer, &button_rect);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &button_rect);

        const char* button_text = is_paused ? "Play" : "Pause";
        SDL_Surface* button_surface = TTF_RenderText_Solid(font, button_text, text_color);
        SDL_Texture* button_texture = SDL_CreateTextureFromSurface(renderer, button_surface);

        SDL_Rect button_text_rect = {
            button_rect.x + (button_rect.w - button_surface->w)/2,
            button_rect.y + (button_rect.h - button_surface->h)/2,
            button_surface->w,
            button_surface->h
        };

        SDL_RenderCopy(renderer, button_texture, NULL, &button_text_rect);

        SDL_RenderPresent(renderer);

        SDL_FreeSurface(text_surface);
        SDL_DestroyTexture(text_texture);
        SDL_FreeSurface(button_surface);
        SDL_DestroyTexture(button_texture);

        SDL_Delay(16);
    }

    TTF_CloseFont(font);
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}