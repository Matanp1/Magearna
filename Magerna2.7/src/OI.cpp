#include "OI.h"
#include "RobotMap.h"
#include "Commands/Climb/ClimbUp.h"
#include "Commands/Climb/ClimbDown.h"
#include "Commands/Gear/GearsClose.h"
#include "Commands/Gear/GearsOpen.h"
#include "Commands/Camera/CameraReset.h"
#include "Commands/Chassis/ChangeDriveMode.h"
#include "Commands/Chassis/RotateToAngle.h"
OI::OI() {
	this->stick = new Joystick(JOYSTICK_CHANNEL);
	for(int i = 0; i < 10; i++)
		this->buttons[i] = new JoystickButton(this->stick, i+1);
	//this->buttons[BTN_A]->WhileHeld(new ClimbDown());
	this->buttons[BTN_Y]->WhileHeld(new ClimbUp());
	this->buttons[BTN_L]->WhenPressed(new GearsOpen());
	this->buttons[BTN_R]->WhenPressed(new GearsClose());
	this->buttons[BTN_R_STICK]->WhenPressed(new CameraReset());
	this->buttons[BTN_START]->WhenPressed(new ChangeDriveMode());
	this->buttons[BTN_SELECT]->WhenPressed(new RotateToAngle(60));
//	this->buttons[BTN_START]->WhenPressed(new TurnByAngle(0));
	//Scheduler::GetInstance()->AddCommand(new PutToDashBoard());
}
Joystick* OI::GetStick()
{
	return this->stick;
}
