#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 200

// 1
void ul2_1_1(){
    int a = 1334;
    int b = 315;
    int res = 0;

    printf("\nCislo1: %d  Cislo2: %d  Vysledok: %d", a, b, res);

    asm volatile(
        "mov w0, %w[value1]  \n\t"
        "mov w1, %w[value2]  \n\t"
        "add w2, w0, w1      \n\t"
        "mov %w[result], w2  \n\t"
        : [result] "=r" (res)        
        : [value1] "r" (a), [value2] "r" (b)
        : "w0", "w1", "w2"
    );

    printf("\nCislo1: %d  Cislo2: %d  Vysledok: %d", a, b, res);
}
// 1
void ul2_1_2(){
    int a = 5;
    int res;

    asm volatile(
        "lsl %w[result], %w[input], #2"
        : [result] "=r" (res)
        : [input] "r" (a)
    );

    printf("Cislo: %d, Vysledok: %d\n", a, res);
}
// 3
void ul2_1_3(){
    int number = 11;
    int res = 0;

    printf("Cislo: %d", number);
    asm volatile(
        "mov w0, %w[value]      \n\t"
        "cmp w0, #10            \n\t"
        "blt 1f                 \n\t"
        "add w1, w0, #55        \n\t"
        "b 2f                   \n\t"
    "1:                         \n\t"
        "add w1, w0, #48        \n\t"
    "2:                         \n\t"
        "mov %w[result], w1     \n\t"
        : [result] "=r" (res)
        : [value] "r" (number)
        : "w0", "w1"
    );

    printf("\nASCII Code: %c", res);

}
// 2
void ul2_1_2(){
    char vendor[13];
    unsigned int eax, ebx, ecx, edx;

    eax = 0;
    __asm__ __volatile__ (
        "cpuid"
        : "=b"(ebx), "=d"(edx), "=c"(ecx)
        : "a"(eax)
    );

    memcpy(&vendor[0],  &ebx, 4);
    memcpy(&vendor[4],  &edx, 4);
    memcpy(&vendor[8],  &ecx, 4);
    vendor[12] = '\0';

    printf("CPU Vendor: %s\n", vendor);
}
// 3
void ul2_2(){
    char text[] = "Ul2.2 By Yaroslav Myrka";
    printf("%s\n", text);

    char *ptr = text;
    printf("%p\n", ptr);

    ptr++;
    *ptr = 'X';
    printf("%s\n", text);

    //ptr = ptr + 1000000;
    // *ptr = 'Y';

    int numbers[] = {1, 2, 3, 4, 5};

    for(int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }

    printf("\n");

    int *int_ptr = numbers;
    printf("%p\n", int_ptr);

    int_ptr++;
    *int_ptr = 99;

    for(int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
}
// 2
void ul2_3_1(){
    FILE *fin = fopen("/Users/arikmirnij/Documents/ap blok 2/ul2.3.1/poviedka.html", "rb");
    FILE *fout = fopen("/Users/arikmirnij/Documents/ap blok 2/ul2.3.1/poviedkaWIN1250.html", "wb");
    unsigned char ch;
    while (fread(&ch, 1, 1, fin) == 1) {
        unsigned char converted = convert_iso8859_2_to_cp1250(ch);
        fwrite(&converted, 1, 1, fout);
    }

    fclose(fin);
    fclose(fout);
}

unsigned char convert_iso8859_2_to_cp1250(unsigned char ch) {
    switch (ch) {
        case 0xA1: return 0xA5; // Ą
        case 0xA5: return 0xBC;
        case 0xA6: return 0x8C; // Ś
        case 0xA9: return 0x8A;
        case 0xAB: return 0x8D;
        case 0xAC: return 0x8F;
        case 0xAE: return 0x8E;
        case 0xB1: return 0xB9;
        case 0xB5: return 0xBE;
        case 0xB6: return 0x9C;
        case 0xB7: return 0xA1;
        case 0xB9: return 0x9A;
        case 0xBB: return 0x9D;
        case 0xBC: return 0x9F;
        case 0xBE: return 0x9E;

        default: return ch;
    }
}
// 1
void ul2_3_2(){
    FILE *input, *output;
    input = fopen("/Users/arikmirnij/Documents/ap blok 2/ul2.3.2/koniec_poviedky.html", "rb");
    output = fopen("/Users/arikmirnij/Documents/ap blok 2/ul2.3.2/decrypt-koniec_poviedky.html", "wb");

    for (int c; (c = fgetc(input)) != EOF; fputc(c ^ 27, output)) {}

    fclose(input), fclose(output);
    return puts("Successfully decrypted"), 0;
}
// 4
void ul2_4(){
    const char *file_name = "/Users/arikmirnij/Downloads/audio.mp3";
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

}



void main(){

}