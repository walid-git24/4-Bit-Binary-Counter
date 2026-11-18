// ASL Challenge #03
// 4-Bit Binary Counter using AVR Port Manipulation

byte counter = 0;

void setup() {
  Serial.begin(9600);

  // PB0-PB3 (D8-D11) as OUTPUT
  // PB4 (D12) as INPUT
  DDRB = (DDRB & 0b11100000) | 0b00001111;

  // Enable internal pull-up on PB4
  PORTB = (PORTB & 0b11100000) | 0b00010000;
}

void loop() {

  // Read button state using PINB
  if (!(PINB & (1 << PB4))) {

    delay(50);

    if (!(PINB & (1 << PB4))) {

      counter = (counter + 1) & 0x0F;

      // Display binary value using one PORTB write
      PORTB = (PORTB & 0b11100000) | 0b00010000 | counter;

      // Print decimal and binary values
      Serial.print(counter);
      Serial.print(" = ");

      for (int bit = 3; bit >= 0; bit--) {
        Serial.print((counter >> bit) & 1);
      }

      Serial.println();

      // Wait for button release
      while (!(PINB & (1 << PB4))) {
      }

      delay(50);
    }
  }
}
