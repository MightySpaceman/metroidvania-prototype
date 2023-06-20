#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity
{
public:
    Entity(double p_x, double p_y, double p_scalex, double p_scaley, double angle, SDL_Texture* p_tex);

    double getX();
    double getY();

    void setX(float p_x);
    void setY(float p_y);

    double getScaleX();
    double getScaleY();
    float getPixelsX();
    float getPixelsY();

    void setScaleX(float p_x);
    void setScaleY(float p_y);

    double getRotation();
    void setRotation(double p_angle);
    void appendRotation(double p_appendedangle);

    double getVelX();
    double getVelY();

    void setVelX(double p_x);
    void setVelY(double p_y);

    double addVel(double p_x, double p_y);

    void updatePos();

    SDL_Texture* getTex();
    SDL_Rect getCurrentFrame();
private:
    double x, y;
    double scaleX, scaleY;
    double angle;
    double velX, velY;

    SDL_Rect currentFrame;
    SDL_Texture* tex;
};