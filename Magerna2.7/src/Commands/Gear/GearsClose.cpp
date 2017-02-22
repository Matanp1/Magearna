#include "GearsClose.h"
#include "CommandBase.h"
GearsClose::GearsClose() {
	// Use Requires() here to declare subsystem dependencies
	Requires(gear);
	SetTimeout(1.0);
}

// Called just before this Command runs the first time
void GearsClose::Initialize() {
	gear->SetServo(false);
}

// Called repeatedly when this Command is scheduled to run
void GearsClose::Execute() {
	gear->SetServo(false);
}

// Make this return true when this Command no longer needs to run execute()
bool GearsClose::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void GearsClose::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GearsClose::Interrupted() {
	End();
}
