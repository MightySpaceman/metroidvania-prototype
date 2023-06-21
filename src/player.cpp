#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Entity.hpp"
#include "Player.hpp"

Player::Player(float p_x, float p_y, float p_scalex, float p_scaley, float p_angle, SDL_Texture* p_tex) : Entity()
{
    setX(p_x);
    setY(p_y);
    setScaleX(p_scalex);
    setScaleY(p_scaley);
    setTex(p_tex);

    setFrame(0, 0, 100, 100);
}

void Player::update()
{
    std::cout << "Something" << std::endl;
}