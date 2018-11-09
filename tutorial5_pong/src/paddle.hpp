#pragma once

#include <SDL2/SDL.h>

class Paddle
{
public:
    Paddle(int x, int y);
    ~Paddle() = default;

    void handle_input(SDL_Event const &event);
    void update(double delta_time);
    void draw();
private:
    SDL_Rect m_position;
};
