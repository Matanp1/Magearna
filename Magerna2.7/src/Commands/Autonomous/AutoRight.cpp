#include "AutoRight.h"

#include "Commands/Chassis/Drive.h"
#include "Commands/Chassis/RotateToAngle.h"
#include "Commands/Gear/GearsClose.h"
#include "Commands/Gear/GearsOpen.h"
#include "Commands/Chassis/DriveToWhiteLine.h"

AutoRight::AutoRight() {
	//Drive to the baseline
		AddSequential(new DriveToWhiteLine());

		//Rotate to the angle of the shaft
		AddSequential(new RotateToAngle(-65));

		//Drive to the shaft and then return back
		AddSequential(new Drive(0.3, 0.0, false), 3);
		AddSequential(new GearsOpen());
		AddSequential(new Drive(-.3, 0.0, false), 3.0);
		AddSequential(new GearsClose());
}
