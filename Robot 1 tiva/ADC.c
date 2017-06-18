#include "ADC.h"

// passing an array to this function and its size to get the ADC FIFO's data 
// data_get(array_name , size of the array) 
// EX : data_get (ADCValue , 4);
int VL=0;
int ls1=0 ,ls2=0 ,ls3=0,ls4=0,ls5=0,ls6=0,ls7=0,ls8=0;


void data_get (uint32_t *pt , int i )
   {
     int k;
     ADCPSSI_ADC0 = 0x0010;    // start sampling (SS1)
     while((ADCRIS_ADC0 &0x02)==0){};  // wait untill sampling is done (for SS1)
      //get SS FIFO values
     for(k=0 ; k<i ; k++)
       {
        *(pt+k) = ADCSSFIFO1_ADC0 &0xFFF;
       }
      ADCISC_ADC0 = 0x0010;   // set interrupt flag for SS1 
   }



void digital_reads(uint32_t *ADC )
{  if (*(ADC)>1900 && *(ADC)<2080)
    ls1=1;
   else
    ls1=0;

 if (*(ADC+1)>1850 && *(ADC+1)<2070)
      ls2=1;
   else
       ls2=0;
 if (*(ADC+2)>1820 && *(ADC+2)<2070)
    ls3=1;
   else
    ls3=0;
  if (*(ADC+3)>1520 && *(ADC+3)<1750)
    ls4=1;
   else
   ls4=0;
 if (*(ADC+4)>1800 && *(ADC+4)<2050)
    ls5=1;
   else
   ls5=0;
 if (*(ADC+5)>1500 && *(ADC+5)<1680)
    ls6=1;
   else
   ls6=0;
 if (*(ADC+6)>1800 && *(ADC+6)<1990)
    ls7=1;
   else
   ls7=0;
 if (*(ADC+7)>1900 && *(ADC+7)<2060)
    ls8=1;
   else
   ls8=0;
    }


void line ()
{
  data_get ( ADC0Value , 8); // line sensor analog reads 
	digital_reads(ADC0Value);
	
if ((ls1==1) && (ls2==0) && (ls3==0) && (ls4==0) && (ls5==0) && (ls6==0) && (ls7==0) && (ls8==0))
{
     analogWrite(Motor5,690);     //200
     analogWrite(Motor6,63);     //250
     analogWrite(Motor7,2815);     //60 
     analogWrite(Motor8,3065);      //30
     digitalWrite(Motor5,LOW); 
     digitalWrite(Motor6,LOW); 
     digitalWrite(Motor7,HIGH);
     digitalWrite(Motor8,HIGH);
  
  }
if ((ls1==1) && (ls2==1) && (ls3==0) && (ls4==0) && (ls5==0) && (ls6==0) && (ls7==0) && (ls8==0))
{
      analogWrite(Motor5,690); 
     analogWrite(Motor6,63);   
     analogWrite(Motor7,2440);     //60
     analogWrite(Motor8,2815);     //30
     digitalWrite(Motor5,LOW); 
     digitalWrite(Motor6,LOW); 
     digitalWrite(Motor7,HIGH);
     digitalWrite(Motor8,HIGH);
  
  }
if ((ls1==0) && (ls2==1) && (ls3==0) && (ls4==0) && (ls5==0) && (ls6==0) && (ls7==0) && (ls8==0))
{
      analogWrite(Motor5,690); 
     analogWrite(Motor6,63);   
     analogWrite(Motor7,2065);    //90
     analogWrite(Motor8,2440);     //60
     digitalWrite(Motor5,LOW); 
     digitalWrite(Motor6,LOW); 
     digitalWrite(Motor7,HIGH);
     digitalWrite(Motor8,HIGH);
  
  }

if ((ls1==0) && (ls2==1) && (ls3==1) && (ls4==0) && (ls5==0) && (ls6==0) && (ls7==0) && (ls8==0))
{
      analogWrite(Motor5,690); 
     analogWrite(Motor6,63);   
     analogWrite(Motor7,1689);    //120
     analogWrite(Motor8,2065);    //90
     digitalWrite(Motor5,LOW); 
     digitalWrite(Motor6,LOW); 
     digitalWrite(Motor7,HIGH);
     digitalWrite(Motor8,HIGH);
  
  }

if ((ls1==0) && (ls2==0) && (ls3==1) && (ls4==0) && (ls5==0) && (ls6==0) && (ls7==0) && (ls8==0))
{
      analogWrite(Motor5,690); 
     analogWrite(Motor6,63);   
     analogWrite(Motor7,1314);     //150
     analogWrite(Motor8,1089);     //120
     digitalWrite(Motor5,LOW); 
     digitalWrite(Motor6,LOW); 
     digitalWrite(Motor7,HIGH);
     digitalWrite(Motor8,HIGH);
  
  }

if ((ls1==0) && (ls2==0) && (ls3==1) && (ls4==1) && (ls5==0) && (ls6==0) && (ls7==0) && (ls8==0))
{
      analogWrite(Motor5,690); 
     analogWrite(Motor6,63);   
     analogWrite(Motor7,939);     //180
     analogWrite(Motor8,1314);    //150
     digitalWrite(Motor5,LOW); 
     digitalWrite(Motor6,LOW); 
     digitalWrite(Motor7,HIGH);
     digitalWrite(Motor8,HIGH);
  
  }
if ((ls1==0) && (ls2==0) && (ls3==0) && (ls4==1) && (ls5==0) && (ls6==0) && (ls7==0) && (ls8==0))
{
      analogWrite(Motor5,690); 
     analogWrite(Motor6,63);   
     analogWrite(Motor7,563);    //210
     analogWrite(Motor8,939);    //180
     digitalWrite(Motor5,LOW); 
     digitalWrite(Motor6,LOW); 
     digitalWrite(Motor7,HIGH);
     digitalWrite(Motor8,HIGH);
  
  }
 if ((ls1==0) && (ls2==0) && (ls3==0) && (ls4==1) && (ls5==1) && (ls6==0) && (ls7==0) && (ls8==0))
 {  /*analogWrite(Motor5,cw1);
    analogWrite(Motor6,cw2);
    analogWrite(Motor7,ccw3);
    analogWrite(Motor8,ccw4);
    digitalWrite(Motor5,LOW);
    digitalWrite(Motor6,LOW);
    digitalWrite(Motor7,HIGH);
    digitalWrite(Motor8,HIGH);*/
      analogWrite(Motor5,690);   //200
     analogWrite(Motor6,63);     // 250
     analogWrite(Motor7,188);   //240
     analogWrite(Motor8,588);   //208
     digitalWrite(Motor5,LOW); 
     digitalWrite(Motor6,LOW); 
     digitalWrite(Motor7,HIGH);
     digitalWrite(Motor8,HIGH);
 }

 if ((ls1==0) && (ls2==0) && (ls3==0) && (ls4==0) && (ls5==1) && (ls6==0) && (ls7==0) && (ls8==0))
 { 
    /*
    analogWrite(Motor5,cw1);
    analogWrite(Motor6,ccw2);
    analogWrite(Motor7,cw3);
    analogWrite(Motor8,cw4);
    digitalWrite(Motor5,LOW);
    digitalWrite(Motor6,HIGH);
    digitalWrite(Motor7,LOW);
    digitalWrite(Motor8,LOW);*/

      analogWrite(Motor5,1064);    //170
     analogWrite(Motor6,438);      //220
     analogWrite(Motor7,188);  
     analogWrite(Motor8,588);  
     digitalWrite(Motor5,LOW); 
     digitalWrite(Motor6,LOW); 
     digitalWrite(Motor7,HIGH);
     digitalWrite(Motor8,HIGH);
     
 }

 if ((ls1==0) && (ls2==0) && (ls3==0) && (ls4==0) && (ls5==1) && (ls6==1) && (ls7==0) && (ls8==0))
 {
   /*analogWrite(Motor5,ccw1);
    analogWrite(Motor6,ccw2);
    analogWrite(Motor7,ccw3);
    analogWrite(Motor8,ccw4);
    digitalWrite(Motor5,HIGH);
    digitalWrite(Motor6,HIGH);
    digitalWrite(Motor7,HIGH);
    digitalWrite(Motor8,HIGH);*/
  analogWrite(Motor5,1314);   //150
     analogWrite(Motor6,814);  //190 
     analogWrite(Motor7,188);  
     analogWrite(Motor8,588);  
     digitalWrite(Motor5,LOW); 
     digitalWrite(Motor6,LOW); 
     digitalWrite(Motor7,HIGH);
     digitalWrite(Motor8,HIGH);
     
 }
if ((ls1==0) && (ls2==0) && (ls3==0) && (ls4==0) && (ls5==0) && (ls6==1) && (ls7==0) && (ls8==0))
{
  analogWrite(Motor5,1689);     //120
     analogWrite(Motor6,1189);  //160  
     analogWrite(Motor7,188);  
     analogWrite(Motor8,588);  
     digitalWrite(Motor5,LOW); 
     digitalWrite(Motor6,LOW); 
     digitalWrite(Motor7,HIGH);
     digitalWrite(Motor8,HIGH);
  
  }

if ((ls1==0) && (ls2==0) && (ls3==0) && (ls4==0) && (ls5==0) && (ls6==1) && (ls7==1) && (ls8==0))
{
  analogWrite(Motor5,2065);     //90
     analogWrite(Motor6,1564);  //130 
     analogWrite(Motor7,188);  
     analogWrite(Motor8,588);  
     digitalWrite(Motor5,LOW); 
     digitalWrite(Motor6,LOW); 
     digitalWrite(Motor7,HIGH);
     digitalWrite(Motor8,HIGH);
  
  }
  if ((ls1==0) && (ls2==0) && (ls3==0) && (ls4==0) && (ls5==0) && (ls6==0) && (ls7==1) && (ls8==0))
  {
  analogWrite(Motor5,2440);      //60
     analogWrite(Motor6,1940);   //100
     analogWrite(Motor7,188);  
     analogWrite(Motor8,588);  
     digitalWrite(Motor5,LOW); 
     digitalWrite(Motor6,LOW); 
     digitalWrite(Motor7,HIGH);
     digitalWrite(Motor8,HIGH);
  
    }
if ((ls1==0) && (ls2==0) && (ls3==0) && (ls4==0) && (ls5==0) && (ls6==0) && (ls7==1) && (ls8==1))
{
  analogWrite(Motor5,2815);     //30
     analogWrite(Motor6,2315); //70   
     analogWrite(Motor7,188);  
     analogWrite(Motor8,588);  
     digitalWrite(Motor5,LOW); 
     digitalWrite(Motor6,LOW); 
     digitalWrite(Motor7,HIGH);
     digitalWrite(Motor8,HIGH);
  
  }
if ((ls1==0) && (ls2==0) && (ls3==0) && (ls4==0) && (ls5==0) && (ls6==0) && (ls7==0) && (ls8==1))
{
  analogWrite(Motor5,3065);   //10
     analogWrite(Motor6,2690);  //40  
     analogWrite(Motor7,188);  
     analogWrite(Motor8,588);  
     digitalWrite(Motor5,LOW); 
     digitalWrite(Motor6,LOW); 
     digitalWrite(Motor7,HIGH);
     digitalWrite(Motor8,HIGH);
  
  }

  if ((ls1==0) && (ls2==0) && (ls3==0) && (ls4==0) && (ls5==0) && (ls6==0) && (ls7==0) && (ls8==0)) 
 {
 /*analogWrite(Motor5,ccw1);
    analogWrite(Motor6,ccw2);
    analogWrite(Motor7,ccw3);
    analogWrite(Motor8,ccw4);
    digitalWrite(Motor5,HIGH);
    digitalWrite(Motor6,HIGH);
    digitalWrite(Motor7,HIGH);
    digitalWrite(Motor8,HIGH);*/
     MotorStop(Motor5); 
     MotorStop(Motor6);   
     MotorStop(Motor7);  
     MotorStop(Motor8);  
     digitalWrite(Motor5,LOW); 
     digitalWrite(Motor6,LOW); 
     digitalWrite(Motor7,LOW);
     digitalWrite(Motor8,LOW);
 }
 
  if ((ls1==1) && (ls2==1) && (ls3==1) && (ls4==1) && (ls5==1) && (ls6==1) && (ls7==1) && (ls8==1)) 
 {
 /*analogWrite(Motor5,ccw1);
    analogWrite(Motor6,ccw2);
    analogWrite(Motor7,ccw3);
    analogWrite(Motor8,ccw4);
    digitalWrite(Motor5,HIGH);
    digitalWrite(Motor6,HIGH);
    digitalWrite(Motor7,HIGH);
    digitalWrite(Motor8,HIGH);*/
     MotorStop(Motor5); 
     MotorStop(Motor6);   
     MotorStop(Motor7);  
     MotorStop(Motor8);  
     digitalWrite(Motor5,LOW); 
     digitalWrite(Motor6,LOW); 
     digitalWrite(Motor7,LOW);
     digitalWrite(Motor8,LOW);
 }
}
/*
int main()
{
   
    init_adc();

  while(1)
  {

      data_get (ADC0Value , 8 );
      digital_reads(ADC0Value);
  }
    return 0 ;
}

*/



void VerticalLines()
{
	if((VL>=0||VL>=1)&&VL!=3)
	{
		VL++;
	}
	if(VL<=3&&VL!=1)
	{
		VL--;
	}
	
}