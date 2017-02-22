
#include "Gear.h"
#include "../RobotMap.h"
#include "WPILib.h"

#define OPEN_POS 0
#define CLOSED_POS 1

Gear::Gear() : Subsystem("Gear") {
	left_servo = new Servo(GEARS_SERVO_LEFT);
	right_servo = new Servo(GEARS_SERVO_RIGHT);
}

void Gear::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void Gear::SetServo(bool isOpen)
{
	if(isOpen)
	{
		left_servo->Set(OPEN_POS);
		right_servo->Set(1-OPEN_POS);
	}
	else
	{
		left_servo->Set(CLOSED_POS);
		right_servo->Set(1-CLOSED_POS);
	}
}
