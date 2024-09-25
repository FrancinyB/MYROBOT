#define Sensor A0
#define Led 3
const byte interruptPin = 2;
volatile byte state = LOW;

void setup() {
  pinMode(Sensor, INPUT);
  pinMode(Led, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
  randomSeed(analogRead(A0));
  Serial.begin(9600);
}

void Interrupt(){
  Serial.println(map(analogRead(Sensor), 0, 1023, 0, 255));
  delay(1000);
}
void loop() {
  digitalWrite(Led, state);
  }
void blink() {
  state = !state;
}