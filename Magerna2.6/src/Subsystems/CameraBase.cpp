#include <Subsystems/CameraBase.h>
#include "../RobotMap.h"
#include "Commands/Camera/MoveCamera.h"

CameraBase::CameraBase() : Subsystem("CameraBase") {
	this->horizontal_servo = new Servo(HORIZONTAL_SERVO);
	this->vertical_servo = new Servo(VERTICAL_SERVO);
	//this->camera = new CameraServer(0);
	//this->camera->StartAutomaticCapture(5);
}

void CameraBase::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new MoveCamera());
}
void CameraBase::SetServo(double horizontal_value, double vertical_value)
{
	double horizontal = this->horizontal_servo->Get()+horizontal_value;
	double vertical = this->vertical_servo->Get()+vertical_value;
	if (horizontal > 1)
		horizontal = 1;
	if (horizontal < -1)
		horizontal = -1;
	if (vertical > 1)
		vertical = 1;
	if (vertical < -1)
		vertical = -1;
	this->horizontal_servo->Set(horizontal);
	this->vertical_servo->Set(vertical);
}
Servo* CameraBase::GetHorizontalServo()
{
	return this->horizontal_servo;
}
Servo* CameraBase::GetVerticalServo()
{
	return this->vertical_servo;
}
void CameraBase::SetStart()
{
	this->horizontal_servo->Set(0.5);
	this->vertical_servo->Set(0.25);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
