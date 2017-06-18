 /*
stop              (0xAA)
forward           (0x01)
reverse           (0x02)
left              (0x03)
right             (0x04)
upright           (0x05)
upleft            (0x06)
downright         (0x07)
downleft          (0x08)
ClockWise         (0x09)
CounterClockWise  (0x10)
serve start       (0x11)  // R1
serve end         (0x12)  // L1
servo             (0x13) ........
lifter1,2   up    (0x14) // triangle up 
lifter1,2   down  (0x15) //, cross down           
lifter3     up    (0x16) // circle up 
lifter3   down    (0x17) // square down
lifters up        (0x18) // up all lifters
lifters down      (0x19) // down all lifters 
lifters stop      (0x20) // stop all lifters 
servepwm up       (0x21) // increments pwm 
servepwm down     (0x22) // decrements pwm
*/
#define PIN_SCE   22
#define PIN_RESET 23
#define PIN_DC    24
#define PIN_SDIN  25
#define PIN_SCLK  26

#define ss1        48
#define ss2        49

#define LCD_C     LOW
#define LCD_D     HIGH

#define LCD_X     84
#define LCD_Y     48
#include<stdlib.h>

char string[8];

int m1spdCW = 250 ;                // adjust this macros to set speed
int m2spdCW = 233 ;
int m3spdCW = 250 ;
int m4spdCW = 223 ;

int m1spdCCW = 225;                // adjust this macros to set speed
int m2spdCCW = 203;
int m3spdCCW = 218;
int m4spdCCW = 226;

int serve = 200 ;

int pos = 0;    // variable to store the servo position

#include <Servo.h>
Servo servo;
#include <SPI.h> 
#include <PS3BT.h>

#include <usbhub.h>
// Satisfy IDE, which only needs to see the include statment in the ino.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif

USB Usb;
USBHub Hub1(&Usb); // Some dongles have a hub inside
//PS3USB PS3(&Usb);
BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so
/* You can create the instance of the class in two ways */
PS3BT PS3(&Btd); // This will just create the instance
//PS3BT PS3(&Btd, 0x00, 0x15, 0x83, 0x3D, 0x0A, 0x57); // This will also store the bluetooth address - this can be obtained from the dongle when running the sketch


void left();
void stop();
void right();
void forward();
void reverse();
void upleft();
void upright();
void downleft();
void downright();
void SERVE();
void lifter12();
void lifter3();
void lifters();
void liftersStop();
void inc();
void dec();
void TIVA1(uint32_t value);
void TIVA2(uint32_t value); 

void setup() {
  // put your setup code here, to run once:
   Serial.begin(115200);
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 USB Library Started"));
  /*
    LcdInitialise();
  LcdClear();
  Nokia5110_SetCursor(0,0); // position of the next char.
  LcdString("serve: ");    // the desired char.
  Nokia5110_SetCursor(0,1);
   LcdString("M2 CW: ");
   Nokia5110_SetCursor(0,2);
   LcdString("M3 CW:");
   Nokia5110_SetCursor(0,3);
   LcdString("M4 CCW:");
   */
pinMode(ss1, OUTPUT);
   digitalWrite(ss1, HIGH);
//////// I think those two lines were missed////////////////
 pinMode(ss2, OUTPUT);           
    digitalWrite(ss2, HIGH);
 ///////////////////////////////////////////
   SPI.setClockDivider(SPI_CLOCK_DIV8);
    SPI.begin();
}

void loop() {
  Usb.Task();

  if (PS3.PS3Connected || PS3.PS3NavigationConnected) {

    digitalRead(PS3.getAnalogHat (LeftHatX) && PS3.getAnalogHat(LeftHatY) &&  PS3.getAnalogHat (RightHatX) && PS3.getAnalogHat(RightHatY));

    while (1) // left
    {
      Usb.Task();

      if (PS3.PS3Connected || PS3.PS3NavigationConnected) {      
         SERVE();
         inc();
         dec();
        if (PS3.getAnalogHat (LeftHatX)  ==0 && PS3.getAnalogHat(LeftHatY) == 128 ) //left
        {
          left();
          SERVE();
        } 
          // right direction
        if (  PS3.getAnalogHat (LeftHatX) ==255 && PS3.getAnalogHat(LeftHatY) ==128)
        {
          right();
          SERVE();
        }
  if (PS3.getAnalogHat(LeftHatX) == 128 && PS3.getAnalogHat(LeftHatY) == 128 ) 
  {
     SERVE();
    stop();
    break;
    }
  // up(robot moves forward)
        if (PS3.getAnalogHat(LeftHatX)==128  && PS3.getAnalogHat(LeftHatY) == 0) // up(robot moves forward)
        {  
          forward();
           SERVE();
        }            
        //down
        if (PS3.getAnalogHat(LeftHatX)==128 &&  PS3.getAnalogHat(LeftHatY) == 255)
        {
          reverse();
           SERVE();
        }
          if (PS3.getAnalogHat(LeftHatX) == 128 && PS3.getAnalogHat(LeftHatY) == 128 ) 
  {
     SERVE();
    stop();
    break;
    }
        // Up left
          if (PS3.getAnalogHat(LeftHatX) ==0 && PS3.getAnalogHat(LeftHatY)== 0  )
        {
          upleft();
           SERVE();
        }

         //45 upright
        if (PS3.getAnalogHat(LeftHatX) == 255 && PS3.getAnalogHat(LeftHatY)==0)
        {
          upright();
           SERVE();
        }
   //45 downleft
        if (PS3.getAnalogHat(LeftHatX) == 0  && PS3.getAnalogHat(LeftHatY) == 255)
        {
          downleft();
           SERVE();
        }
        if (PS3.getAnalogHat(LeftHatX) == 255  && PS3.getAnalogHat(LeftHatY) == 255)
        {
          downright();
           SERVE();
           }
  if (PS3.getAnalogHat(LeftHatX) == 128 && PS3.getAnalogHat(LeftHatY) == 128 ) 
  {
    SERVE();
    stop();
    break;
    }
}
      else
  {
   stop();
   break;
        }
       }
         while (1) // right
    {
      Usb.Task();

       if (PS3.PS3Connected || PS3.PS3NavigationConnected) {
        dec();
        inc();
        SERVE();
         if (  PS3.getAnalogHat (RightHatX) ==255 && PS3.getAnalogHat(LeftHatY) ==128 )
        {
          ClockWise();
           SERVE();
        }
           if (  PS3.getAnalogHat (RightHatX) ==128 && PS3.getAnalogHat(LeftHatY) ==128 )
        {
          SERVE();
          stop();
          break;
        }
            if (  PS3.getAnalogHat (RightHatX) ==0 && PS3.getAnalogHat(LeftHatY) ==128 )
        {
          CounterClockWise();
           SERVE();
        }
       if (  PS3.getAnalogHat (RightHatX) ==128 && PS3.getAnalogHat(LeftHatY) ==128 )
        {
          SERVE();
          stop();
          break;
        }
        
          }
       else{
        stop();
        break;
       }
       }
    }
    
  }
 

void TIVA1(uint32_t value) {
  SPI.transfer(0x00);
  digitalWrite(ss1, LOW);   
 SPI.transfer(value);
  digitalWrite(ss1, HIGH);
}
void TIVA2(uint32_t value) {
//why not   SPI.transfer(0x00); at the start like TIVA1  ?!!!
digitalWrite(ss2, LOW);
 SPI.transfer(value);
  digitalWrite(ss2, HIGH);
}
void stop()
{TIVA1(0xFF);}
void forward()
{ TIVA1(0x01); }
void reverse()
{ TIVA1(0x02); }
void left()
{TIVA1(0x03);}
void right()
{TIVA1(0x04);}
void upright()
{TIVA1(0x05);}
void upleft()
{TIVA1(0x06);}
void downright()
{TIVA1(0x07);}
void downleft()
{TIVA1(0x08);}
void ClockWise() 
{TIVA1(0x09);}
void CounterClockWise()
{TIVA1(0x10);}
void SERVE()
{
  if(PS3.getAnalogButton(R1)>50) // start
  {TIVA1(0x11);}
  if(PS3.getAnalogButton(L1)>50) // stop
  { TIVA1(0x12);}
  lifter12();
  lifter3();
  lifters();
  inc();
  dec();
 // liftersStop();
}

void saucer()
{TIVA1(0x13);}

void lifter12()
{
  while(1)
    {
      Usb.Task();
      if (PS3.PS3Connected || PS3.PS3NavigationConnected) {
   if(PS3.getAnalogButton(TRIANGLE)>100) 
   {
     TIVA1(0x14); }
   else
   { liftersStop();
     break;}
  }
}

  while(1)
    {
      Usb.Task();
      if (PS3.PS3Connected || PS3.PS3NavigationConnected) {
   if(PS3.getAnalogButton(CROSS)>100)
   {
  TIVA1(0x15);
    }
else
  {liftersStop();
    break;}
      }
   }
  }
           
void lifter3()
{
   while(1)
    {
      Usb.Task();
      if (PS3.PS3Connected || PS3.PS3NavigationConnected) {
  if(PS3.getAnalogButton(CIRCLE)>100)
   {  TIVA1(0x16);}
 else
  {liftersStop();
    break;}
   }
    }
    while(1)
    {
      Usb.Task();
      if (PS3.PS3Connected || PS3.PS3NavigationConnected) {
   if(PS3.getAnalogButton(SQUARE)>100) 
   {TIVA1(0x17);}
  else
   {liftersStop();
    break;}
   }
   }
}
void lifters()
{
  while(1)
    {
      Usb.Task();
      if (PS3.PS3Connected || PS3.PS3NavigationConnected) {
  if(PS3.getAnalogButton(UP)>100)
   {TIVA1(0x18);  }
     else
     {liftersStop();
   //Serial.println(PS3.getAnalogButton(UP));
    break;}
      }
   }
   while(1)
    {
      Usb.Task();
      if (PS3.PS3Connected || PS3.PS3NavigationConnected) {
  if(PS3.getAnalogButton(DOWN)>100)
   { TIVA1(0x19); }
   else
    {liftersStop();
    break;}
   }
  }
}
void liftersStop()
{

   TIVA1(0x20);
}
void dec()
{
   if(PS3.getAnalogButton(LEFT)>50)
   {
  TIVA1(0x22);}
 }
 void inc()
 {
 if(PS3.getAnalogButton(RIGHT)>50)
   {
  TIVA1(0x21);}
 }


static const byte ASCII[][5] =
{
 {0x00, 0x00, 0x00, 0x00, 0x00} // 20  
,{0x00, 0x00, 0x5f, 0x00, 0x00} // 21 !
,{0x00, 0x07, 0x00, 0x07, 0x00} // 22 "
,{0x14, 0x7f, 0x14, 0x7f, 0x14} // 23 #
,{0x24, 0x2a, 0x7f, 0x2a, 0x12} // 24 $
,{0x23, 0x13, 0x08, 0x64, 0x62} // 25 %
,{0x36, 0x49, 0x55, 0x22, 0x100} // 26 &
,{0x00, 0x05, 0x03, 0x00, 0x00} // 27 '
,{0x00, 0x1c, 0x22, 0x41, 0x00} // 28 (
,{0x00, 0x41, 0x22, 0x1c, 0x00} // 29 )
,{0x14, 0x08, 0x3e, 0x08, 0x14} // 2a *
,{0x08, 0x08, 0x3e, 0x08, 0x08} // 2b +
,{0x00, 0x50, 0x30, 0x00, 0x00} // 2c ,
,{0x08, 0x08, 0x08, 0x08, 0x08} // 2d -
,{0x00, 0x60, 0x60, 0x00, 0x00} // 2e .
,{0x20, 0x10, 0x08, 0x04, 0x02} // 2f /
,{0x3e, 0x51, 0x49, 0x45, 0x3e} // 30 0
,{0x00, 0x42, 0x7f, 0x40, 0x00} // 31 1
,{0x42, 0x61, 0x51, 0x49, 0x46} // 32 2
,{0x21, 0x41, 0x45, 0x4b, 0x31} // 33 3
,{0x18, 0x14, 0x12, 0x7f, 0x10} // 34 4
,{0x27, 0x45, 0x45, 0x45, 0x39} // 35 5
,{0x3c, 0x4a, 0x49, 0x49, 0x30} // 36 6
,{0x01, 0x71, 0x09, 0x05, 0x03} // 37 7
,{0x36, 0x49, 0x49, 0x49, 0x36} // 38 8
,{0x06, 0x49, 0x49, 0x29, 0x1e} // 39 9
,{0x00, 0x36, 0x36, 0x00, 0x00} // 3a :
,{0x00, 0x56, 0x36, 0x00, 0x00} // 3b ;
,{0x08, 0x14, 0x22, 0x41, 0x00} // 3c <
,{0x14, 0x14, 0x14, 0x14, 0x14} // 3d =
,{0x00, 0x41, 0x22, 0x14, 0x08} // 3e >
,{0x02, 0x01, 0x51, 0x09, 0x06} // 3f ?
,{0x32, 0x49, 0x79, 0x41, 0x3e} // 40 @
,{0x7e, 0x11, 0x11, 0x11, 0x7e} // 41 A
,{0x7f, 0x49, 0x49, 0x49, 0x36} // 42 B
,{0x3e, 0x41, 0x41, 0x41, 0x22} // 43 C
,{0x7f, 0x41, 0x41, 0x22, 0x1c} // 44 D
,{0x7f, 0x49, 0x49, 0x49, 0x41} // 45 E
,{0x7f, 0x09, 0x09, 0x09, 0x01} // 46 F
,{0x3e, 0x41, 0x49, 0x49, 0x7a} // 47 G
,{0x7f, 0x08, 0x08, 0x08, 0x7f} // 48 H
,{0x00, 0x41, 0x7f, 0x41, 0x00} // 49 I
,{0x20, 0x40, 0x41, 0x3f, 0x01} // 4a J
,{0x7f, 0x08, 0x14, 0x22, 0x41} // 4b K
,{0x7f, 0x40, 0x40, 0x40, 0x40} // 4c L
,{0x7f, 0x02, 0x0c, 0x02, 0x7f} // 4d M
,{0x7f, 0x04, 0x08, 0x10, 0x7f} // 4e N
,{0x3e, 0x41, 0x41, 0x41, 0x3e} // 4f O
,{0x7f, 0x09, 0x09, 0x09, 0x06} // 50 P
,{0x3e, 0x41, 0x51, 0x21, 0x5e} // 51 Q
,{0x7f, 0x09, 0x19, 0x29, 0x46} // 52 R
,{0x46, 0x49, 0x49, 0x49, 0x31} // 53 S
,{0x01, 0x01, 0x7f, 0x01, 0x01} // 54 T
,{0x3f, 0x40, 0x40, 0x40, 0x3f} // 55 U
,{0x1f, 0x20, 0x40, 0x20, 0x1f} // 56 V
,{0x3f, 0x40, 0x38, 0x40, 0x3f} // 57 W
,{0x63, 0x14, 0x08, 0x14, 0x63} // 58 X
,{0x07, 0x08, 0x70, 0x08, 0x07} // 59 Y
,{0x61, 0x51, 0x49, 0x45, 0x43} // 5a Z
,{0x00, 0x7f, 0x41, 0x41, 0x00} // 5b [
,{0x02, 0x04, 0x08, 0x10, 0x20} // 5c ¥
,{0x00, 0x41, 0x41, 0x7f, 0x00} // 5d ]
,{0x04, 0x02, 0x01, 0x02, 0x04} // 5e ^
,{0x40, 0x40, 0x40, 0x40, 0x40} // 5f _
,{0x00, 0x01, 0x02, 0x04, 0x00} // 60 `
,{0x20, 0x54, 0x54, 0x54, 0x78} // 61 a
,{0x7f, 0x48, 0x44, 0x44, 0x38} // 62 b
,{0x38, 0x44, 0x44, 0x44, 0x20} // 63 c
,{0x38, 0x44, 0x44, 0x48, 0x7f} // 64 d
,{0x38, 0x54, 0x54, 0x54, 0x18} // 65 e
,{0x08, 0x7e, 0x09, 0x01, 0x02} // 66 f
,{0x0c, 0x52, 0x52, 0x52, 0x3e} // 67 g
,{0x7f, 0x08, 0x04, 0x04, 0x78} // 68 h
,{0x00, 0x44, 0x7d, 0x40, 0x00} // 69 i
,{0x20, 0x40, 0x44, 0x3d, 0x00} // 6a j 
,{0x7f, 0x10, 0x28, 0x44, 0x00} // 6b k
,{0x00, 0x41, 0x7f, 0x40, 0x00} // 6c l
,{0x7c, 0x04, 0x18, 0x04, 0x78} // 6d m
,{0x7c, 0x08, 0x04, 0x04, 0x78} // 6e n
,{0x38, 0x44, 0x44, 0x44, 0x38} // 6f o
,{0x7c, 0x14, 0x14, 0x14, 0x08} // 70 p
,{0x08, 0x14, 0x14, 0x18, 0x7c} // 71 q
,{0x7c, 0x08, 0x04, 0x04, 0x08} // 72 r
,{0x48, 0x54, 0x54, 0x54, 0x20} // 73 s
,{0x04, 0x3f, 0x44, 0x40, 0x20} // 74 t
,{0x3c, 0x40, 0x40, 0x20, 0x7c} // 75 u
,{0x1c, 0x20, 0x40, 0x20, 0x1c} // 76 v
,{0x3c, 0x40, 0x30, 0x40, 0x3c} // 77 w
,{0x44, 0x28, 0x10, 0x28, 0x44} // 78 x
,{0x0c, 0x50, 0x50, 0x50, 0x3c} // 79 y
,{0x44, 0x64, 0x54, 0x4c, 0x44} // 7a z
,{0x00, 0x08, 0x36, 0x41, 0x00} // 7b {
,{0x00, 0x00, 0x7f, 0x00, 0x00} // 7c |
,{0x00, 0x41, 0x36, 0x08, 0x00} // 7d }
,{0x10, 0x08, 0x08, 0x10, 0x08} // 7e ←
,{0x78, 0x46, 0x41, 0x46, 0x78} // 7f →
};




void Nokia5110_SetCursor(unsigned char newX, unsigned char newY){
  if((newX > 11) || (newY > 5)){        // bad input
    return;                             // do nothing
  }
  // multiply newX by 7 because each character is 7 columns wide
  LcdWrite(0, 0x80|(newX*7));     // setting bit 7 updates X-position
  LcdWrite(0, 0x40|newY);         // setting bit 6 updates Y-position
}

void LcdCharacter(char character)
{
  LcdWrite(LCD_D, 0x00);
  for (int index = 0; index < 5; index++)
  {
    LcdWrite(LCD_D, ASCII[character - 0x20][index]);
  }
  LcdWrite(LCD_D, 0x00);
}

void LcdClear(void)
{
  for (int index = 0; index < LCD_X * LCD_Y / 8; index++)
  {
    LcdWrite(LCD_D, 0x00);
  }
Nokia5110_SetCursor(0,2);
}

void LcdInitialise(void)
{
  pinMode(PIN_SCE, OUTPUT);
  pinMode(PIN_RESET, OUTPUT);
  pinMode(PIN_DC, OUTPUT);
  pinMode(PIN_SDIN, OUTPUT);
  pinMode(PIN_SCLK, OUTPUT);
  pinMode(A2,INPUT);
  digitalWrite(PIN_RESET, LOW);
  digitalWrite(PIN_RESET, HIGH);
  LcdWrite(LCD_C, 0x21 );  // LCD Extended Commands.
  LcdWrite(LCD_C, 0xbf );  // Set LCD Vop (Contrast). 
  LcdWrite(LCD_C, 0x04 );  // Set Temp coefficent. //0x04
  LcdWrite(LCD_C, 0x00 );  // LCD bias mode 1:48. //0x13
  LcdWrite(LCD_C, 0x20 );  // LCD Basic Commands
  LcdWrite(LCD_C, 0x0C );  // LCD in normal mode.
  
}

void LcdString(char *characters)
{
  while (*characters)
  {
    LcdCharacter(*characters++);
  }
}

void LcdWrite(byte dc, byte data)
{
  digitalWrite(PIN_DC, dc);
  digitalWrite(PIN_SCE, LOW);
  shiftOut(PIN_SDIN, PIN_SCLK, MSBFIRST, data);
  digitalWrite(PIN_SCE, HIGH);
}

void LcdWriteCmd(byte cmd)
{
  digitalWrite(PIN_DC, LOW); //DC pin is low for commands
  digitalWrite(PIN_SCE, LOW);
  shiftOut(PIN_SDIN, PIN_SCLK, MSBFIRST, cmd); //transmit serial data
  digitalWrite(PIN_SCE, HIGH);
}


void LcdXY(int x, int y)
{
  LcdWriteCmd(0x80 | x);  // Column.
  LcdWriteCmd(0x40 | y);  // Row.
}





