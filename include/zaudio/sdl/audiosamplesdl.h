#ifndef _AUDIO_SAMPLE_SDL_H_
#define _AUDIO_SAMPLE_SDL_H_

#include <zaudio/iaudiosample.h>

#include <cstdint>
#include <vector>

#include <zaudio/sampleinfo.h>

class AudioSampleSDL : public IAudioSample
{
public:
    AudioSampleSDL(const SampleInfo &sampleInfo = SampleInfo());
    AudioSampleSDL(const std::vector<float> &data, const SampleInfo &sampleInfo = SampleInfo());
    AudioSampleSDL(const AudioSampleSDL &other);
    virtual ~AudioSampleSDL(void);

    virtual void seek(float pos) override;
    virtual size_t stream(float *stream, size_t length) override;

    virtual SampleInfo getSampleInfo(void) override { return m_sampleInfo; };

    virtual std::vector<float> getData(void) override { return m_data; };
    virtual void setData(const std::vector<float> &data) override { m_data = data; };

    AudioSampleSDL &operator=(const AudioSampleSDL &rhs);

private:
    std::vector<float> m_data;
    size_t m_pos;

    SampleInfo m_sampleInfo;
};

#endif // _AUDIO_SAMPLE_SDL_H_
