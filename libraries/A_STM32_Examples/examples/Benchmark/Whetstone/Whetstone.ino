/*
 * This is the same whetstone code with adjustments for the Serial.print function on the Arduino
 * The main loop within the procedure whetstone() is identical. Only the output format is Arduino-specific.
 */

#include "whetstone.h"

void setup() {

	// Initializations
	pinMode(LED_BUILTIN, OUTPUT);

	Serial.begin();
	delay(3000); // wait a while for host to connect
}

void loop() {
	int fcpu = 0;

	digitalWrite(LED_BUILTIN, LOW); // led is active low
	Serial.println("press 'g' to start");
	// wait for a key g
	while (1) {
		byte c;
		if (Serial.available())
			c = Serial.read();
		if (c == 'g') {
			break;
		}
		delay(100);
	}

	digitalWrite(LED_BUILTIN, HIGH); // led is active low

#ifdef F_CPU
	fcpu = F_CPU / 1000000;
#endif

	whetstone(fcpu);
}

void blinks() {
	for (int i = 0; i < 5; i++) {
		digitalWrite(LED_BUILTIN, HIGH);
		delay(100);
		digitalWrite(LED_BUILTIN, LOW);
		delay(100);
	}
}
