#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>

#include <Commands/Command.h>

#include "OI.h"
#include "Subsystems/Chassis.h"
#include "Subsystems/Climb.h"
#include "Subsystems/Gear.h"
#include "Subsystems/CameraBase.h"
/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use
 * CommandBase::exampleSubsystem
 */
class CommandBase: public frc::Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;

	// Create a single static instance of all of your subsystems
	static Chassis* chassis;
	static Climb* climb;
	static OI* oi;
	static Gear* gear;
	static CameraBase* cameraBase;
};

#endif  // COMMAND_BASE_H
