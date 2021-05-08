#include <Wire.h>
#include <i2cTunerAccessor.h>

#define TUNER_ADDRESS 0xD0
#define REGISTER_ADDRESS 0xAA // Change this to any register address.

i2cTunerAccessor tuner(TUNER_ADDRESS);

void setup()
{
	tuner.begin();
	Serial.begin(9600);
}

void loop()
{
	uint8_t registerValue;
	registerValue = tuner.readFromRegister(REGISTER_ADDRESS);

	Serial.print('Data in register 0x');
	Serial.print(REGISTER_ADDRESS, HEX);
	Serial.print(' is ');
	Serial.println(registerValue, HEX);

	delay(500);
}