#define Interrupt 2
#define Sensor A0
#define Led 3


void setup() {
  pinMode(Sensor, INPUT);
  pinMode(Led, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(Interrupt), fInterrupt, CHANGE);
  randomSeed(analogRead(A0));
  Serial. begin(9600);
}

void Interrupt(){
  Serial.println(map(analogRead(Sensor), 0, 1023, 0, 255));
  delay(1000);
}
void loop() {
 
  if (Serial.available()){
    analogWrite(A0,HIGH);
    delay(100);
    digitalWrite (3, LOW);
    delay(100);
  }
  else{
    analogWrite(A0,LOW);
    delay(100);
    digitalWrite (3, HIGH);
    delay(100); 
  }
}
