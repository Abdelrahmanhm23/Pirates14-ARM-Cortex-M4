#ifndef PID_H_
#define PID_H_


#include "MemMap.h"
#include "MotorInit.h"
#include "encoders.h"


#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))


////////Motor lifter 1////////
extern float kp_ML1, ki_ML1, kd_ML1;
extern float error_ML1, P_ML1, I_ML1, D_ML1, PID_value_ML1;
extern float previous_error_ML1, previous_I_ML1;
extern float REF_RPM_ML1  , REF_REV_ML1 ;
/////////////////////////////

////////Motor lifter 2////////
extern float kp_ML2, ki_ML2, kd_ML2;
extern float error_ML2, P_ML2, I_ML2, D_ML2, PID_value_ML2;
extern float previous_error_ML2, previous_I_ML2;
extern float REF_RPM_ML2  , REF_REV_ML2 ;
/////////////////////////////

////////Motor lifter 3////////
extern float kp_ML3, ki_ML3, kd_ML3;
extern float error_ML3, P_ML3, I_ML3, D_ML3, PID_value_ML3;
extern float previous_error_ML3, previous_I_ML3;
extern float REF_RPM_ML3  , REF_REV_ML3 ;
/////////////////////////////

////////Motor lifter 3////////
extern float kp_MServe, ki_MServe, kd_MServe;
extern float error_MServe, P_MServe, I_MServe, D_MServe, PID_value_MServe;
extern float previous_error_MServe, previous_I_MServe;
extern float REF_RPM_MServe  , REF_REV_MServe ;
/////////////////////////////

#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

void PID_ML1_RPM(int rpm_ref_ML1);
void PID_ML1_REV(int ref_ML1);
void PID_ML2_RPM(int rpm_ref_ML2);
void PID_ML2_REV(int ref_ML2);
void PID_ML3_RPM(int rpm_ref_ML3);
void PID_ML3_REV(int ref_ML3);
void PID_MServe_RPM(int rpm_ref_MServe);

#endif /* PID_H_ */
