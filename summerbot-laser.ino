#include "Laser.hpp"
#include <String>

Laser *laser;
uint16_t leftLength;
int leftStrength;
int rightLength;
int rightStrength;

void setup() {
	
	Serial.begin(9600);
	delay(1000);
	
	laser = new Laser(Serial3, Serial4);
		
}

void loop() {
	
	laser->readLasers(leftLength, leftStrength, rightLength, rightStrength);
	String length = "leftLenght : ";
	String strength = "leftStrength : ";
	Serial.print(length);
	Serial.println(leftLength);
	Serial.print(strength);
	Serial.println(leftStrength);
	delay(1000);
	
}