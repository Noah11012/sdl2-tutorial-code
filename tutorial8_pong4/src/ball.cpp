#include "ball.hpp"

Ball::~Ball()
{
    SDL_DestroyTexture(m_image);
}

void Ball::init(SDL_Renderer *renderer, int x, int y)
{
    IMG_Init(IMG_INIT_PNG);

    SDL_Surface *image = IMG_Load("ball.png");
    
    m_image = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

    IMG_Quit();

    m_position.x = x;
    m_position.y = y;

    m_x = m_position.x;
    m_y = m_position.y;

    SDL_QueryTexture(m_image, nullptr, nullptr, &m_position.w, &m_position.h);

    std::random_device dev;
    std::mt19937 rand_gen(dev());
    std::uniform_int_distribution<> dist_x(0, 1);

    if(dist_x(rand_gen) == 0)
    {
        m_velocity_x = -3;
    } else {
        m_velocity_x = 3;
    }

    std::uniform_int_distribution<> dist_y(1, 3);
    m_velocity_y = dist_y(rand_gen);

    if(dist_x(rand_gen) == 0)
    {
        m_velocity_y = -m_velocity_y;
    }
}

void Ball::update(double delta_time)
{
    m_x = m_x + (m_velocity_x * delta_time);
    m_y = m_y + (m_velocity_y * delta_time);
    m_position.x = m_x;
    m_position.y = m_y;
}

void Ball::draw(SDL_Renderer *renderer)
{
    SDL_RenderCopy(renderer, m_image, nullptr, &m_position);
}


