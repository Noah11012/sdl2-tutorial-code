#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <random>

class Ball
{
public:
    Ball() = default;
    ~Ball();
    void init(SDL_Renderer *renderer, int x, int y);
    void update(double delta_time);
    void draw(SDL_Renderer *renderer);
private:
    int m_velocity;
    double m_x;
    SDL_Texture *m_image;
    SDL_Rect m_position;
};
