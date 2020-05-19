#ifndef i2cTunerAccessor_h
#define i2cTunerAccessor_h

#include <inttypes.h>
#include "Arduino.h"

class i2cTunerAccessor {
	public:
		i2cTunerAccessor(int writeAddress, int readAddress);
		void begin();
		void writeToRegister(int registerAddress, int data);
		int readFromRegister(int registerAddress);
	private:
		uint8_t _tunerAddress;
}

#endif