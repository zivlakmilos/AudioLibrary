#ifndef _AUDIO_PLAYER_SDL_H_
#define _AUDIO_PLAYER_SDL_H_

#include "iaudioplayer.h"

#include <vector>
#include <memory>
#include <SDL2/SDL_audio.h>

class AudioPlayerSDL : public IAudioPlayer
{
public:
    AudioPlayerSDL(void);
    virtual ~AudioPlayerSDL(void);

    virtual bool play(const std::shared_ptr<IAudioSample> &audioSample) override;
    virtual bool play(void);
    virtual bool pause(void) override;
    virtual bool stop(void) override;
    virtual bool seek(float pos) override;
    virtual void stream(float *stream, size_t length) override;

private:
    SDL_AudioDeviceID m_audioDevice;

    std::shared_ptr<IAudioSample> m_sample;
};

#endif // _AUDIO_PLAYER_SDL_H_
