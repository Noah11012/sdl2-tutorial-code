#include "application.hpp"

Application::Application()
{
    m_window = SDL_CreateWindow("SDL2 Window",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                680, 480,
                                0);

    if(!m_window)
    {
        std::cout << "Failed to create window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }

    m_window_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(!m_window_renderer)
    {
        std::cout << "Failed to get window's surface\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }

    m_render_viewport = { 0, 0, 680, 480 };

    IMG_Init(IMG_INIT_PNG);

    SDL_Surface *image_surface = IMG_Load("world.png");
    m_image = SDL_CreateTextureFromSurface(m_window_renderer, image_surface);
    SDL_FreeSurface(image_surface);
}

Application::~Application()
{
    SDL_DestroyRenderer(m_window_renderer);
    SDL_DestroyWindow(m_window);
    IMG_Quit();
}

void Application::loop()
{
    bool keep_window_open = true;
    while(keep_window_open)
    {
        while(SDL_PollEvent(&m_window_event) > 0)
        {
            switch(m_window_event.type)
            {
                case SDL_QUIT:
                    keep_window_open = false;
                    break;
                
                case SDL_KEYDOWN:
                    handle_zoom();
            }
        }

        update(1.0/60.0);
        draw();
    }
}

void Application::handle_zoom()
{
    unsigned char const *keys = SDL_GetKeyboardState(nullptr);
    if(keys[SDL_SCANCODE_UP])
    {
        m_render_viewport.w += 5;
        m_render_viewport.h += 5;
    } else if(keys[SDL_SCANCODE_DOWN])
    {
        m_render_viewport.w -= 5;
        m_render_viewport.h -= 5;
    }
    else if(keys[SDL_SCANCODE_W])
    {
        m_render_viewport.y += 20;
        if(m_render_viewport.y > 0)
            m_render_viewport.y = 0;
    } else if(keys[SDL_SCANCODE_S])
    {
        m_render_viewport.y -= 20;
        if(m_render_viewport.y < -720)
            m_render_viewport.y = -720;
    } else if(keys[SDL_SCANCODE_A])
    {
        m_render_viewport.x += 20;
    } else if(keys[SDL_SCANCODE_D])
    {
        m_render_viewport.x -= 20;
        if(m_render_viewport.x < -1280)
            m_render_viewport.x = -1280;
    }
}

void Application::update(double delta_time)
{

}

void Application::draw()
{
    SDL_SetRenderDrawColor(m_window_renderer, 255, 255, 255, 255);
    SDL_RenderClear(m_window_renderer);
    SDL_RenderCopy(m_window_renderer, m_image, nullptr, nullptr);
    SDL_RenderSetViewport(m_window_renderer, &m_render_viewport);
    SDL_RenderPresent(m_window_renderer);
}
