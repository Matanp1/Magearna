#include "CommandBase.h"

#include <Commands/Scheduler.h>

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
Chassis* CommandBase::chassis = NULL;
OI* CommandBase::oi= NULL;
Climb* CommandBase::climb = NULL;
Gear* CommandBase::gear = NULL;
CameraBase* CommandBase::cameraBase = NULL;

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {
}
