#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Entity.hpp"

// Function to open a window to render objects to
RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
    :window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, 
        SDL_WINDOW_SHOWN);

        if (window == NULL)
        {
            std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

// loads image/texture from input filepath, then returns pointer to  it's stored location in memory
SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == NULL)
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

        return texture;
}

// cleans up/destroys the window
void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}

// clears the window
void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& p_entity)
{
    SDL_Rect src;
    src.x = p_entity.getFrame().x;
    src.y = p_entity.getFrame().y;;
    src.w = p_entity.getFrame().w;;
    src.h = p_entity.getFrame().h;;

    SDL_Rect dst;
    dst.x = p_entity.X() * 1;
    dst.y = p_entity.Y() * 1;
    dst.w = p_entity.getFrame().w; // * p_entity.scaleX();  // sets destination rect scale (and therefore sprite) to the entity's current frame dimensions multiplied by the entity's scale values
    dst.h = p_entity.getFrame().h; // * p_entity.scaleY();

    SDL_RenderCopyEx(renderer, p_entity.getTex(), &src, &dst, p_entity.getRotation(), NULL, SDL_FLIP_NONE);
}

void RenderWindow::renderBackground(SDL_Texture* texture, int windowWidth, int windowHeight)
{
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = 1920;
    src.h = 1080;

    SDL_Rect dst;
    dst.x = 0;
    dst.y = 0;
    dst.w = 1920; 
    dst.h = 1080;

    SDL_RenderCopyEx(renderer, texture, &src, &dst, 0, NULL, SDL_FLIP_NONE);
};

void RenderWindow::display(){
    SDL_RenderPresent(renderer);
}

int RenderWindow::getDimensionsX(SDL_Texture* texture)
{
    int* x = new int;  // Allocate memory for x
    SDL_QueryTexture(texture, nullptr, nullptr, x, nullptr);
    int result = *x;
    delete x;  // Deallocate the memory after retrieving the value
    return result;
}

int RenderWindow::getDimensionsY(SDL_Texture* texture)
{
    int* y = new int;  // Allocate memory for y
    SDL_QueryTexture(texture, nullptr, nullptr, nullptr, y);
    int result = *y;
    delete y;  // Deallocate the memory after retrieving the value
    return result;
}

SDL_Renderer* RenderWindow::getRenderer()
{
    SDL_Renderer* newrenderer = renderer;
    return newrenderer;
}


