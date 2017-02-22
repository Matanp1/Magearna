#include "ChangeDriveMode.h"
#include "CommandBase.h"
ChangeDriveMode::ChangeDriveMode() {
	// Use Requires() here to declare subsystem dependencies
}

// Called once when the command executes
void ChangeDriveMode::Initialize() {
	CommandBase::chassis->ChangeMul();
}
