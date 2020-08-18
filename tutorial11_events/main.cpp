#include <iostream>
#include <SDL2/SDL.h>

/* Helper function to convert the number mapped to the buttons
   on the mouse to a readable string. This function does
   not handle all possible mouse buttons. */
char const *convert_button_number_to_string(int button)
{
    char const *result = "NO_BUTTON";
    switch (button)
    {
        case SDL_BUTTON_LEFT:
        result = "left";
        break;
        
        case SDL_BUTTON_MIDDLE:
        result = "middle";
        break;
        
        case SDL_BUTTON_RIGHT:
        result = "right";
        break;
        
        default:
        break;
    }
    
    return result;
}

int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          1280,
                                          720,
                                          0);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Event event;
    bool running = true;
    while (running)
    {
        while (SDL_PollEvent(&event) > 0)
        {
            switch (event.type)
            {
                case SDL_QUIT:
                std::cout << "Quitting application\n";
                running = false;
                break;

                case SDL_MOUSEMOTION:
                std::cout << "Mouse Position = { "
                          << event.motion.x << " "
                          << event.motion.y << " }\n";
                break;
                
                case SDL_MOUSEBUTTONDOWN:
                case SDL_MOUSEBUTTONUP:
                std::cout << convert_button_number_to_string(event.button.button)
                          << " mouse button " << ((event.button.state == SDL_PRESSED) ? "pressed" : "released");
                std::cout << "\n";
                break;

                case SDL_KEYDOWN:
                case SDL_KEYUP:
                std::cout << "Key " << (char)event.key.keysym.sym << " "
                          << ((event.key.state == SDL_PRESSED) ? "pressed" : "released") << "\n";
                break;
            }
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}