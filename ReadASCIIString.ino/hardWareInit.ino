
/******************************************/
/* Function implementation for Interrupt */
/******************************************/
void initHardware(){
  pinMode(ZeroCrossIn, INPUT);
  //------- FAST PWM SETUP --------//
  pinMode(11, OUTPUT);                    // PIN 11 OUTPUT BURST 
  TCCR1A = 0; //default
  TCCR1B = 0; //default
  TCCR1A = (1 << WGM11);                                // fast PWM 14
  TCCR1B = (1 << WGM12) | (1 << WGM13) | (1<< CS10);                        // fast PWM 14 - PS: 1 = 120301 Hz
  ICR1 = 132/2;                                     // TOP 132.
  OCR1A = 66/2 ;                                     // 50% DUTY-CYCLE

  /* INT2 INITIALIZING */
 EICRA &= ~(bit(ISC20) | bit (ISC21));  // clear existing flags
 EICRA |= (1 << ISC20) ;                // Any-edge int
 EIFR =  (1 << INTF2);                  // Int-flag sat.
 EIMSK |= (1 << INT2);                  //INT2 enable
}
void initTimer3Interrupt()
{
  // initialize timer3 
  noInterrupts();                          // disable all interrupts
  TCCR3A = 0;
  TCCR3B = 0;
  TCNT3 = 0;

  OCR3A = 125;                              // compare match 1000hz / 1ms
  TCCR3B |= (1 << WGM32);                   // CTC mode
  TCCR3B |= (1 << CS30) | (1 << CS31);       // 64 prescaler 
  TIMSK3 |= (1 << OCIE3A);                  // enable timer compare interrupt
  interrupts();                             // enable all interrupts
}
/****************************************************/
/****************************************************/

void burstOn()                  //enable burst timer 1 120kHz
{
  TCNT1L = 0;                         //added reset på low
  TCNT1H = 0;                         //added reset på high
  TCCR1A |= (1 << COM1A0);            // OCR1A on - resten er det samme.
}

void burstOff()                 //disable burst timer 1 120kHz
{
  TCCR1A &= (0 << COM1A0);            // OCR1A off - resten er det samme.
}


