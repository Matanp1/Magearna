#include "DriveByJoystick.h"
#include "../../RobotMap.h"

DriveByJoystick::DriveByJoystick(Joystick* stick)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(chassis);
	this->stick = stick;
}

// Called just before this Command runs the first time
void DriveByJoystick::Initialize()
{
	chassis->Drive(.0, .0, false);
}

// Called repeatedly when this Command is scheduled to run
void DriveByJoystick::Execute()
{
	int poValue = stick->GetPOV();
	if(poValue != -1)
	{
		if(poValue == 0)
			chassis->Drive(.3, 0.0, false);
		else if(poValue == 90)
			chassis->Drive(0.0, -.2, false);
		else if(poValue == 180)
			chassis->Drive(-.3, 0.0, false);
		else if(poValue == 270)
			chassis->Drive(0.0, .2, false);
	}
	else
		chassis->Drive(this->stick, !this->stick->GetRawButton(BTN_L_STICK + 1));
}

// Make this return true when this Command no longer needs to run execute()
bool DriveByJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveByJoystick::End()
{
	chassis->Drive(0.0, 0.0, false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveByJoystick::Interrupted()
{
	End();
}
