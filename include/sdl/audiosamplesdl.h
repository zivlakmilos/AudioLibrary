#ifndef _AUDIO_SAMPLE_SDL_H_
#define _AUDIO_SAMPLE_SDL_H_

#include "iaudiosample.h"

#include <cstdint>
#include <vector>

class AudioSampleSDL : public IAudioSample
{
public:
    AudioSampleSDL(void);
    AudioSampleSDL(const std::vector<float> &data);
    AudioSampleSDL(const AudioSampleSDL &other);
    virtual ~AudioSampleSDL(void);

    virtual void seek(float pos);
    virtual bool stream(float *stream, size_t length) override;

    inline std::vector<float> getData(void) { return m_data; };
    inline void setData(const std::vector<float> &data) { m_data = data; };

    AudioSampleSDL &operator=(const AudioSampleSDL &rhs);

private:
    std::vector<float> m_data;
    size_t m_pos;
};

#endif // _AUDIO_SAMPLE_SDL_H_
