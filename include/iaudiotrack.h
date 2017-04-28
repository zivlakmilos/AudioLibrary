#ifndef _I_AUDIO_TRACK_H_
#define _I_AUDIO_TRACK_H_

#include <cstddef>

class IAudioTrack
{
public:
    virtual ~IAudioTrack(void) {};

    virtual bool play(void) = 0;
    virtual bool pause(void) = 0;
    virtual bool stop(void) = 0;
    virtual bool seek(float pos) = 0;
    virtual void streamData(float *stream, size_t length) = 0;
};

#endif // _I_AUDIO_TRACK_H_
