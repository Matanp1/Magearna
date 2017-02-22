#ifndef ChangeDriveMode_H
#define ChangeDriveMode_H

#include "Commands/InstantCommand.h"

class ChangeDriveMode : public InstantCommand {
public:
	ChangeDriveMode();
	void Initialize();
};

#endif  // ChangeDriveMode_H
