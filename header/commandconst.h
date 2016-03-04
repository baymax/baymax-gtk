#ifndef COMMANDCONST_H
#define COMMANDCONST_H

#include <stdint.h>

const int32_t FAN_SPEED_0 = 0x1;
const int32_t FAN_SPEED_1 = 0x2;
const int32_t FAN_SPEED_2 = 0x4;
const int32_t FAN_SPEED_3 = 0x8;
const int32_t FAN_SPEED_4 = 0x10;

const int32_t SUSPENSION_MODE_LOW = 0x20;
const int32_t SUSPENSION_MODE_NORMAL = 64;
const int32_t SUSPENSION_MODE_HIGH = 128;

const int32_t INTERIOR_LIGTH_ON = 256;
const int32_t INTERIOR_LIGTH_OFF = 512;

const int32_t SPOILER_MODE_AUTO = 1024;
const int32_t SPOILER_MODE_OFF = 2048;

const int32_t SPORT_MODE_ON = 4096;
const int32_t SPORT_MODE_OFF = 8192;

const int32_t REGENERATION_ON = 16384;
const int32_t REGENERATION_OFF = 32768;


const int32_t FAN_SPEED = 0x1F;
const int32_t SUSPENSION_MODE = 224;
const int32_t INTERIOR_LIGTH = 768;
const int32_t SPOILER_MODE = 3072;
const int32_t SPORT_MODE = 12288;
const int32_t REGERATION = 49152;

#endif // COMMANDCONST_H