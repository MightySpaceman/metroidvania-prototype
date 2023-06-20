#pragma once
#include <SDL2/SDL.h>

class Rect 
{
public:
    Rect();
    SDL_Rect* getRect();
    void setRect(float x, float y, float w, float h);
private:
    SDL_Rect* rect;
};

class Line
{
    
};