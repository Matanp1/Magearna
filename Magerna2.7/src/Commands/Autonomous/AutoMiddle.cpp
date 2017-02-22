#include "AutoMiddle.h"

#include "Commands/Chassis/Drive.h"
#include "Commands/Chassis/PassWhiteLine.h"
#include "Commands/Chassis/DriveToWhiteLine.h"
#include "Commands/Gear/GearsClose.h"
#include "Commands/Gear/GearsOpen.h"
AutoMiddle::AutoMiddle() {

	//Pass the white line
	AddSequential(new DriveToWhiteLine());


	//Drive to the shaft and then return back
	//AddSequential(new Drive(0.3, 0.0, false), 1.0);
	AddSequential(new GearsOpen());
	AddSequential(new Drive(-.3, 0.0, false), 1.0);
	AddSequential(new GearsClose());
}
