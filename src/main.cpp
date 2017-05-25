#include <iostream>
#include <cmath>

#include <zaudio/exception.h>
#include <zaudio/sdl/audioplayersdl.h>
#include <zaudio/sdl/audiosamplersdl.h>
#include <zaudio/sdl/audiosamplesdl.h>
#include <zaudio/sdl/audioloadersdl.h>

#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
    AudioPlayerSDL player;
    AudioSamplerSDL sampler;

    //std::shared_ptr<IAudioSample> sample = AudioLoaderSDL::loadWav("/home/zi/audiocpp/res/sample.wav");
    std::shared_ptr<IAudioSample> sample = AudioLoaderSDL::loadWav("/home/zi/a_far_lamore_comincia_tu.wav");

    std::shared_ptr<IAudioSample> piano1 = AudioLoaderSDL::loadWav("/home/zi/samples/Alesis-Fusion-Bright-Acoustic-Piano-C4.wav");
    std::shared_ptr<IAudioSample> piano2 = AudioLoaderSDL::loadWav("/home/zi/samples/Alesis-Fusion-Bright-Acoustic-Piano-C2.wav");

    /*
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
    */

    sampler.play(piano1);
    sampler.play(piano2);
    SDL_Delay(3000);

    return 0;
}
