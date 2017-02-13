#ifndef Servo_H
#define Servo_H

#include <Commands/Subsystem.h>
#include "WPILib.h"

class CameraBase : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Servo* horizontal_servo;
	Servo* vertical_servo;
	//CameraServer* camera;
public:
	CameraBase();
	void InitDefaultCommand();
	void SetServo(double horizontal_value, double vertical_value);
	void SetStart();
	Servo* GetHorizontalServo();
	Servo* GetVerticalServo();
};

#endif  // Servo_H
