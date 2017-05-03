#ifndef _I_AUDIO_PLAYER_H_
#define _I_AUDIO_PLAYER_H_

#include <memory>
#include <functional>

#include "iaudiosample.h"

class IAudioPlayer
{
public:
    virtual ~IAudioPlayer(void) {};

    virtual bool play(const std::shared_ptr<IAudioSample> &sample) = 0;
    virtual bool play(void) = 0;
    virtual bool pause(void) = 0;
    virtual bool stop(void) = 0;
    virtual bool seek(float pos) = 0;
    virtual void stream(float *stream, size_t length) = 0;

    virtual void setOnSampleEndListener(std::function<void(void)> onSampleEndListener) = 0;
};

#endif // _I_AUDIO_PLAYER_H_
