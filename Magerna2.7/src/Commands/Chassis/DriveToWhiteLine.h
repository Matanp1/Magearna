#ifndef DriveToWhiteLine_H
#define DriveToWhiteLine_H

#include "../../CommandBase.h"

#define WHITE_MIN_VALUE 0.09
#define WHITE_MAX_VALUE 0.16

class DriveToWhiteLine : public CommandBase {
public:
	DriveToWhiteLine();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveToWhiteLine_H
