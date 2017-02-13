#include "Chassis.h"
#include "../RobotMap.h"
#include "../CommandBase.h"
#include "Commands/Chassis/DriveByJoystick.h"

#define SLOW_MUL 0.5

Chassis::Chassis() :
		Subsystem("Chassis") {
	this->gyro = new ADXRS450_Gyro(SPI::Port::kOnboardCS0);
	this->drive = new RobotDrive(new VictorSP(CHASSIS_LEFT_FRONT),
			new VictorSP(CHASSIS_LEFT_REAR), new VictorSP(CHASSIS_RIGHT_FRONT),
			new VictorSP(CHASSIS_RIGHT_REAR));
	this->gyro->Reset();
	this->drive->SetSafetyEnabled(false);
}

void Chassis::InitDefaultCommand() {
	SetDefaultCommand(new DriveByJoystick(CommandBase::oi->GetStick()));
}
void Chassis::Drive(float mag, float rot, bool squared) {
	this->drive->ArcadeDrive(mag, rot, squared);
}
void Chassis::Drive(Joystick* stick, bool squared) {
	float y = -stick->GetRawAxis(1);//*SLOW_MUL;
	float x = -stick->GetRawAxis(0);//*SLOW_MUL;
	if(y < .1 && y > -.1)
		y = 0;
	if(x < .1 && x > -.1)
		x = 0;
	this->drive->ArcadeDrive(y, x, squared);
}
void Chassis::ResetGyro()
{
	this->gyro->Reset();
}
int Chassis::GetGyroAngle()
{
	int angle = gyro->GetAngle();
	angle %= 360;
	if(angle < 0)
		angle += 360;
	return angle;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
