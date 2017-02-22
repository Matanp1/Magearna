#include "ClimbUp.h"

#define MIN_RANGE 0.5
#define TIME_SINCE_REACHED 2

ClimbUp::ClimbUp()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(climb);
}

// Called just before this Command runs the first time
void ClimbUp::Initialize()
{
	climb->SetPower(0);
}

// Called repeatedly when this Command is scheduled to run
void ClimbUp::Execute()
{
	climb->SetPower(-.75);
}

// Make this return true when this Command no longer needs to run execute()
bool ClimbUp::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ClimbUp::End()
{
	climb->SetPower(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClimbUp::Interrupted()
{
	End();
}
