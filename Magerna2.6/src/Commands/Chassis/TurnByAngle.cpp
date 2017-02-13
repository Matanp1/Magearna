#include "TurnByAngle.h"
#define RANGE 5

TurnByAngle::TurnByAngle(int angle)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(chassis);
	this->angle = angle;
	this->sub = this->angle - chassis->GetGyroAngle();
	if ((sub < -180) || (sub>0 && sub<180))
		this->isClockwise = true;
	else
		this->isClockwise = false;
}

// Called just before this Command runs the first time
void TurnByAngle::Initialize()
{
	chassis->Drive(0,0,false);
}

// Called repeatedly when this Command is scheduled to run
void TurnByAngle::Execute()
{
	double speed = sqrt(abs(sub)/360.0);
//	double speed = 0.15;
	frc::SmartDashboard::PutNumber("Chassis speed:", speed);
	if (isClockwise)
		chassis->Drive(0, speed, false);//+clockwise
	else
		chassis->Drive(0, -speed, false);//-

}

// Make this return true when this Command no longer needs to run execute()
bool TurnByAngle::IsFinished()
{
//	if (angle == 0)
//		return chassis->GetGyroAngle() >= 360-RANGE || chassis->GetGyroAngle() <= RANGE || chassis->GetGyroAngle() == 0;
	return (chassis->GetGyroAngle() >= this->angle-RANGE && chassis->GetGyroAngle() <= this->angle+RANGE);
}

// Called once after isFinished returns true
void TurnByAngle::End()
{
	chassis->Drive(0,0,false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnByAngle::Interrupted()
{
	End();
}
