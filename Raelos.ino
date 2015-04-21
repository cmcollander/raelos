#include "Koshata.h"

Koshata kosh = Koshata();

int incomingByte = 0;
int greatestMag = 0;

int currX = 0;
int currY = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
	if(Serial.available() > 0) {
		incomingByte = Serial.read();
		if(incomingByte >= 'A' && incomingByte <= 'Z')
			currY = map(incomingByte,'A','Z',-100,100);
		if(incomingByte >= 'a' && incomingByte <='z')
			currX = map(incomingByte,'a','z',-100,100);
		
		moveKosh(currX,currY);
	}
}

// Expects numbers between -100 and 100
void moveKosh(int x, int y) {  
  int left  = constrain(x+y,-100,100);
  int right = constrain(y-x,-100,100);
  
  long dist = x*x;
  dist += y*y;
  dist = sqrt(dist);
  
  if(dist<15) {
	kosh.brake();
	return;
  }
  
  kosh.leftWheels(left);
  kosh.rightWheels(right);
}
