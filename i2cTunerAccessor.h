#ifndef i2cTunerAccessor_h
#define i2cTunerAccessor_h

#include <inttypes.h>
#include "Arduino.h"
#include <Wire.h>

class i2cTunerAccessor
{
public:
	i2cTunerAccessor(uint8_t tunerAddress, TwoWire *wireInst = &Wire);
	void begin();
	void writeToRegister(uint8_t registerAddress, uint8_t data);
	uint8_t readFromRegister(uint8_t registerAddress);

private:
	TwoWire *_wire;
	uint8_t _tunerAddress;
}

#endif