#ifndef TurnByAngle_H
#define TurnByAngle_H

#include "../../CommandBase.h"
#include "WPILib.h"

class TurnByAngle: public CommandBase
{
private:
	int angle;
	int sub;
	bool isClockwise;
public:
	TurnByAngle(int angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
