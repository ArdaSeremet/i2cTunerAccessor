#include "i2cTunerAccessor.h"
#include "Arduino.h"

i2cTunerAccessor::i2cTunerAccessor(uint8_t tunerAddress, TwoWire *wireInst)
{
	_tunerAddress = tunerAddress; // Set tuner address to a private variable.
	_wire = wireInst;
}

void i2cTunerAccessor::begin()
{
	_wire->begin(); // Start the I2C interface.
}

void i2cTunerAccessor::writeToRegister(uint8_t registerAddress, uint8_t data)
{
	_wire->beginTransmission(_tunerAddress); // Start the communication with tuner in write mode.
	_wire->write(registerAddress);			 // Specify the address of register to write data.
	_wire->write(data);						 // The data packet to write in specified register.
	_wire->endTransmission();				 // End the communication by transmitting data packets to slave.
}

uint8_t i2cTunerAccessor::readFromRegister(uint8_t registerAddress)
{
	_wire->beginTransmission(_tunerAddress); // Start the communication with tuner in write mode.
	_wire->write(registerAddress);			 // Specify the adress of register to read data.
	_wire->endTransmission();				 // End the communication by transmitting data packets to slave.

	_wire->requestFrom(_tunerAddress, 1); // Request 1 byte of data from slave.
	uint8_t dataPacket = _wire->read();	  // Read 1 byte of data from slave.

	return dataPacket; // Return the read byte.
}