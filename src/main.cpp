#include <iostream>
#include <cmath>

#include "exception.h"
#include "sdl/audioplayersdl.h"
#include "sdl/audiosamplesdl.h"

#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
    AudioPlayerSDL player;
    std::shared_ptr<AudioSampleSDL> sample(new AudioSampleSDL);

    std::vector<float> test;
    for(int i = 0; i < 100000; i++)
        test.push_back(std::sin(i));

    sample->setData(test);
    player.play(sample);

    std::cout << "Hello World!" << std::endl;
    SDL_Delay(3000);

    return 0;
}
