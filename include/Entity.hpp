#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/*
----[ Entity Class ]----

Multi-purpose class intended to be inherited into anything that appears on screen,
e.g. the player, enemies, level props, or even backgrounds. Contains position, scale 
and rotation attributes, as well as an SDL_Rect for defining bounds and a pointer
to supplied SDL_Texture for the actual...you know...texture. Has functions to handle
the manipulation and retriving of these attributes, as well as updating them accordingly.

Nobody will probably ever read this except for me, so this is mostly just a note for myself :)

*/

class Entity
{
public:
    // constructor class with all information provided 
    Entity(double p_x, double p_y, double p_scalex, double p_scaley, double p_angle, SDL_Texture* p_tex);
    // constructor class with no information provided
    Entity();

    // accessing and modifying position
    double X(); // returns x
    double Y(); // returns y
    void setX(float p_x); // sets x to value
    void setY(float p_y); // sets y to value
    void applyX(float p_x); // increments x by supplied value
    void applyY(float p_y); // increments y by supplied value

    // accessing and modifying velocity
    float velX(); // returns x velocity
    float velY(); // returns y velocity
    void setVelX(float p_x); // sets X velocity to value
    void setVelY(float p_y); // sets y velocity to value
    void applyVelX(float p_x); // increments x velocity by supplied value
    void applyVelY(float p_y); // increments x velocity by supplied value

    // accessing and modifying scale (not used much)
    float scaleX(); // retuns x scale
    float scaleY(); // returns y scale
    void setScaleX(float p_x); // sets x scale
    void setScaleY(float p_y); // sets y scale
    
    // returns the size in pixels
    float pixelsX(); // returns pixel width
    float pixelsY(); // returns pixel height

    // accessing and modifying rotation (0-360 degree value)
    float getRotation(); // returns rotation angle
    void setRotation(float p_angle); // sets rotation to value
    void applyRotation(float p_appendedangle); // increments rotation by supplied value

    // for retreiving texture and SDL_Rect
    SDL_Texture* getTex();
    void setTex(SDL_Texture* p_tex);
    SDL_Rect getFrame();
    void setFrame(int x, int y, int w, int h);
    
private: 
    // private field for important things (because online stuff told me to or something like that)
    // position and scale information
    float x, y;
    float scale_x, scale_y;
    float vel_x, vel_y;

    // angle of rotation
    float angle;

    // SDL stuff
    SDL_Rect frame;
    SDL_Texture* tex;
};