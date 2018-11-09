def Settings( **kwargs ):
    return { 'flags': ['-x', 'c++', 'std=c++17', '`sdl-config2 --cflags --libs`'] }
