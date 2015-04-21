#ifndef Koshata_h
#define Koshata_h

#include "Arduino.h"

#define FL_FWD 0
#define FL_BWD 1
#define FR_FWD 1
#define FR_BWD 0
#define BL_FWD 1
#define BL_BWD 0
#define BR_FWD 1
#define BR_BWD 0

#define FL_DIR 2
#define FR_DIR 7
#define BL_DIR 4
#define BR_DIR 8

#define FL_PWM 3
#define FR_PWM 6
#define BL_PWM 5
#define BR_PWM 9

#define MAX_PWM 255

#define MAX_FL_SPD 100
#define MAX_FR_SPD 90
#define MAX_BL_SPD 100
#define MAX_BR_SPD 90


class Koshata
{
  public:
    Koshata();
	void leftWheels(int);
	void rightWheels(int);
    void goForward(int);
	void goForward();
    void goBackward(int);
	void goBackward();
    void brake();
    void turnLeft(int);
	void turnLeft();
    void turnRight(int);
	void turnRight();
};

#endif
