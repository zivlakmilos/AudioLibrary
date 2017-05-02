#include "sdl/audioplayersdl.h"

#include <SDL2/SDL.h>

#include "exception.h"
#include "sdl/audiosamplesdl.h"

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
    : IAudioPlayer()
{
    SDL_Init(SDL_INIT_AUDIO);

    SDL_AudioSpec spec;
    SDL_memset(&spec, 0, sizeof(spec));
    spec.freq = 44100;
    spec.format = AUDIO_S16SYS;
    spec.channels = 2;
    spec.samples = 2048;
    spec.callback = _stream;
    spec.userdata = this;

    m_audioDevice = SDL_OpenAudioDevice(NULL, 0, &spec, NULL, 0);
    if(m_audioDevice == 0)
        throw Exception("Can't open audio device");
}

AudioPlayerSDL::~AudioPlayerSDL(void)
{
    SDL_CloseAudioDevice(m_audioDevice);
}

bool AudioPlayerSDL::play(const std::shared_ptr<IAudioSample> &audioSample)
{
    m_sample = audioSample;
    seek(0.0f);
    SDL_PauseAudioDevice(m_audioDevice, 0);
    return true;
}

bool AudioPlayerSDL::play(void)
{
    if(!m_sample)
        return false;
    SDL_PauseAudioDevice(m_audioDevice, 0);
    return true;
}

bool AudioPlayerSDL::pause(void)
{
    SDL_PauseAudioDevice(m_audioDevice, 1);
    return true;
}

bool AudioPlayerSDL::stop(void)
{
    SDL_PauseAudioDevice(m_audioDevice, 0);
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
    if(!m_sample)
        return;
    if(!m_sample->stream(stream, length))
        stop();
}