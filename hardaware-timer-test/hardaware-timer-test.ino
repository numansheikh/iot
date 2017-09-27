#define LED 13
boolean x=false;

ISR(TIMER1_OVF_vect) {
TCNT1=0x0BDC; // set initial value to remove time error (16bit counter register)
  x=!x; //toggle  
}

void setup() {
  pinMode(LED, OUTPUT);

  TIMSK1=0x01; // enabled global and timer overflow interrupt;
  TCCR1A = 0x00; // normal operation page 148 (mode0);
  TCNT1=0x0BDC; // set initial value to remove time error (16bit counter register)
  TCCR1B = 0x04; // start timer/ set clock
};

void loop () {
  digitalWrite(LED, x);
};
