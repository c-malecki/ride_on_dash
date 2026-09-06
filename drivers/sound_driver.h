#ifndef __SOUND_DRIVER_H_
#define __SOUND_DRIVER_H_

#include "esp_err.h"
#include <stdio.h>

/*
  MAX98357a Class D Audio Amplifier
*/

#define AUDIO_AMP_PIN_LRC (15)
#define AUDIO_AMP_PIN_BCLK (7)
#define AUDIO_AMP_PIN_DIN (6)

#define SOUND_DRIVER_VOLUME_0 0
#define SOUND_DRIVER_VOLUME_1 ? // 1_3dB
#define SOUND_DRIVER_VOLUME_2 ? // 1_6dB
#define SOUND_DRIVER_VOLUME_3 ? // 1_9dB
#define SOUND_DRIVER_VOLUME_4 ? // 1_12dB
#define SOUND_DRIVER_VOLUME_5 ? // 15db

esp_err_t SOUND_DRIVER_Init(void);
void SOUND_DRIVER_Play(FILE *wav_file);

#endif // __SOUND_DRIVER_H_