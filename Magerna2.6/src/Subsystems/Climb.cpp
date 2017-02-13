#include "Climb.h"
#include "../RobotMap.h"
#include "WPILib.h"
Climb::Climb() :
		Subsystem("Climb")
{
	this->garry = new VictorSP(VICTORSP_CLIMB);
}
void Climb::SetPower(float power)
{
	this->garry->Set(power);
}

void Climb::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new PutToDashBoard());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
