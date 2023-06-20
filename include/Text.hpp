#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Text
{
public:
    // constructor function
    Text(SDL_Renderer* p_renderer, const char* filepath, int fontSize, SDL_Color p_color, double p_x, double p_y, double p_scale_x, double p_scale_y);

    // renders text to the screen
    void render();

    // retreiving private variables
    char* getContent();
    int getFontSize();
    double getX(), getY();
    double getScaleX(), getScaleY();
    SDL_Texture* getTex();
    SDL_Color* getColor();

    // changing private variables
    void setContent(char* p_content);
    void setFontSize(int p_fontsize);
    void setX(double p_x), setY(double p_y);
    void setScaleX(double p_x), setScaleY(double p_y);
    void setColor(SDL_Color* p_color);
private:
    const char* filepath;
    char* content;
    int fontSize;
    double x, y;
    double scale_x, scale_y;
    SDL_Color color;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
};