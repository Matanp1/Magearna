#ifndef RotateToAngle_H
#define RotateToAngle_H

#include "../../CommandBase.h"
class RotateToAngle : public CommandBase {
private:
	double desired_angle;
public:
	RotateToAngle(int angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RotateToAngle_H
