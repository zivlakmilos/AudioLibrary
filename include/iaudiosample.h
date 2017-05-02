#ifndef _I_AUDIO_TRACK_H_
#define _I_AUDIO_TRACK_H_

#include <cstddef>

class IAudioSample
{
public:
    virtual ~IAudioSample(void) {};

    virtual void seek(float pos) = 0;
    virtual bool stream(float *stream, size_t length) = 0;
};

#endif // _I_AUDIO_TRACK_H_
