#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>

class Application
{
public:
    Application();
    ~Application();

    void loop();
    void update(double delta_time);
    void handle_zoom();
    void draw();
private:
    SDL_Texture  *m_image;
    SDL_Rect      m_render_viewport;
    SDL_Window   *m_window;
    SDL_Renderer *m_window_renderer;
    SDL_Event     m_window_event;
};