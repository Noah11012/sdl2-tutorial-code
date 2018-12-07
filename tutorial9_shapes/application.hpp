#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>

class Application
{
public:
    Application();
    ~Application();

    void loop();
    void update(double delta_time);
    void draw();
private:
    SDL_Window   *m_window;
    SDL_Renderer *m_window_renderer;
    SDL_Event     m_window_event;
};