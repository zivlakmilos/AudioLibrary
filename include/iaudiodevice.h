#ifndef _I_AUDIO_DEVICE_H_
#define _I_AUDIO_DEVICE_H_

#include <string>

class IAudioDevice
{
public:
    explicit IAudioDevice(const std::string &device) {};
    virtual ~IAudioDevice(void) {};
};

#endif // _I_AUDIO_DEVICE_H_
