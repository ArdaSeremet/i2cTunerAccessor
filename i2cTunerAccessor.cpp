#include "i2cTunerAccessor.h"
#include "Arduino.h"
#include "Wire.h"

i2cTunerAccessor::i2cTunerAccessor(int tunerAddress) {
	_tunerAddress = tunerAddress; // Set tuner address to a private variable.
}

void i2cTunerAccessor::begin() {
	Wire.begin(); // Start the I2C interface.
}

void i2cTunerAccessor::writeToRegister(int registerAddress, int data) {
	Wire.beginTransmission(_tunerAddress); // Start the communication with tuner in write mode.
	Wire.write(registerAddress); // Specify the address of register to write data.
	Wire.write(data); // The data packet to write in specified register.
	Wire.endTransmission(); // End the communication by transmitting data packets to slave.
}

int i2cTunerAccessor::readFromRegister(int registerAddress) {
	Wire.beginTransmission(_tunerAddress); // Start the communication with tuner in write mode.
	Wire.write(registerAddress); // Specify the adress of register to read data.
	Wire.endTransmission(); // End the communication by transmitting data packets to slave.

	Wire.requestFrom(_tunerAddress, 1); // Request 1 byte of data from slave.
	if(Wire.available() > 0) { // If more than 0 byte is available to read...
		int dataPacket = Wire.read(); // Read 1 byte of data from slave. 
	}

	return dataPacket; // Return the read byte.
}