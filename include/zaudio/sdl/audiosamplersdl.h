#ifndef _AUDIO_SAMPLER_SDL_H_
#define _AUDIO_SAMPLER_SDL_H_

#include <zaudio/iaudiosampler.h>

#include <SDL2/SDL_audio.h>

class AudioSamplerSDL : public IAudioSampler
{
public:
    AudioSamplerSDL(void);
    virtual ~AudioSamplerSDL(void);

    virtual bool play(const std::shared_ptr<IAudioSample> &sample) override;
    virtual bool stop(void) override;
    virtual void stream(float* sample, size_t lenght) override;
    virtual void setOnAllSamplesEndListener(std::function<void(void)> onAllSamplesEndListener) override;
    virtual void setUpdateListener(std::function<void(float*, size_t)> updateListener) override;

private:
    SDL_AudioDeviceID m_audioDevice;

    std::vector<std::shared_ptr<IAudioSample>> m_samples;

    std::function<void(void)> m_onAllSamplesEndListener;
    std::function<void(float*, size_t)> m_updateListener;
};

#endif // _AUDIO_SAMPLER_SDL_H_
