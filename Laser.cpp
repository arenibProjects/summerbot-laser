//---headers

#include "Laser.hpp"


//---functions

Laser::Laser(HardwareSerial &leftSerial, HardwareSerial &rightSerial) {
	
	leftSerial_ = leftSerial;
	rightSerial_ = rightSerial;
	
	leftSerial_.begin(115200);
	rightSerial_.begin(115200);
	
}

bool 
Laser::readLasers(int &leftLength, int &leftStrength, int &rightLength, int &rightStrength){

	// Data Format for Benewake TFmini
	// ===============================
	// 9 bytes total per message:
	// 1) 0x59
	// 2) 0x59
	// 3) Dist_L (low 8bit)
	// 4) Dist_H (high 8bit)
	// 5) Strength_L (low 8bit)
	// 6) Strength_H (high 8bit)
	// 7) Reserved bytes
	// 8) Original signal quality degree
	// 9) Checksum parity bit (low 8bit), Checksum = Byte1 + Byte2 +...+Byte8. This is only a low 8bit though

	//left laser
	while(leftSerial_.available() >= 9) { //9 bytes of data available
		//todo add a max wait time
		if((0x59 == leftSerial_.read()) && (0x59 == leftSerial_.read())) { //the two first are 0x59
			
			unsigned int t1 = leftSerial_.read(); //Dist_L
			unsigned int t2 = leftSerial_.read(); //Dist_H
			t2 <<= 8;
			t2 += t1;
			leftLength = t2;
			
			t1 = leftSerial_.read(); //Strength_L
			t2 = leftSerial_.read(); //Strength_H
			t2 <<= 8;
			t2 += t1;
			leftStrength = t2;
			
			for(int i=0; i<3; i++) {
				leftSerial_.read(); //bytes 7, 8, 9
			}
			
		}
		
	}
	
	while(rightSerial_.available() >= 9) { //9 bytes of data available
		//todo add a max wait time
		if((0x59 == rightSerial_.read()) && (0x59 == rightSerial_.read())) { //the two first are 0x59
			
			unsigned int t1 = rightSerial_.read(); //Dist_L
			unsigned int t2 = rightSerial_.read(); //Dist_H
			t2 <<= 8;
			t2 += t1;
			rightLength = t2;
			
			t1 = rightSerial_.read(); //Strength_L
			t2 = rightSerial_.read(); //Strength_H
			t2 <<= 8;
			t2 += t1;
			rightStrength = t2;
			
			for(int i=0; i<3; i++) {
				rightSerial_.read(); //bytes 7, 8, 9
			}
		
		}
		
	}

	return true;
}

bool 
Laser::recalibrate(double &xPos, double &yPos, double &angle) {
	
	
	return true;
}