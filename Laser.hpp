#ifndef LASER_HPP
#define LASER_HPP 1

#include "arduino.h"


//---Laser class

class Laser {

public :

	//constructor
	Laser(HardwareSerial leftSerial, HardwareSerial rightSerial);
	
	bool
	recalibrate(double &xPos, double &yPos, double &angle);
	
	bool
	readLasers(uint16_t &leftLength, int &leftStrength, int &rightLength, int &rightStrength);
	
private :
	
	HardwareSerial leftSerial_, rightSerial_;

};


#endif