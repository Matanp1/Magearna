#ifndef GearsOpen_H
#define GearsOpen_H

#include "../../CommandBase.h"

class GearsOpen : public CommandBase {
public:
	GearsOpen();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GearsOpen_H
