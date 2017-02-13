#ifndef Climb_H
#define Climb_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Climb: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	VictorSP* garry;
public:
	Climb();
	void SetPower(float power);
	void InitDefaultCommand();
};

#endif
