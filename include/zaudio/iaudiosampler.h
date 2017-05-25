#ifndef _I_AUDIO_SAMPLER_H_
#define _I_AUDIO_SAMPLER_H_

#include <memory>
#include <functional>

#include <zaudio/iaudiosample.h>

class IAudioSampler
{
public:
    virtual ~IAudioSampler(void) {}

    virtual bool play(const std::shared_ptr<IAudioSample> &sample) = 0;
    virtual bool stop(void) = 0;
    virtual void stream(float *sample, size_t lenght) = 0;
    virtual void setUpdateListener(std::function<void(float*, size_t)> updateListener) = 0;
};

#endif // _I_AUDIO_SAMPLER_H_
