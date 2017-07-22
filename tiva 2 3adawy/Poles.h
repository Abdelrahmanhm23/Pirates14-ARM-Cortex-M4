#ifndef POLES_H_
#define POLES_H_

#include <stdint.h>
#include "MemMap.h"
#include "MotorInit.h"
#include "PID.h"
#include "UART.h"
#include "Motion.h"
#include "spi.h"
#include "pistons.h"
#include "Serve.h"
#include <math.h>
#include "stdlib.h"

extern long desired_pos1;
extern long desired_pos2;
extern long desired_pos3;

extern long current_pos1;
extern long current_pos2;
extern long current_pos3;

extern long pos1;
extern long pos2;
extern long pos3;

void Pole1( long desired_pos1, long desired_pos2, long desired_pos3,int SERVEPWM);
void Pole2( long desired_pos1, long desired_pos2, long desired_pos3,int SERVEPWM);
void Pole3( long desired_pos1, long desired_pos2, long desired_pos3,int SERVEPWM);
void Pole4( long desired_pos1, long desired_pos2, long desired_pos3,int SERVEPWM);
void Pole5( long desired_pos1, long desired_pos2, long desired_pos3,int SERVEPWM);

#endif