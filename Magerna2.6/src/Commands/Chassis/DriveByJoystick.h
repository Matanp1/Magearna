#ifndef DriveByJoystick_H
#define DriveByJoystick_H

#include "../../CommandBase.h"
#include "WPILib.h"

class DriveByJoystick: public CommandBase
{
private:
	Joystick* stick;

public:
	DriveByJoystick(Joystick* stick);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
