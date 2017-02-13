#ifndef Chassis_H
#define Chassis_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Chassis: public Subsystem
{
private:
	RobotDrive* drive;
	ADXRS450_Gyro* gyro;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Chassis();
	void InitDefaultCommand();
	void Drive(float mag,float rot,bool squared);
	void Drive(Joystick* stick,bool squared);
	void ResetGyro();
	int GetGyroAngle();
};

#endif
