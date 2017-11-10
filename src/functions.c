#include "main.h"
#define sethisbad 0.06599526121

void armEncoderTracker(){
    encoderReset(armEncoder);
  int  armEncoderValue = encoderGet(armEncoder);
}


void arm(int armDegrees){

  if ((armEncoderValue + range) < armDegrees){
    motorSet(rightLift, 127);
    motorSet(leftLift, 127);
    }
    else if ((armEncoderValue - range) < armDegrees){
    motorSet(rightLift, 127);
    motorSet(leftLift, 127);
    }
    else if ((armEncoderValue + range) > armDegrees){
    motorSet(rightLift, -127);
    motorSet(leftLift, -127);
    }
    else if ((armEncoderValue - range) > armDegrees){
    motorSet(rightLift, -127);
    motorSet(leftLift, -127);
    }
    else{
    motorSet(rightLift, 0);
    motorSet(leftLift, 0);
    }

}



void drive(float distance_in){

  if ((sethisbad * encoderGet(rightDriveEncoder)) < distance_in){
  	motorSet(rightDrive1, 127);
  	motorSet(rightDrive2, -127);
  }
  else if ((sethisbad * encoderGet(rightDriveEncoder)) >= distance_in){
    	motorSet(rightDrive1, 0);
    	motorSet(rightDrive2, 0);
  }
  else if ((sethisbad * encoderGet(leftDriveEncoder)) < distance_in){
    motorSet(leftDrive1, 127);
  	motorSet(leftDrive2, 127);
  }
  else if ((sethisbad * encoderGet(leftDriveEncoder)) >= distance_in){
    motorSet(leftDrive1, 0);
  	motorSet(leftDrive2, 0);
  }

}
