#ifndef Gear_H
#define Gear_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
class Gear : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Servo* left_servo;
	Servo* right_servo;
public:
	Gear();
	void InitDefaultCommand();
	void SetServo(bool isOpen);
};

#endif  // Gear_H
