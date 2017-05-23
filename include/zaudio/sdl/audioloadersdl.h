#ifndef _AUDIO_LOADER_SDL_H_
#define _AUDIO_LOADER_SDL_H_

#include <string>
#include <memory>

#include <zaudio/sdl/audiosamplesdl.h>

class AudioLoaderSDL
{
public:
    static std::shared_ptr<IAudioSample> loadWav(const std::string &filePath);

private:
    AudioLoaderSDL(void) {};
};

#endif // _AUDIO_LOADER_SDL_H_
