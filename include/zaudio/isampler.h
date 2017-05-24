#ifndef _I_SAMPLER_H_
#define _I_SAMPLER_H_

#include <zaudio/iaudiosample.h>

class ISampler
{
public:
    virtual ~ISampler(void) {}

    virtual bool play(const IAudioSample &sample) = 0;
    virtual bool stop(void) = 0;
    virtual void stream(float *sample, size_t lenght) = 0;
    virtual void setUpdateListener(void) = 0;
};

#endif // _I_SAMPLER_H_
