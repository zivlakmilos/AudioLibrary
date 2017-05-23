#include <zaudio/sdl/audioloadersdl.h>

#include <SDL2/SDL.h>

#include <zaudio/exception.h>

std::shared_ptr<IAudioSample> AudioLoaderSDL::loadWav(const std::string &filePath)
{
    SDL_AudioSpec spec;
    uint32_t length;
    uint8_t *buffer;

    if(SDL_LoadWAV(filePath.c_str(), &spec, &buffer, &length) == NULL)
        throw Exception("Can't load file: " + filePath);

    std::vector<float> data;

    // TODO: Make more general
    int16_t *pos = (int16_t*)buffer;

    for(int i = 0; i < length / 2; i++)
        data.push_back(pos[i] / 32767.0f);

    SDL_FreeWAV(buffer);

    SampleInfo sampleInfo;
    sampleInfo.freq = spec.freq;
    sampleInfo.channels = spec.channels;

    return std::shared_ptr<IAudioSample>(new AudioSampleSDL(data, sampleInfo));
}
