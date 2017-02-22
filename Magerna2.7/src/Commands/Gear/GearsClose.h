#ifndef GearsClose_H
#define GearsClose_H

#include "../../CommandBase.h"

class GearsClose : public CommandBase {
public:
	GearsClose();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GearsClose_H
