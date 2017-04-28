#ifndef _I_AUDIO_PLAYER_H_
#define _I_AUDIO_PLAYER_H_

#include "iaudiotrack.h"

class IAudioPlayer
{
public:
    IAudioPlayer(IAudioDevice &audioDevice) {};
    virtual ~IAudioPlayer(void) {};

    virtual void addTrack(IAudioTrack &track) = 0;
    virtual bool removeTrack(IAudioTrack &track) = 0;
    virtual bool playTrack(IAudioTrack &track) = 0;
    virtual bool pauseTrack(IAudioTrack &track) = 0;
    virtual bool stopTrack(IAudioTrack &track) = 0;
    virtual bool seekTrack(IAudioTrack &track, float pos) = 0;
    virtual void stopAll(void) = 0;
};

#endif // _I_AUDIO_PLAYER_H_
