#ifndef _I_AUDIO_PLAYER_H_
#define _I_AUDIO_PLAYER_H_

#include "iaudiosample.h"

class IAudioPlayer
{
public:
    virtual ~IAudioPlayer(void) {};

    virtual bool playSample(IAudioSample &sample) = 0;
    virtual bool pauseSample(IAudioSample &sample) = 0;
    virtual bool stopSample(IAudioSample &sample) = 0;
    virtual bool seekSample(IAudioSample &sample, float pos) = 0;
    virtual void stopAll(void) = 0;
    virtual void stream(float *stream, size_t length);
};

#endif // _I_AUDIO_PLAYER_H_
