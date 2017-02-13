#include "OI.h"
#include "RobotMap.h"
#include "Commands/Climb/ClimbUp.h"
#include "Commands/Climb/ClimbDown.h"
#include "Commands/Gear/GearsClose.h"
#include "Commands/Gear/GearsOpen.h"
#include "Commands/Chassis/TurnByAngle.h"

OI::OI() {
	this->stick = new Joystick(JOYSTICK_CHANNEL);
	for(int i = 0; i < 10; i++)
		this->buttons[i] = new JoystickButton(this->stick, i+1);
//	this->buttons[BTN_A]->WhileHeld(new ClimbDown());
//	this->buttons[BTN_Y]->WhileHeld(new ClimbUp());
//	this->buttons[BTN_L]->WhenPressed(new GearsOpen());
//	this->buttons[BTN_R]->WhenPressed(new GearsClose());

	this->buttons[BTN_A]->WhenPressed(new TurnByAngle(180));
	this->buttons[BTN_Y]->WhenPressed(new TurnByAngle(0));
	this->buttons[BTN_B]->WhenPressed(new TurnByAngle(90));
	this->buttons[BTN_X]->WhenPressed(new TurnByAngle(270));
	this->buttons[BTN_L]->WhileHeld(new ClimbDown());
	this->buttons[BTN_R]->WhileHeld(new ClimbUp());//*/

//	this->buttons[BTN_START]->WhenPressed(new TurnByAngle(0));
	//Scheduler::GetInstance()->AddCommand(new PutToDashBoard());
}
Joystick* OI::GetStick()
{
	return this->stick;
}
