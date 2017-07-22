#ifndef MOTION_H_
#define MOTION_H_

#include "MemMap.h"
#include "MotorInit.h"


extern unsigned long M5_CW;
extern unsigned long M5_CCW;
extern unsigned long M6_CW;
extern unsigned long M6_CCW;
extern unsigned long M7_CW;
extern unsigned long M7_CCW;
extern unsigned long M8_CW;
extern unsigned long M8_CCW;

extern unsigned long FORWARD[4];
extern unsigned long REVERSE[4];
extern unsigned long LEFT[4];
extern unsigned long RIGHT[4];
extern unsigned long UPRIGHT[4];
extern unsigned long UPLEFT[4];
extern unsigned long DOWNRIGHT[4];
extern unsigned long DOWNLEFT[4];
extern unsigned long CLOCKWISE[4];
extern unsigned long COUNTERCLOCKWISE[4];

extern unsigned long servepwm;

//	y[0]=250;   // 0x3F     63
//	y[1]=233;   // 0x114    276
//	y[2]=250;   // 0x3F     63
//	y[3]=223;   // 0x191    401
//	y[4]=225;   // 0x178    376
//	y[5]=203;   // 0x28B    651
//	y[6]=218;   // 0x1CF    463
//	y[7]=226;   // 0x16B    363 


/*  


  ______________________
  | M5       ^      M6 |
  |        \ | /       |
  |         \|/        |
	|    <-----|----->   |
  |         /|\        |
  | M7     / v \    M8 |       
  | ___________________|


*/
void Stop();
void Forward();
void Reverse();
void Left();
void Right();
void UpRight();
void UpLeft();
void DownRight();
void DownLeft();
void ClockWise();
void CounterClockWise();
void lifter1up();
void lifter1down();
void lifter2up();
void lifter2down();
void lifter12up();
void lifter12down();
void lifter3up();
void lifter3down();
void liftersup();
void liftersdown();
void liftersStop();
void serve();
void servestop();

#endif