#include "Drive.h"
Drive::Drive(float mag, float rot, bool squared)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(chassis);
	this->mag = mag;
	this->rot = rot;
	this->squared = squared;
}

// Called just before this Command runs the first time
void Drive::Initialize()
{
	chassis->Drive(0.0, 0.0, false);
}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute()
{
	chassis->Drive(this->mag, this->rot, this->squared);
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Drive::End()
{
	chassis->Drive(0.0, 0.0, false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted()
{
	End();
}
