#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

// player class inherited from entity
class Player : public Entity
{
// functions
public:
    Player(float p_x, float p_y, float p_scalex, float p_scaley, float p_angle, SDL_Texture* p_tex);

    // updates position, state, etc 
    void update();

public:
    float fallSpeed = 10;
    float moveSpeed = 10;
    float jumpSpeed = 20;
    float sprintSpeed = 35;
    float sprintTime = 200; // milliseconds
    float sprintInterval = 200; // milliseconds
    int health = 100; 

private:
    // state information
    bool _isGrounded;
    bool _isSprintable;
    bool _isSprintReset;
    bool _isInputEnabled;
    bool _isFalling;
    bool _isAttackable;
};