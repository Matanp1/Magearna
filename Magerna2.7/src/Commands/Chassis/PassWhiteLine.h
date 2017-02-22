#ifndef PassWhiteLine_H
#define PassWhiteLine_H

#include "../../CommandBase.h"

#define WHITE_MIN_VALUE 0.09
#define WHITE_MAX_VALUE 0.15

class PassWhiteLine : public CommandBase {
public:
	PassWhiteLine();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // PassWhiteLine_H
