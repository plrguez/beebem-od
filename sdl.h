#ifndef SDL_HEADER
#define SDL_HEADER

#include <SDL.h>

extern SDL_Joystick *joystick_p;
extern SDL_Surface *frame_buffer_p;


int InitializeSDL(int,char*[]);
#ifdef OPENDINGUX
int SetVideoMode(bool menu=false);
#endif

int InitializeSDLSound(int soundfrequency);
void FreeSDLSound(void);
void AddBytesToSDLSoundBuffer(void *p, int len);

void SDL_Sleep(unsigned int ticks);

unsigned long HowManyBytesLeftInSDLSoundBuffer(void);

void GP2x_Initialize(void);
void GP2x_FreeResources(void);
volatile Uint8* GP2x_GetSoundBuffer(void);

int GP2x_GetCPUSpeed(void);
void GP2x_SetCPUSpeed(unsigned int MHZ);

unsigned long GP2X_timer(void);

void OSS_Mixer_Init(void);
void OSS_Mixer_Quit(void);
int OSS_Mixer_GetVolume(void);
void OSS_Mixer_SetVolume(int new_volume);

#endif
