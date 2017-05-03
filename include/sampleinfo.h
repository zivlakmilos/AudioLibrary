#ifndef _SAMPLE_INFO_H_
#define _SAMPLE_INFO_H_

#include <cstdint>

struct SampleInfo
{
    SampleInfo(void)
        : freq(48000),
          channels(1) {};

    int32_t freq;
    uint8_t channels;
};

#endif // _SAMPLE_INFO_H_
