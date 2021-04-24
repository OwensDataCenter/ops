const int buttonPin = A0;
const byte ANTENNA = 9;
int SW1 = 0;
int PULL1 = 0;
int PULL0 = 0;
int TEMP = 0;
int SW2 = 0;
// DIGITAL: PIN2=ALARM LIGHT (RED & BLUE) PIN3=PANEL SPEAKER PIN4=N/A PIN5=ALARM STROBE PIN6=ALARM HORN PIN7=N/A PIN8=N/A PIN9=AM BEACON 800KHZ PIN10=N/A PIN11=N/A PIN12=PANEL LED PIN13=BUILTIN_LED (SUPERVISORY)
//  ANALOG: PINA0=SW1 (5.0v) (PANEL STATION) PINA1=N/A PINA2=SW2 (3.3v) (PULL STATION) PINA3=N/A PINA4=N/A PINA5=STATUS LED
// https://www.arduino.cc/en/Tutorial/LibraryExamples/MasterWriter WIRE
void setup() {
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  tone(3, 1000);
  delay(2000);
  noTone(3);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(A5, OUTPUT);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(A5, LOW);
  delay(500);
  digitalWrite(12, HIGH);
  digitalWrite(A5, HIGH);
  delay(500);
  digitalWrite(12, LOW);
  digitalWrite(A5, LOW);
  delay(500);
  digitalWrite(12, HIGH);
  digitalWrite(A5, HIGH);
  delay(500);
  digitalWrite(12, LOW);
  digitalWrite(A5, LOW);
  delay(500);
  digitalWrite(12, HIGH);
  digitalWrite(A5, HIGH);
  delay(500);
  digitalWrite(12, LOW);
  digitalWrite(A5, LOW);
  delay(500);
  digitalWrite(12, HIGH);
  digitalWrite(A5, HIGH);
  delay(500);
  digitalWrite(12, LOW);
  digitalWrite(A5, LOW);
  delay(500);
  digitalWrite(12, HIGH);
  delay(2000);
  pinMode(5, OUTPUT);
  digitalWrite(12, LOW);
  digitalWrite(5, LOW);
  digitalWrite(A5, LOW);
  pinMode(buttonPin, INPUT);
  pinMode(A2, INPUT);
  pinMode(6, OUTPUT);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  TCCR1A = _BV (COM1A0);
  TCCR1B = _BV(WGM12) | _BV(CS10);
  OCR1A =  9;
}
void loop() {
  SW1 = analogRead(buttonPin);
  float PULL0 = SW1 * (5.0 / 1023.0);
  if (PULL0 <  5.00) {
    digitalWrite(A5, HIGH);
    digitalWrite(12, HIGH);
    pinMode (ANTENNA, OUTPUT);
    digitalWrite(2, HIGH);
    while (true) {
      digitalWrite(5, HIGH);
      delay(20);
      digitalWrite(5, LOW);
      noTone(6);
      tone(3, 1000);
      delay(500);
      noTone(3);
      tone(6, 500);
      delay(500);
    }
  } else {
    digitalWrite(12, LOW);
  }
  SW2 = analogRead(A2);
  float PULL1 = SW2 * (5.0 / 1023.0);
  if (PULL1 >= 3.30) {
    digitalWrite(A5, HIGH);
    digitalWrite(12, HIGH);
    pinMode (ANTENNA, OUTPUT);
    digitalWrite(2, HIGH);
    while (true) {
      digitalWrite(5, HIGH);
      delay(20);
      digitalWrite(5, LOW);
      noTone(6);
      tone(3, 1000);
      delay(500);
      noTone(3);
      tone(6, 500);
      delay(500);
    }
  } else {
    digitalWrite(12, LOW);
  }
}
