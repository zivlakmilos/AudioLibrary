#include "sdl/audiosamplesdl.h"

#include <cstdint>

AudioSampleSDL::AudioSampleSDL(const SampleInfo &sampleInfo)
    : IAudioSample(),
      m_sampleInfo(sampleInfo)
{
}

AudioSampleSDL::AudioSampleSDL(const std::vector<float> &data, const SampleInfo &sampleInfo)
    : IAudioSample(),
      m_data(data),
      m_pos(0),
      m_sampleInfo(sampleInfo)
{
}

AudioSampleSDL::AudioSampleSDL(const AudioSampleSDL &other)
    : IAudioSample(),
      m_data(other.m_data),
      m_pos(0)
{
}

AudioSampleSDL::~AudioSampleSDL(void)
{
}

void AudioSampleSDL::seek(float pos)
{
    m_pos = pos * m_data.size();
}

bool AudioSampleSDL::stream(float *stream, size_t length)
{
    if(m_pos >= m_data.size())
        return false;

    length = (m_data.size() - m_pos < length) ? m_data.size() - m_pos : length;

    for(int i = 0; i < length; i++)
        stream[i] = m_data[m_pos + i];
    m_pos += length;

    return true;
}

AudioSampleSDL &AudioSampleSDL::operator=(const AudioSampleSDL &rhs)
{
    if(this == &rhs)
        return *this;

    m_data = rhs.m_data;
    seek(0.0f);

    return *this;
}
