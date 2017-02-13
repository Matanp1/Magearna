#ifndef MoveCamera_H
#define MoveCamera_H

#include "../../CommandBase.h"

class MoveCamera : public CommandBase {
public:
	MoveCamera();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveCamera_H
