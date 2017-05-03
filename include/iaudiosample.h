#ifndef _I_AUDIO_TRACK_H_
#define _I_AUDIO_TRACK_H_

#include <cstddef>

#include "sampleinfo.h"

class IAudioSample
{
public:
    virtual ~IAudioSample(void) {};

    virtual void seek(float pos) = 0;
    virtual bool stream(float *stream, size_t length) = 0;

    virtual SampleInfo getSampleInfo(void) = 0;
};

#endif // _I_AUDIO_TRACK_H_
