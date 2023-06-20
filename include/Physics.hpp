#pragma once

#include <SDL2/SDL.h>
#include <math.h>

namespace Physics
{
    bool detectCollision(SDL_Rect a, SDL_Rect b);
    bool detectInBounds(int window_width, int window_height, int object_width, int object_height, int x, int y);
};