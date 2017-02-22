#include "Chassis.h"

#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SmartDashboard.h>
#include "Commands/Chassis/DriveByJoystick.h"
#include "../RobotMap.h"
#include "../CommandBase.h" //P=0.005;I=0.0004;D=0.1
Chassis::Chassis() : PIDSubsystem("Chassis", 0.01, 0.0004, 0.001) {
	this->output = 1.0;
	this->gyro = new ADXRS450_Gyro(SPI::Port::kOnboardCS0);
	this->drive = new RobotDrive(new VictorSP(CHASSIS_LEFT_FRONT),
					new VictorSP(CHASSIS_LEFT_REAR), new VictorSP(CHASSIS_RIGHT_FRONT),
					new VictorSP(CHASSIS_RIGHT_REAR));
	this->irSensor = new AnalogInput(ODS_CHANNEL);
	this->reverse_mul = 1;
	this->gyro->Reset();
	this->drive->SetSafetyEnabled(false);
}

double Chassis::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	return this->gyro->GetAngle();
}

void Chassis::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	this->output = output;
	this->drive->ArcadeDrive(0, -output, false);
}

void Chassis::UpdatePID(double p, double i, double d)
{
	this->GetPIDController().get()->SetPID(p, i, d);
}
void Chassis::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveByJoystick(CommandBase::oi->GetStick()));
}
void Chassis::Drive(float mag,float rot,bool squared)
{
	this->drive->ArcadeDrive(mag * this->reverse_mul, rot, squared);
}
void Chassis::Drive(Joystick* stick,bool squared)
{
	float x = -stick->GetRawAxis(0);
	float y = -stick->GetRawAxis(1);
	y *= this->reverse_mul;
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
//	int angle = gyro->GetAngle();
//		angle %= 360;
//		if(angle < 0)
//			angle += 360;
		return gyro->GetAngle();
}
double Chassis::GetAnalogValue()
{
	return this->irSensor->GetVoltage();
}
void Chassis::ChangeMul()
{
	this->reverse_mul *= -1;
}
double Chassis::GetOutput()
{
	return this->output;
}
void Chassis::ResetOutput()
{
	this->output = 1;
}
