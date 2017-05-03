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
    //player.seek(0.2f);
    player.seek(0.9f);

    std::cout << "Hello World!" << std::endl;

    bool playing = true;
    player.setOnSampleEndListener([&](void) {
            playing = false;
        });
    player.setOnUpdateListener([](const float *data, size_t length) {
        });

    while(playing)
    {
        SDL_Delay(100);
    }

    return 0;
}
