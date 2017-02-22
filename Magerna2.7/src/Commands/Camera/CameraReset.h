#ifndef CameraReset_H
#define CameraReset_H

#include "../../CommandBase.h"

class CameraReset : public CommandBase {
public:
	CameraReset();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CameraReset_H
