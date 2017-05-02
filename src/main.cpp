#include <iostream>
#include <cmath>

#include "exception.h"
#include "sdl/audioplayersdl.h"
#include "sdl/audiosamplesdl.h"
#include "sdl/audioloadersdl.h"

#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
    AudioPlayerSDL player;
    std::shared_ptr<IAudioSample> sample = AudioLoaderSDL::loadWav("/home/zi/audiocpp/res/sample.wav");

    player.play(sample);

    std::cout << "Hello World!" << std::endl;
    SDL_Delay(3000);

    return 0;
}
