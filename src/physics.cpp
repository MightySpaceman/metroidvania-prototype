#include <SDL2/SDL.h>
#include <math.h>

#include "Physics.hpp"

// Collision detection function courtesy of https://lazyfoo.net/tutorials/SDL/27_collision_detection/index.php (I understand the concept, I just can't be bothered to write it all out myself. I promise :) )
bool Physics::detectCollision(SDL_Rect a, SDL_Rect b)
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

     //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
};


// detects whether the object is within the game's view window
bool Physics::detectInBounds(int window_width, int window_height, int object_width, int object_height, int x, int y)
{
    if (x > window_width-object_width || x < 0)
    {
        return true;
    }
    if (y > window_width-object_width || y < 0)
    {
        return true;
    }
};