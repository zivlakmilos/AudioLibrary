#include <zaudio/sdl/audiosamplersdl.h>

#include <SDL2/SDL.h>

static void _stream(void *userdata, uint8_t *stream, int lenght)
{
    IAudioSampler *sampler = (IAudioSampler*)userdata;
    int16_t *out = (int16_t*)stream;
    lenght /= 2;

    float data[lenght];
    for(int i = 0; i < lenght; i++)
        data[i] = 0.0f;

    sampler->stream(data, lenght);

    for(int i = 0; i < lenght; i++)
        out[i] = 32767 * data[i];
}

AudioSamplerSDL::AudioSamplerSDL(void)
    : IAudioSampler(),
      m_audioDevice(0)
{
    SDL_Init(SDL_INIT_AUDIO);
}

AudioSamplerSDL::~AudioSamplerSDL(void)
{
    if(m_audioDevice != 0)
        SDL_CloseAudioDevice(m_audioDevice);
}

bool AudioSamplerSDL::play(const std::shared_ptr<IAudioSample> &sample)
{
    if(m_audioDevice == 0)
    {
        SampleInfo info = sample->getSampleInfo();

        SDL_AudioSpec spec;
        SDL_memset(&spec, 0, sizeof(spec));
        spec.freq = info.freq;
        spec.format = AUDIO_S16SYS;
        spec.channels = info.channels;
        spec.samples = 2048;
        spec.callback = _stream;
        spec.userdata = this;

        m_audioDevice = SDL_OpenAudioDevice(NULL, 0, &spec, NULL, 0);
        if(m_audioDevice == 0)
            return false;
    }

    bool exists = false;
    for(auto sample : m_samples)
    {
        if(sample == sample)
        {
            sample->seek(0.0f);
            exists = true;
        }
    }
    if(!exists)
        m_samples.push_back(sample);
    SDL_PauseAudioDevice(m_audioDevice, 0);

    return true;
}

bool AudioSamplerSDL::stop(void)
{
    if(m_audioDevice != 0)
        SDL_PauseAudioDevice(m_audioDevice, 1);

    return true;
}

void AudioSamplerSDL::stream(float *sample, size_t lenght)
{
    if(m_samples.empty())
    {
        stop();
        return;
    }

    float tmpSamples[lenght];

    for(int i = 0; i < lenght; i++)
        tmpSamples[i] = 0.0f;

    int count = m_samples.size();
    for(auto it = m_samples.begin(); it != m_samples.end(); it++)
    {
        size_t lenght2 = (*it)->stream(tmpSamples, lenght);

        for(int i = 0; i < lenght2; i++)
            sample[i] += tmpSamples[i];

        if(lenght2 < lenght)
            m_samples.erase(it--);
    }

    for(int i = 0; i < lenght; i++)
        sample[i] /= (float)count;
}

void AudioSamplerSDL::setUpdateListener(std::function<void(float *data, size_t)> updateListener)
{
    m_updateListener = updateListener;
}
