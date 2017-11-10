#include "main.h"



void setGoalLift(int speed) {
	motorSet(goalLift, speed);
}

void setDrive(int leftSpeed, int rightSpeed) {
	int left = abs(leftSpeed) > 10 ? leftSpeed : 0;
	int right = abs(rightSpeed) > 10 ? rightSpeed : 0;

	motorSet(leftDrive1, left);
	motorSet(leftDrive2, left);
	motorSet(rightDrive1, right);
	motorSet(rightDrive2, -right);
}

void setLift(int speed) {
	motorSet(rightLift, -speed);
	motorSet(leftLift, speed);
}

void setClaw(int speed) {
	motorSet(claw, -speed);
}

void setRackGearLift(int speed) {
	motorSet(rackGears, speed);
}

void operatorControl() {
	while (1) {
		setDrive(joystickGetAnalog(1, 3), joystickGetAnalog(1, 2));

		if (joystickGetDigital(1, 6, JOY_UP)) {
			setLift(127);
		} else if (joystickGetDigital(1, 6, JOY_DOWN)) {
			setLift(-127);
		} else {
			setLift(0);
		}

		if (joystickGetDigital(1, 5, JOY_UP)) {
			setClaw(127);
		} else if (joystickGetDigital(1, 5, JOY_DOWN)) {
			setClaw(-127);
		} else {
			setClaw(10);
		}

		if (joystickGetDigital(1, 7, JOY_UP)) {
			setRackGearLift(127);
		} else if (joystickGetDigital(1, 7, JOY_DOWN)) {
			setRackGearLift(-127);
		} else {
			setRackGearLift(0);
		}

		if (joystickGetDigital(1, 8, JOY_UP)) {
			setGoalLift(127);
		} else if (joystickGetDigital(1, 8, JOY_DOWN)) {
			setGoalLift(-127);
		} else {
			setGoalLift(10);
		}

		delay(20);
	}
}
