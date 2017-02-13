#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int LEFTMOTOR = 1;
// constexpr int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int RANGE_FINDER_PORT = 1;
// constexpr int RANGE_FINDER_MODULE = 1;

//PWM ports
#define HORIZONTAL_SERVO 0
#define VERTICAL_SERVO 1
#define GEARS_SERVO_LEFT 2
#define GEARS_SERVO_RIGHT 3
//4
#define CHASSIS_LEFT_FRONT 5
#define CHASSIS_LEFT_REAR 6
#define CHASSIS_RIGHT_FRONT 7
#define CHASSIS_RIGHT_REAR 8
#define VICTORSP_CLIMB 9

//Joystick ports
#define JOYSTICK_CHANNEL 0

//Joystick buttons ports
#define BTN_A 0
#define BTN_B 1
#define BTN_X 2
#define BTN_Y 3
#define BTN_L 4
#define BTN_R 5
#define BTN_SELECT 6
#define BTN_START 7
#define BTN_L_STICK 8
#define BTN_R_STICK 9

#endif  // ROBOTMAP_H
