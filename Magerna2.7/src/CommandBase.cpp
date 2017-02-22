#include "CommandBase.h"

#include <Commands/Scheduler.h>

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
OI* CommandBase::oi= NULL;
Chassis* CommandBase::chassis = NULL;
Climb* CommandBase::climb = NULL;
Gear* CommandBase::gear = NULL;
CameraBase* CommandBase::cameraBase = NULL;

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {
}
void CommandBase::Init()
{
	chassis = new Chassis();
	climb = new Climb();
	gear = new Gear();
	cameraBase = new CameraBase();
	oi = new OI();
}
