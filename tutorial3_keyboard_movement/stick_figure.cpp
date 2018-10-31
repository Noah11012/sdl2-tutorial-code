#include "stick_figure.hpp"

StickFigure::StickFigure()
{
    m_image = SDL_LoadBMP("stick_figure.bmp");

    m_position.x = 0;
    m_position.y = 0;
    m_position.w = 22;
    m_position.h = 43;

    m_x = 0.0;
    m_y = 0.0;

    m_direction = Direction::NONE;
}

void StickFigure::handle_events(SDL_Event const &event)
{
    switch(event.type)
    {
        case SDL_KEYDOWN:
            Uint8 const *keys = SDL_GetKeyboardState(nullptr);

            if(keys[SDL_SCANCODE_W] == 1)
                m_direction = Direction::UP;
            else if(keys[SDL_SCANCODE_S] == 1)
                m_direction = Direction::DOWN;
            else if(keys[SDL_SCANCODE_A] == 1)
                m_direction = Direction::LEFT;
            else if(keys[SDL_SCANCODE_D] == 1)
                m_direction = Direction::RIGHT;
            break;
    }
}

void StickFigure::update(double delta_time)
{
    switch(m_direction)
    {
        case Direction::NONE:
            m_x += 0.0;
            m_y += 0.0;
            break;
        case Direction::UP:
            m_y = m_y - (5.0 * delta_time);
            break;
        case Direction::DOWN:
            m_y = m_y + (5.0 * delta_time);
            break;
        case Direction::LEFT:
            m_x = m_x - (5.0 * delta_time);
            break;
        case Direction::RIGHT:
            m_x = m_x + (5.0 * delta_time);
            break;
    }

    m_position.x = m_x;
    m_position.y = m_y;
}

void StickFigure::draw(SDL_Surface *window_surface)
{
    SDL_BlitSurface(m_image, nullptr, window_surface, &m_position);
}