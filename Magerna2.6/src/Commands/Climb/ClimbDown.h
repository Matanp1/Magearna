#ifndef ClimbDown_H
#define ClimbDown_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ClimbDown: public CommandBase
{
public:
	ClimbDown();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
