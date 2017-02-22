#include "PassWhiteLine.h"

PassWhiteLine::PassWhiteLine() {
	// Use Requires() here to declare subsystem dependencies
	Requires(chassis);
}

// Called just before this Command runs the first time
void PassWhiteLine::Initialize() {
	chassis->Drive(0.0, 0.0, false);
}

// Called repeatedly when this Command is scheduled to run
void PassWhiteLine::Execute() {
	chassis->Drive(0.3, 0.0, false);
}

// Make this return true when this Command no longer needs to run execute()
bool PassWhiteLine::IsFinished() {
	return !(chassis->GetAnalogValue() <= WHITE_MAX_VALUE && chassis->GetAnalogValue() >= WHITE_MIN_VALUE);
}

// Called once after isFinished returns true
void PassWhiteLine::End() {
	chassis->Drive(0.0, 0.0, false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PassWhiteLine::Interrupted() {
	End();
}
