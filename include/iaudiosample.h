#ifndef _I_AUDIO_TRACK_H_
#define _I_AUDIO_TRACK_H_

#include <cstddef>

class IAudioSample
{
public:
    virtual ~IAudioTrack(void) {};

    virtual void streamData(float *stream, size_t length) = 0;
};

#endif // _I_AUDIO_TRACK_H_
