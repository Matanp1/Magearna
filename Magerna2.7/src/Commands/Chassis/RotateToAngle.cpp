#include "RotateToAngle.h"

RotateToAngle::RotateToAngle(int angle) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(chassis);
	desired_angle = angle;
}

// Called just before this Command runs the first time
void RotateToAngle::Initialize() {
	//CommandBase::chassis->SetSetpoint(frc::SmartDashboard::GetNumber("wanted_angle", 0));
	CommandBase::chassis->SetSetpoint(desired_angle);
	CommandBase::chassis->Enable();
}

// Called repeatedly when this Command is scheduled to run
void RotateToAngle::Execute() {
//	ommandBase::chassis->GetPIDController().get()
}

// Make this return true when this Command no longer needs to run execute()
bool RotateToAngle::IsFinished() {
	return (chassis->GetGyroAngle() >= desired_angle-2 && chassis->GetGyroAngle() <= desired_angle+2) &&
			(chassis->GetOutput() <= 0.1 && chassis->GetOutput() >= -0.1);
	//chassis->GetGyroAngle() >= desired_angle-1 && chassis->GetGyroAngle() <= desired_angle+1;
}

// Called once after isFinished returns true
void RotateToAngle::End() {
	CommandBase::chassis->Disable();
	chassis->Drive(0, 0, false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateToAngle::Interrupted() {

	End();
}
