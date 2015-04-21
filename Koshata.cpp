#include "Arduino.h"
#include "Koshata.h"

Koshata::Koshata()
{
	pinMode(FL_DIR, OUTPUT);
	pinMode(FR_DIR, OUTPUT);
	pinMode(BL_DIR, OUTPUT);
	pinMode(BR_DIR, OUTPUT);
	
	pinMode(FL_PWM, OUTPUT);
	pinMode(FR_PWM, OUTPUT);
	pinMode(BL_PWM, OUTPUT);
	pinMode(BR_PWM, OUTPUT);
	
	goForward();
	brake();
}

void Koshata::leftWheels(int val) {
	digitalWrite(FL_DIR, val<0?FL_BWD:FL_FWD);
	digitalWrite(BL_DIR, val<0?BL_BWD:BL_FWD);
	
	val=val<0?-val:val; // Absolute Value
	
	analogWrite(FL_PWM, val*(MAX_FL_SPD/100.0));
	analogWrite(BL_PWM, val*(MAX_BL_SPD/100.0));
}

void Koshata::rightWheels(int val) {
	digitalWrite(FR_DIR, val<0?FR_BWD:FR_FWD);
	digitalWrite(BR_DIR, val<0?BR_BWD:BR_FWD);
	
	val=val<0?-val:val; // Absolute Value
	
	analogWrite(FR_PWM, val*(MAX_FR_SPD/100.0));
	analogWrite(BR_PWM, val*(MAX_BR_SPD/100.0));
}


void Koshata::goForward(int val) {
	digitalWrite(FL_DIR, FL_FWD);
	digitalWrite(FR_DIR, FR_FWD);
	digitalWrite(BL_DIR, BL_FWD);
	digitalWrite(BR_DIR, BR_FWD);
	
	analogWrite(FL_PWM, val*(MAX_FL_SPD/100.0));
	analogWrite(FR_PWM, val*(MAX_FR_SPD/100.0));
	analogWrite(BL_PWM, val*(MAX_BL_SPD/100.0));
	analogWrite(BR_PWM, val*(MAX_BR_SPD/100.0));
}

void Koshata::goForward() {
	goForward(MAX_PWM);
}

void Koshata::goBackward(int val) {
	digitalWrite(FL_DIR, FL_BWD);
	digitalWrite(FR_DIR, FR_BWD);
	digitalWrite(BL_DIR, BL_BWD);
	digitalWrite(BR_DIR, BR_BWD);
	
	analogWrite(FL_PWM, val*(MAX_FL_SPD/100.0));
	analogWrite(FR_PWM, val*(MAX_FR_SPD/100.0));
	analogWrite(BL_PWM, val*(MAX_BL_SPD/100.0));
	analogWrite(BR_PWM, val*(MAX_BR_SPD/100.0));
}

void Koshata::goBackward() {
	goBackward(MAX_PWM);
}

void Koshata::turnLeft(int val) {
	digitalWrite(FL_DIR, FL_BWD);
	digitalWrite(FR_DIR, FR_FWD);
	digitalWrite(BL_DIR, BL_BWD);
	digitalWrite(BR_DIR, BR_FWD);
	
	analogWrite(FL_PWM, val*(MAX_FL_SPD/100.0));
	analogWrite(FR_PWM, val*(MAX_FR_SPD/100.0));
	analogWrite(BL_PWM, val*(MAX_BL_SPD/100.0));
	analogWrite(BR_PWM, val*(MAX_BR_SPD/100.0));
}

void Koshata::turnLeft() {
	turnLeft(MAX_PWM);
}

void Koshata::turnRight(int val) {
	digitalWrite(FL_DIR, FL_FWD);
	digitalWrite(FR_DIR, FR_BWD);
	digitalWrite(BL_DIR, BL_FWD);
	digitalWrite(BR_DIR, BR_BWD);
	
	analogWrite(FL_PWM, val*(MAX_FL_SPD/100.0));
	analogWrite(FR_PWM, val*(MAX_FR_SPD/100.0));
	analogWrite(BL_PWM, val*(MAX_BL_SPD/100.0));
	analogWrite(BR_PWM, val*(MAX_BR_SPD/100.0));
}

void Koshata::turnRight() {
	turnRight(MAX_PWM);
}

void Koshata::brake() {
  analogWrite(FL_PWM, 0);
  analogWrite(FR_PWM, 0);
  analogWrite(BL_PWM, 0);
  analogWrite(BR_PWM, 0);
}
