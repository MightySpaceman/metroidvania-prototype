#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "Text.hpp"

Text::Text(SDL_Renderer* p_renderer, const char* p_filepath, int p_fontSize, SDL_Color p_color, double p_x, double p_y, double p_scale_x, double p_scale_y)
:renderer(p_renderer), filepath(p_filepath), fontSize(p_fontSize), color(p_color), x(p_x), y(p_y), scale_x(p_scale_x), scale_y(p_scale_y)
{
    TTF_Font* font = TTF_OpenFont(filepath, 24);
    if (!font) {
        std::cout << "Font failed to load." << std::endl;
    }
    SDL_Surface* textsurface = TTF_RenderText_Solid(font, "Hello world!", color);   	
    SDL_Texture* fontTexture = SDL_CreateTextureFromSurface(renderer, textsurface);
}

// retreiving texture
SDL_Texture* Text::getTex(){ return texture; }

// retreiving content
char* Text::getContent(){ return content; }

// retreiving position/dimensions info
double Text::getX(){ return x; }
double Text::getY(){ return y; }
double Text::getScaleX(){ return scale_x; }
double Text::getScaleY(){ return scale_y; }
int Text::getFontSize(){ return fontSize; }

// modifying content
void Text::setContent(char* p_content){ content = p_content; }

// modifying position/dimensions
void Text::setX(double p_x){ x = p_x; }
void Text::setY(double p_y){ y = p_y; }
void Text::setScaleX(double p_x){ scale_x = p_x; }
void Text::setScaleY(double p_y){ scale_y = p_y; }
void Text::setFontSize(int p_fontsize){ fontSize = p_fontsize; }

