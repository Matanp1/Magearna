#include "MoveCamera.h"

#define SLOW_MUL 0.03

MoveCamera::MoveCamera() {
	// Use Requires() here to declare subsystem dependencies
	Requires(cameraBase);
	//CameraServer::GetInstance()->Add
}

// Called just before this Command runs the first time
void MoveCamera::Initialize() {
	cameraBase->SetStart();
}

// Called repeatedly when this Command is scheduled to run
void MoveCamera::Execute() {
	double x = oi->GetStick()->GetRawAxis(4);
	double y = oi->GetStick()->GetRawAxis(5);
	if(x < 0.1 && x > -0.1)
	{
		x = 0;
	}
	if(y < 0.1 && y > -0.1)
	{
		y = 0;
	}
	cameraBase->SetServo(x*SLOW_MUL, -y*SLOW_MUL);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveCamera::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MoveCamera::End() {
	cameraBase->SetServo(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveCamera::Interrupted() {
	End();
}
