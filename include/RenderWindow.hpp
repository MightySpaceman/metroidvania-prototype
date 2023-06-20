#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

class RenderWindow
{
public:
    RenderWindow(const char* p_title, int p_w, int p_h);
    SDL_Texture* loadTexture(const char* p_filePath);
    void cleanUp();
    void clear();
    void render(Entity& p_entity);
    void renderBackground(SDL_Texture* texture, int windowWidth, int windowHeight);
    void display();
    int getDimensionsX(SDL_Texture* texture);
    int getDimensionsY(SDL_Texture* texture);
    SDL_Renderer* getRenderer();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};