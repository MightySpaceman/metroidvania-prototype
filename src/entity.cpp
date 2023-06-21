#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Entity.hpp"

Entity::Entity(double p_x, double p_y, double p_scalex, double p_scaley, double p_angle, SDL_Texture* p_tex)
:x(p_x), y(p_y), scale_x(p_scalex), scale_y(p_scaley), angle(p_angle), tex(p_tex)
{
    frame.x = 0;
    frame.y = 0;
    frame.w = 600;
    frame.h = 400;
}

Entity::Entity()
{

}

// modifying position
double Entity::X(){ return x; }
double Entity::Y(){ return y; }
void Entity::setX(float p_x){ x = p_x; }
void Entity::setY(float p_y) { y = p_y; }
void Entity::applyX(float p_x) { x += p_x; }
void Entity::applyY(float p_y) { y += p_y; }
//
// modifying velocity
float Entity::velX() { return vel_y; };
float Entity::velY() { return vel_x; };
void Entity::setVelX(float p_x) { vel_x = p_x; }
void Entity::setVelY(float p_y) { vel_y = p_y; }
void Entity::applyVelX(float p_x) { vel_x += p_x; }
void Entity::applyVelY(float p_y) { vel_y += p_y; }

// modifying scale
float Entity::scaleX() { return scale_x; }
float Entity::scaleY() { return scale_y; }
void Entity::setScaleX(float p_x) { scale_x = p_x; }
void Entity::setScaleY(float p_y) { scale_y = p_y; }

// modifying rotation
float Entity::getRotation() { return angle; }
void Entity::setRotation(float p_angle) { angle = p_angle; }
void Entity::applyRotation(float p_appendedangle)
{
    angle += p_appendedangle;
    if (angle > 360)
    {
        angle = 0;
    } else if (angle < 0) 
    {
        angle = 360;
    }
}

// retrieving width and height in pixels
float Entity::pixelsX() { return frame.w*scale_x; }
float Entity::pixelsY() { return frame.h*scale_y; }


// returns a pointer to the entity's texture
SDL_Texture* Entity::getTex() { return tex; }
// sets the texture
void Entity::setTex(SDL_Texture* p_tex) { tex = p_tex; }
// returns the current SDL_Rect frame
SDL_Rect Entity::getFrame() { return frame; }
// sets the frame bounds
void Entity::setFrame(int x, int y, int w, int h)
{
    frame.x = x;
    frame.y = y;
    frame.w = w;
    frame.h = h;
}