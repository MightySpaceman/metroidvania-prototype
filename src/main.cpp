#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <chrono>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Physics.hpp"
#include "Player.hpp"

const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 700;
const int TICKRATE = 20;

int main() {
    // initialising libraries
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL_Init has failed! SDL_ERROR: " << SDL_GetError() << std::endl;
    else    
        std::cout << "SDL_Init succeeded" << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_Init has failed! SDL_ERROR: " << SDL_GetError() << std::endl;
    else    
        std::cout << "IMG_Init succeeded" << std::endl;

    // open the window
    RenderWindow window("METROIDVANIA-PROTOTYPE", WINDOW_WIDTH, WINDOW_HEIGHT);

    // setting up textures
    SDL_Texture* sofiaTexture = window.loadTexture("res/gfx/sofia.png");
    SDL_Texture* background = window.loadTexture("res/gfx/checker.png");


    // spawns player entity and puts it in the middle of the screen
    Player sofia(0, 0, 0.1, 0.3, 0, sofiaTexture);
    sofia.setX(WINDOW_WIDTH/2 - (sofia.getFrame().w/2));
    sofia.setY(WINDOW_HEIGHT/2 - (sofia.getFrame().h/2));
    
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

    // initialise jump variables
    auto lastJump = std::chrono::high_resolution_clock::now();

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

        // jump time thingies
        std::chrono::duration<float, std::milli> lastJumpTime = now - lastJump;


        while (accumulator > TICKRATE)
        {

            // keyboard handling
            // up arrow
            if (keyboardState[SDL_SCANCODE_Z]) 
            {

            }

            // down arrow
            if (keyboardState[SDL_SCANCODE_DOWN]) 
            {
                
            }

            // left arrow
            if (keyboardState[SDL_SCANCODE_LEFT]) 
            {
                sofia.applyX(-5);
            }

            // right arrow
            if (keyboardState[SDL_SCANCODE_RIGHT]) 
            {
                sofia.applyX(5);
            }

            accumulator -= TICKRATE;
        }

        // rendering
        window.clear();   
        window.renderBackground(background, WINDOW_WIDTH, WINDOW_HEIGHT);
        window.render(sofia);
        window.display();
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}