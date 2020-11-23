#include "RobotArm_Control.h"

extern u16 RobotArm_1;
extern u16 RobotArm_2;
extern u16 RobotArm_3;
extern u16 RobotArm_4;


void RobotArm_Act(u16 A,u16 B,u16 C,u16 D)
{
	RobotArm_1=A;
	RobotArm_2=B;
	RobotArm_3=C;
	RobotArm_4=D;
	RobotArm_Enable();
}
