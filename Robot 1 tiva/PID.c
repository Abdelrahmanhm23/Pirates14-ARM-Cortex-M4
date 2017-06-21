#include "PID.h"


////////Motor lifter 1////////
float kp_ML1=0.50036, ki_ML1=0.04180, kd_ML1=0;
float error_ML1=0, P_ML1=0, I_ML1=0, D_ML1=0, PID_value_ML1=0;
float previous_error_ML1=0, previous_I_ML1=0;
float REF_RPM_ML1=300  , REF_REV_ML1=(135*2) ;    //135 one rev
/////////////////////////////

////////Motor lifter 2////////
float kp_ML2=0.50036, ki_ML2=0.04180, kd_ML2=0;
float error_ML2=0, P_ML2=0, I_ML2=0, D_ML2=0, PID_value_ML2=0;
float previous_error_ML2=0, previous_I_ML2=0;
float REF_RPM_ML2=300  , REF_REV_ML2=(135*2) ;   //135 one rev
/////////////////////////////

////////Motor lifter 3////////
float kp_ML3=1.43596, ki_ML3=0.11253, kd_ML3=-1.523;                  //  1.43596  ,   0.11253
float error_ML3=0, P_ML3=0, I_ML3=0, D_ML3=0, PID_value_ML3=0;
float previous_error_ML3=0, previous_I_ML3=0;
float REF_RPM_ML3=300 , REF_REV_ML3=(135*2);   //135 one rev
/////////////////////////////


////////Motor serve////////////////////////
float kp_MServe=0.50036, ki_MServe=0.04180, kd_MServe=0;                  //  1.43596  ,   0.11253
float error_MServe=0, P_MServe=0, I_MServe=0, D_MServe=0, PID_value_MServe=0;
float previous_error_MServe=0, previous_I_MServe=0;
float REF_RPM_MServe=300 , REF_REV_MServe=(135*2);   //135 one rev
/////////////////////////////




long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void PID_ML1_RPM(int rpm_ref_ML1)
{
error_ML1 = rpm_ref_ML1 - RPM_ML1 ;
	P_ML1 = error_ML1;
	I_ML1 = I_ML1 + error_ML1 ;
	D_ML1 = error_ML1 - previous_error_ML1 ;
	
	PID_value_ML1 = (kp_ML1*P_ML1) + (ki_ML1*I_ML1) + (kd_ML1*D_ML1);
PID_value_ML1=	constrain(PID_value_ML1 , 1,3190 );
PID_value_ML1=	map(PID_value_ML1 , 0 , 3190 , 3190 , 1);
  previous_error_ML1=error_ML1;	
	analogWrite(Motor1,PID_value_ML1);
}


void PID_ML1_REV(int ref_ML1)
{
	error_ML1 = ref_ML1 - Mlifter1counter ;
	P_ML1 = error_ML1;
	I_ML1 = I_ML1 + error_ML1 ;
	D_ML1 = error_ML1 - previous_error_ML1 ;
	
	PID_value_ML1 = (kp_ML1*P_ML1) + (ki_ML1*I_ML1) + (kd_ML1*D_ML1);
  PID_value_ML1=	constrain(PID_value_ML2 , 1,3190 );
PID_value_ML1=	map(PID_value_ML1 , 1 , 3190 , 3190 , 1);
  previous_error_ML1=error_ML1;	
	analogWrite(Motor1,PID_value_ML1);
	if(Mlifter1counter>=ref_ML1)
	{MotorStop(Motor1);}
}


void PID_ML2_RPM(int rpm_ref_ML2)
{
	error_ML2 = rpm_ref_ML2 - RPM_ML2 ;
	P_ML2 = error_ML2;
	I_ML2 = I_ML2 + error_ML2 ;
	D_ML2 = error_ML2 - previous_error_ML2 ;
	
PID_value_ML2 = (kp_ML2*P_ML2) + (ki_ML2*I_ML2) + (kd_ML2*D_ML2);
PID_value_ML2=	constrain(PID_value_ML2 , 1,3190 );
PID_value_ML2=	map(PID_value_ML2 , 0 , 3190 , 3190 , 1);
  previous_error_ML2=error_ML2;	
	analogWrite(Motor2,PID_value_ML2);

}

void PID_ML2_REV(int ref_ML2)
{
	error_ML2 = ref_ML2 - Mlifter2counter ;
	P_ML2 = error_ML2;
	I_ML2 = I_ML2 + error_ML2 ;
	D_ML2 = error_ML2 - previous_error_ML2 ;
	
	
PID_value_ML2 = (kp_ML2*P_ML2) + (ki_ML2*I_ML2) + (kd_ML2*D_ML2);
 PID_value_ML2=	constrain(PID_value_ML2 , 1,3190 );
PID_value_ML2=	map(PID_value_ML2 , 1 , 3190 , 3190 , 1);
  previous_error_ML2=error_ML2;	
	analogWrite(Motor2,PID_value_ML2);
	if(Mlifter2counter>=ref_ML2)
	{MotorStop(Motor2);}
}




void PID_ML3_RPM(int rpm_ref_ML3)
{
	error_ML3 = rpm_ref_ML3 - RPM_ML3 ;
		if(error_ML3>500)
		{error_ML3=4;}
	P_ML3 = error_ML3;
	I_ML3 = I_ML3 + error_ML3 ;
	D_ML3 = error_ML3 - previous_error_ML3 ;
	
	PID_value_ML3 = (kp_ML3*P_ML3) + (ki_ML3*I_ML3) + (kd_ML3*D_ML3);
PID_value_ML3=	constrain(PID_value_ML3 , 1,3190 );
PID_value_ML3=	map(PID_value_ML3 , 0 , 3190 , 3190 , 1);
  previous_error_ML3=error_ML3;	
	analogWrite(Motor3,PID_value_ML3);
}

void PID_ML3_REV(int ref_ML3)
{

	error_ML3 = ref_ML3 - Mlifter3counter ;
	
	P_ML3 = error_ML3;
	I_ML3 = I_ML3 + error_ML3 ;
	D_ML3 = error_ML3 - previous_error_ML3 ;
	PID_value_ML3 = (kp_ML3*P_ML3) + (ki_ML3*I_ML3) + (kd_ML3*D_ML3);
PID_value_ML3=	constrain(PID_value_ML3 , 1,3190 );
PID_value_ML3=	map(PID_value_ML3 , 1 , 3190 , 3190 , 1);
  previous_error_ML3=error_ML3;	
	analogWrite(Motor3,PID_value_ML3);
	if(Mlifter3counter>=ref_ML3)
	{MotorStop(Motor3);}
}


void PID_MServe_RPM(int rpm_ref_MServe)
{
	error_MServe = rpm_ref_MServe - RPM_MServe ;
	P_MServe = error_MServe;
	I_MServe = I_MServe + error_MServe ;
	D_MServe = error_MServe - previous_error_MServe ;
	
	PID_value_MServe = (kp_MServe*P_MServe) + (ki_MServe*I_MServe) + (kd_MServe*D_MServe);
  PID_value_MServe=	constrain(PID_value_MServe , 0,255 );
  PID_value_MServe=	map(PID_value_MServe , 0 , 255 , 3190 , 1000);
  previous_error_MServe=error_MServe;	
	analogWrite(Motor9,PID_value_MServe);   /////Motor 9   serve motor
}