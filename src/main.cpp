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
    //std::shared_ptr<IAudioSample> sample = AudioLoaderSDL::loadWav("/home/zi/audiocpp/res/sample.wav");
    std::shared_ptr<IAudioSample> sample = AudioLoaderSDL::loadWav("/home/zi/a_far_lamore_comincia_tu.wav");

    player.play(sample);
    player.seek(0.2f);

    std::cout << "Hello World!" << std::endl;

    char ch;
    do
    {
        std::cin >> ch;
    } while(ch != '\n');

    return 0;
}
