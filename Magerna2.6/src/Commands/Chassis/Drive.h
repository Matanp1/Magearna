#ifndef Drive_H
#define Drive_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Drive: public CommandBase
{
private:
	float mag;
	float rot;
	bool squared;
public:
	Drive(float mag, float rot, bool squared);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
