#ifndef Chassis_H
#define Chassis_H

#include <Commands/PIDSubsystem.h>
#include "WPILib.h"
class Chassis : public PIDSubsystem {
private:
	RobotDrive* drive;
	ADXRS450_Gyro* gyro;
	AnalogInput* irSensor;
	int reverse_mul;
	double output;
public:
	Chassis();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void UpdatePID(double p, double i, double d);
	void Drive(float mag,float rot,bool squared);
	void Drive(Joystick* stick,bool squared);
	void ResetGyro();
	int GetGyroAngle();
	double GetAnalogValue();
	void ChangeMul();
	double GetOutput();
	void ResetOutput();
};

#endif  // Chassis_H
