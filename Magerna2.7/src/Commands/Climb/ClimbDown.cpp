#include "ClimbDown.h"

ClimbDown::ClimbDown()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(climb);
}

// Called just before this Command runs the first time
void ClimbDown::Initialize()
{
	climb->SetPower(0);
}

// Called repeatedly when this Command is scheduled to run
void ClimbDown::Execute()
{
	climb->SetPower(.75);
}

// Make this return true when this Command no longer needs to run execute()
bool ClimbDown::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ClimbDown::End()
{
	climb->SetPower(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClimbDown::Interrupted()
{
	End();
}
