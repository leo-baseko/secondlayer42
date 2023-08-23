#include <stdio.h>
#include <portaudio.h>
#include <math.h>

#define SAMPLE_RATE (44100)
#define AMPLITUDE (0.5)
#define FREQUENCY (440.0)

int audioCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer,
                  const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags,
                  void *userData)
{
    (void)inputBuffer;
	(void)timeInfo;
	(void)statusFlags;
	(void)userData;
	float *out = (float *)outputBuffer;

    for (unsigned int i = 0; i < framesPerBuffer; i++)
	{
        float sample = AMPLITUDE * sin(2 * M_PI * FREQUENCY * i / SAMPLE_RATE);
        *out++ = sample;  // Left channel
        *out++ = sample;  // Right channel
    }
    return (paContinue);
}

int main()
{
    PaError err;
    PaStream *stream;

    err = Pa_Initialize();
    if (err != paNoError)
	{
        fprintf(stderr, "Erreur lors de l'initialisation de PortAudio : %s\n", Pa_GetErrorText(err));
        return 1;
    }
    err = Pa_OpenDefaultStream(&stream, 0, 2, paFloat32, SAMPLE_RATE, paFramesPerBufferUnspecified,
                               audioCallback, NULL);
    if (err != paNoError)
	{
        fprintf(stderr, "Erreur lors de l'ouverture du flux audio : %s\n", Pa_GetErrorText(err));
        return 1;
    }
    err = Pa_StartStream(stream);
    if (err != paNoError)
	{
        fprintf(stderr, "Erreur lors du démarrage du flux audio : %s\n", Pa_GetErrorText(err));
        return 1;
    }
    printf("Joue du son pendant 5 secondes...\n");
    Pa_Sleep(5000);
    err = Pa_StopStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Erreur lors de l'arrêt du flux audio : %s\n", Pa_GetErrorText(err));
        return 1;
    }
    err = Pa_CloseStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Erreur lors de la fermeture du flux audio : %s\n", Pa_GetErrorText(err));
        return 1;
    }
    Pa_Terminate();
    return 0;
}
