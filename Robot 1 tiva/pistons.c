#include "pistons.h"
/*
int n =0 ;
int count=0 ;
int counter = 0;

void LOAD()
{
	TIMER4A_Start();
if(n==0)
{ digitalWrite(LOADING1,HIGH);
	TIMER4A_Start();
}
else if(n==1)
{
	digitalWrite(LOADING2,HIGH);
	TIMER4A_Handler();
}
}


void TIMER4A_Handler ()
 {
 GPTMICR4 = 0x00000001; 
	 counter++;
	 if(count == 0)
	 {digitalWrite(LOADING1,LOW);
		digitalWrite(ServePiston,HIGH);
	  count=1;
	 }
	 else if(count == 1)
	 { digitalWrite(ServePiston,LOW);
		 n=1;
		 count=2;
	 }
	 if(count == 2)
	 {digitalWrite(LOADING2,LOW);
		digitalWrite(ServePiston,HIGH);
	  count=3;
	 }
	 else if(count == 3)
	 { digitalWrite(ServePiston,LOW);
		 n=0;
		 count=0;
	 }
	 
 }
 void TIMER4A_Stop(void){ 
  GPTMCTL4 &= ~0x00000001; // disable
}
void TIMER4A_Start(void){ 
  GPTMCTL4 |= 0x00000001;   // enable
}*/