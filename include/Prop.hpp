#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Prop
{
public:
    Prop(float p_x, float p_y, float p_w, float p_h);

    bool isColliding();
private:
    float x, y;
    SDL_Rect frame;
    SDL_Rect collider;

    SDL_Texture* tex;
};