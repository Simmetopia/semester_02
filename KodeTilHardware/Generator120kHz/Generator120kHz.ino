#define F_CPU 16000000
#include <avr\io.h>


void setup()								// burst setup Timer 1
{
	//------- FAST PWM SETUP --------//
	pinMode(11, OUTPUT);				
	TCCR1A |= (1 << WGM11)| (1 << COM1A0);																// fast PWM 14
	TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS10);												// fast PWM 14 - PS: 1 = 120301 Hz
	ICR1 = 132;																			// TOP 132.
	OCR1A = 66;																			// 50% DUTY-CYCLE

}

void burstOn()									//enable burst timer 1 120kHz
{	
	TCCR1A = (1 << COM1A0);						// OCR1A on - resten er det samme.
}


void loop()
{

}

/*

void interuptTimer()						// interupt på timer 2
{

}

// Vi manlger at lave interrupt på 1ms for vores burst.

*/












//
//uint8_t burstPin = 4;
//
//
//
//
//void setup()
//{
//	//TCCR1A = 0b00000011;
//	//TCCR1B = 0b00000001;			// prescaler 1,
//
//	pinMode(burstPin, OUTPUT);
//}
////
//void setup() 
//{
//	pinMode(2, OUTPUT); // D2 as output pin
//}
//void loop() 
//{
//
//		PORTD = PORTD | B00000100; // D2 high
//		PORTD = PORTD & B11111011; // D2 low
//
//}
//	//for (int i = 0; i < 125; i++)			//laver 120khz burst for hver Zero-cross
//	//{
//	//	digitalWrite(burstPin, HIGH);
//	//	//_delay_us(2);
//	//	digitalWrite(burstPin, LOW);
//	//	//_delay_us(2);
//	//}

//const int ocr1aPin = 11;
//
//// Set the frequency that we will get on pin OCR1A
//void setFrequency(uint32_t freq)
//{
//	uint32_t requiredDivisor = (F_CPU / 2) / (uint32_t)freq;
//	uint16_t prescalerVal;
//	uint8_t prescalerBits;
//	if (requiredDivisor < 65536UL)
//	{
//		prescalerVal = 1;
//		prescalerBits = 1;
//	}
//	else if (requiredDivisor < 8 * 65536UL)
//	{
//		prescalerVal = 8;
//		prescalerBits = 2;
//	}
//	else if (requiredDivisor < 64 * 65536UL)
//	{
//		prescalerVal = 64;
//		prescalerBits = 3;
//	}
//	else if (requiredDivisor < 256 * 65536UL)
//	{
//		prescalerVal = 256;
//		prescalerBits = 4;
//	}
//	else
//	{
//		prescalerVal = 1024;
//		prescalerBits = 5;
//	}
//
//	uint16_t top = ((requiredDivisor + (prescalerVal / 2)) / prescalerVal) - 1;
//	TCCR1A = 0;
//	TCCR1B = (1 << WGM12) | prescalerBits;
//	TCCR1C = 0;
//	OCR1A = (top & 0xFF);
//}
//
//// Turn the frequency on
//void on()
//{
//	TCNT1H = 0;
//	TCNT1L = 0;
//	TCCR1A |= (1 << COM1A0);
//}
//
//// Turn the frequency off and turn of the IR LED
//void off()
//{
//	TCCR1A &= ~(1 << COM1A0);
//}
//
//void setup()
//{
//	digitalWrite(ocr1aPin, LOW);
//	pinMode(ocr1aPin, OUTPUT);
//}
