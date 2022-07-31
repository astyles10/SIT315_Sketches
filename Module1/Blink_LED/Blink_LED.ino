void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  noInterrupts();
  // TCCRx - Timer/Counter Control Register. Prescaler configured here
  TCCR1A = 0;
  TCCR1B = 0;

  // Timer/Counter Register. Actual timer value stored here
  TCNT1 = 0;

  // Clock frequency = 16,000,000 Hz
  // 0.25Hz = (16,000,000 / ((62499 + 1) * 1024))
  // Output Compare Register
  OCR1A = 15625;

  
  TCCR1B |= (1 << CS12) | (1 << CS10);

  TIMSK1 |= (1 << OCIE1A);
  TCCR1B |= (1 << WGM12);

  interrupts();
}

void loop() {
//  digitalWrite(LED_BUILTIN, HIGH);
//  delay(500);
//  digitalWrite(LED_BUILTIN, LOW);
//  delay(500);  
}

ISR(TIMER1_COMPA_vect) {
  digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ 1);
}
