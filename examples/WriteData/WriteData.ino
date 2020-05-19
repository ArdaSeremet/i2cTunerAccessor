#include <Wire.h>
#include <i2cTunerAccessor.h>

#define TUNER_ADDRESS 0xD0
#define REGISTER_ADDRESS 0xAA // Change this to any register address.

i2cTunerAccessor tuner(TUNER_ADDRESS);

void setup() {
	tuner.begin();
	Serial.begin(9600);
}

void loop() {
	int dataToSend = 0xAE;
	tuner.writeToRegister(REGISTER_ADDRESS, dataToSend);

	delay(500);
}