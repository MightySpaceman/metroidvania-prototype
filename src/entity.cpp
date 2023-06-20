#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Entity.hpp"

Entity::Entity(double p_x, double p_y, double p_scalex, double p_scaley, double p_angle, SDL_Texture* p_tex)
:x(p_x), y(p_y), scaleX(p_scalex), scaleY(p_scaley), angle(p_angle), tex(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 600;
    currentFrame.h = 400;
}

// returns the entity's x position
double Entity::getX(){
    return x;
}

// returns the entity's y position
double Entity::getY(){
    return y;
}

// modifies the entity's x position
void Entity::setX(float p_x)
{
    x = p_x;
    // std::cout << x << std::endl;
}

// modifies the entity's y position
void Entity::setY(float p_y)
{
    y = p_y;
}

double Entity::getScaleX()
{
    return scaleX;
}

double Entity::getScaleY()
{
    return scaleY;
}

float Entity::getPixelsX()
{
    return currentFrame.w*scaleX;
}

float Entity::getPixelsY()
{
    return currentFrame.h*scaleY;
}

void Entity::setScaleX(float p_x)
{
    scaleX = p_x;
}

void Entity::setScaleY(float p_y)
{
    scaleY = p_y;
}

double Entity::getRotation()
{
    return angle;
}

void Entity::setRotation(double p_angle)
{
    angle = p_angle;
}

void Entity::appendRotation(double p_appendedangle)
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

double Entity::getVelX()
{
    return velX;
}

double Entity::getVelY()
{
    return velY;
}

void Entity::setVelX(double p_x)
{
    velX = p_x;
}

void Entity::setVelY(double p_y)
{
    velY = p_y;
}



// returns a pointer to the entity's texture
SDL_Texture* Entity::getTex()
{
    return tex;
}


SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;
}