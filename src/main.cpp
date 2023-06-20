#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <chrono>
#include <SDL2/SDL_ttf.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Physics.hpp"

const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;
const int TICKRATE = 20;
const float GRAVITY = 15;
const float TERMINAL_VELOCITY = 20; // falling speed
const float PLAYER_SPEED = 12; // player speed
const float JUMP_SPEED = GRAVITY*2;
const float JUMP_COOLDOWN = 500;

int main(int argc, char* args[]) {
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL_Init has failed! SDL_ERROR: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_Init has failed! SDL_ERROR: " << SDL_GetError() << std::endl;
                                                                                        
    if (!(TTF_Init()))
        std::cout << "TTF_Init has failed! SDL_ERROR: " << SDL_GetError() << std::endl;


    RenderWindow window("GAME V1.0", WINDOW_WIDTH, WINDOW_HEIGHT);
    SDL_Rect windowrect;
    windowrect.x = 0;
    windowrect.y = 0;
    windowrect.w = 100;
    windowrect.h = 100;

    SDL_Texture* sofiaTexture = window.loadTexture("res/gfx/sofia.png");
    SDL_Texture* background = window.loadTexture("res/gfx/checker.png");
    SDL_Texture* arrowtexture = window.loadTexture("res/gfx/arrow.png");

    TTF_Font* font = TTF_OpenFont("arial.ttf", 24);
    if (!font) {
        std::cout << "Font failed to load." << std::endl;
    }

    // SDL_Color color = { 255, 255, 255 };
    // SDL_Surface* textsurface = TTF_RenderText_Solid(font, "Hello world!", color);   	
    // SDL_Texture* fontTexture = SDL_CreateTextureFromSurface(window.getRenderer(), textsurface);

    // player entity 
    Entity sofia(WINDOW_WIDTH/2-(window.getDimensionsX(sofiaTexture)/2), WINDOW_HEIGHT/2-(window.getDimensionsY(sofiaTexture)/2), 0.3, 0.2, 0, sofiaTexture);
    Entity arrow(40,40, 0.3, 0.4, 0, arrowtexture);

    // game running condition
    bool gameRunning = true;

    // event stack
    SDL_Event event;

    // get keyboard state for input
    const Uint8* keyboardState = SDL_GetKeyboardState(NULL);

    // initialize delta time variables
    float deltaTime;
    float accumulator;
    auto last_update = std::chrono::high_resolution_clock::now();

    // initialise jump cooldown variable
    std::chrono::high_resolution_clock::time_point lastJump;
    lastJump = std::chrono::high_resolution_clock::now();
    float lastJumpRaw;
    bool jumping = false;

    // apply gravity or not
    bool applyGravity = true;


    while (gameRunning) {
        // close event
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                gameRunning = false;
        }

        // delta time shenanagins
        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float, std::milli> deltaTimeRaw = now - last_update;
        deltaTime = deltaTimeRaw.count();

        last_update = now;
        accumulator += deltaTime;

        // jump cooldown thingies
        auto currentJump = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float, std::milli> lastJumpTime = currentJump - lastJump;
        jumping = false;

        // std::cout << lastJumpTime.count() << std::endl;

        arrow.setY(-200);

        // apply default constants
        applyGravity = true; 
        sofia.setVelX(0);


        while (accumulator > TICKRATE)
        {
            std::cout << sofia.getY() << std::endl;

            // keyboard handling

            // jumping:
            if (keyboardState[SDL_SCANCODE_Z]) 
            {
                jumping = true;
                if (true)
                {
                    sofia.setY(sofia.getY() - JUMP_SPEED);
                }
            } else { jumping = false; }

            if (keyboardState[SDL_SCANCODE_DOWN]) 
            {
                sofia.setVelY(sofia.getVelY() + 2);
            }

            if (keyboardState[SDL_SCANCODE_LEFT] && sofia.getVelX() > -TERMINAL_VELOCITY) 
            {
                sofia.setVelX(-PLAYER_SPEED);
            }

            if (keyboardState[SDL_SCANCODE_RIGHT] && sofia.getVelX() < TERMINAL_VELOCITY) 
            {
                sofia.setVelX(PLAYER_SPEED);
            }
            
            


            // Check if the image hits the ground
            if (sofia.getY() > WINDOW_HEIGHT - 280) {
                sofia.setY(WINDOW_HEIGHT-279);  // Reset the image position to be above the ground
                sofia.setVelY(0);
            }

            // Check if the image hits the walls
            if (sofia.getX() > WINDOW_WIDTH - sofia.getPixelsX() || sofia.getX() < 0) {                
                if (sofia.getX() > WINDOW_WIDTH/2)
                {
                    sofia.setX(WINDOW_WIDTH-sofia.getPixelsX());
                } else {
                    sofia.setX(0);
                }
            }

            // stop if hitting ground and disable gravity
            if (sofia.getY() > WINDOW_HEIGHT - 290)
            {
                sofia.setVelY(0);
                sofia.setY(WINDOW_HEIGHT-280);
                applyGravity = false;
            }

            // Apply gravity
            if (applyGravity && sofia.getVelY() < TERMINAL_VELOCITY)
            {
                sofia.setY(sofia.getY() + GRAVITY);
            }

            sofia.setX(sofia.getX() + sofia.getVelX());
            sofia.setY(sofia.getY() + sofia.getVelY());

            accumulator -= TICKRATE;
        }

        // rendering
        window.clear();   
        // SDL_RenderCopy(window.getRenderer(), fontTexture, NULL, NULL);
        window.renderBackground(background, WINDOW_WIDTH, WINDOW_HEIGHT);
        window.render(sofia);
        window.render(arrow);
        window.display();
    }

    window.cleanUp();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();

    return 0;
}