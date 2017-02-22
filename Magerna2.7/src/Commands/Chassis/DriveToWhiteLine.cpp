#include "DriveToWhiteLine.h"

DriveToWhiteLine::DriveToWhiteLine() {
	// Use Requires() here to declare subsystem dependencies
	Requires(chassis);
}

// Called just before this Command runs the first time
void DriveToWhiteLine::Initialize() {
	chassis->Drive(0.0, 0.0, false);
}

// Called repeatedly when this Command is scheduled to run
void DriveToWhiteLine::Execute() {
	chassis->Drive(0.4, -0.04, false);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveToWhiteLine::IsFinished() {
	return chassis->GetAnalogValue() <= WHITE_MAX_VALUE && chassis->GetAnalogValue() >= WHITE_MIN_VALUE;
}

// Called once after isFinished returns true
void DriveToWhiteLine::End() {
	chassis->Drive(0.0, 0.0, false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveToWhiteLine::Interrupted() {

}
