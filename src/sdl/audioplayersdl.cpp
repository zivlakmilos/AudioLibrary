#include <zaudio/sdl/audioplayersdl.h>

#include <SDL2/SDL.h>

#include <zaudio/exception.h>
#include <zaudio/sdl/audiosamplesdl.h>

static void _stream(void *userdata, uint8_t *stream, int length)
{
    IAudioPlayer *audioPlayer = (IAudioPlayer*)userdata;
    int16_t *out = (int16_t*)stream;
    length /= 2;

    float data[length];
    for(int i = 0; i < length; i++)
        data[i] = 0.0f;

    audioPlayer->stream(data, length);

    for(int i = 0; i < length; i++)
        out[i] = 32767 * data[i];
}

AudioPlayerSDL::AudioPlayerSDL(void)
    : IAudioPlayer(),
      m_audioDevice(0),
      m_loop(false)
{
    SDL_Init(SDL_INIT_AUDIO);
}

AudioPlayerSDL::~AudioPlayerSDL(void)
{
    if(m_audioDevice != 0)
        SDL_CloseAudioDevice(m_audioDevice);
}

bool AudioPlayerSDL::play(const std::shared_ptr<IAudioSample> &audioSample, bool loop)
{
    if(m_audioDevice != 0)
        SDL_CloseAudioDevice(m_audioDevice);

    SDL_AudioSpec spec;
    SDL_memset(&spec, 0, sizeof(spec));
    spec.freq = audioSample->getSampleInfo().freq;
    spec.format = AUDIO_S16SYS;
    spec.channels = audioSample->getSampleInfo().channels;
    spec.samples = 2048;
    spec.callback = _stream;
    spec.userdata = this;

    m_audioDevice = SDL_OpenAudioDevice(NULL, 0, &spec, NULL, 0);
    if(m_audioDevice == 0)
        return false;

    m_sample = audioSample;
    seek(0.0f);
    SDL_PauseAudioDevice(m_audioDevice, 0);
    m_loop = loop;

    return true;
}

bool AudioPlayerSDL::play(bool loop)
{
    if(!m_sample || m_audioDevice == 0)
        return false;
    SDL_PauseAudioDevice(m_audioDevice, 0);
    m_loop = loop;
    return true;
}

bool AudioPlayerSDL::pause(void)
{
    SDL_PauseAudioDevice(m_audioDevice, 1);
    return true;
}

bool AudioPlayerSDL::stop(void)
{
    SDL_PauseAudioDevice(m_audioDevice, 1);
    seek(0.0f);
    return true;
}

bool AudioPlayerSDL::seek(float pos)
{
    if(!m_sample)
        return false;
    m_sample->seek(pos);
    return true;
}

void AudioPlayerSDL::stream(float *stream, size_t length)
{
    if(!m_sample || m_audioDevice == 0)
        return;
    if(!m_sample->stream(stream, length))
    {
        stop();
        if(m_onSampleEndListener)
            m_onSampleEndListener();
        if(m_loop)
            play(true);
    }

    if(m_onUpdateListener)
        m_onUpdateListener(stream, length);
}

void AudioPlayerSDL::setOnSampleEndListener(std::function<void(void)> onSampleEndListener)
{
    m_onSampleEndListener = onSampleEndListener;
}

void AudioPlayerSDL::setOnUpdateListener(std::function<void(const float*, size_t)> onUpdateListener)
{
    m_onUpdateListener = onUpdateListener;
}
