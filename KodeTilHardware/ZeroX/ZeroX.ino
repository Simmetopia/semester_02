//Zero Cross Test
//------------------------------------------
//unsigned int of 8 bits. == 1 byte
//Arduino Pin 2 + GND
#define F_CPU 16000000
#include <avr\io.h>
#include<avr\delay.h>
uint8_t zeroPin = 0;								// pin 0 er zeroX pin der opfanger hvert ZeroX




void setup()
{
	pinMode(zeroPin, INPUT);

	//------- FAST PWM SETUP --------//
	pinMode(11, OUTPUT);										// PIN 11 OUTPUT BURST 
	TCCR1A = (1 << WGM11);																// fast PWM 14
	TCCR1B = (1 << WGM12) | (1 << WGM13) | (1<< CS10);												// fast PWM 14 - PS: 1 = 120301 Hz
	ICR1 = 132;																			// TOP 132.
	OCR1A = 66;																			// 50% DUTY-CYCLE

} 

void burstOn()									//enable burst timer 1 120kHz
{
	TCCR1A = (1 << COM1A0);						// OCR1A on - resten er det samme.
}
void burstOff()									//disable burst timer 1 120kHz
{
	TCCR1A = (0 << COM1A0);						// OCR1A off - resten er det samme.
}


void loop()
{
	while (digitalRead(zeroPin) == 1)
	{
		Serial.println("No Zero Cross!!");
	}
	while (digitalRead(zeroPin) == 0)
	{
		Serial.println("Zero Cross!");
		burstOn();
		_delay_ms(1);
		burstOff();
	}
}





