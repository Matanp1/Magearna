#include "GearsOpen.h"
#include "CommandBase.h"
GearsOpen::GearsOpen() {
	// Use Requires() here to declare subsystem dependencies
	Requires(gear);
	SetTimeout(3);
}

// Called just before this Command runs the first time
void GearsOpen::Initialize() {
	gear->SetServo(false);
}

// Called repeatedly when this Command is scheduled to run
void GearsOpen::Execute() {
	gear->SetServo(true);
}

// Make this return true when this Command no longer needs to run execute()
bool GearsOpen::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void GearsOpen::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GearsOpen::Interrupted() {
	End();
}
