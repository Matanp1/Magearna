#include "CameraReset.h"

CameraReset::CameraReset() {
	// Use Requires() here to declare subsystem dependencies
	Requires(CommandBase::cameraBase);
	SetTimeout(1.0);
}

// Called just before this Command runs the first time
void CameraReset::Initialize() {
	cameraBase->SetStart();
}

// Called repeatedly when this Command is scheduled to run
void CameraReset::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool CameraReset::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void CameraReset::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CameraReset::Interrupted() {

}
