#include <Servo.h>
#include <Ultrasonic.h>

#define echo 4
#define trigger 5
#define VRx A0
#define VRy A1
#define SW 2

#define enable_a 8
#define EN1 9
#define EN2 10

Servo servo;
Ultrasonic ultrasonic(trigger, echo);
int pos, x_axe, y_axe, count;

void setup(){
  servo.attach(3);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW,INPUT_PULLUP);

  pinMode(enable_a, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);

  digitalWrite(enable_a,HIGH);
  servo.write(0);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(SW),range, FALLING);

}

String joystick(){
  x_axe=analogRead(VRx);
  y_axe=analogRead(VRy);
  bool xchange=x_axe<450;
  bool x2change=x_axe>600;
  bool ychange=y_axe<450;
  bool y2change=y_axe>600;
  String join = 
  String (xchange)+
  String(x2change)+
  String(ychange)+
  String(y2change);

  return join;

}

void dcMotor (String control){
  if (control=="1000"){
    digitalWrite(EN1, HIGH);
    digitalWrite(EN2, LOW);
    delay(300);
  }
  if(control=="0100"){
    digitalWrite(EN1, LOW);
    digitalWrite(EN2, HIGH);
    delay(300);
  }
  digitalWrite(EN1, LOW);
  digitalWrite(EN2, LOW);
}

void servoMotor(String control){
  if(control=="0010" && pos > 0){
    pos--;
    servo.write(pos);
    delay(10);
  }
  if (control=="0001" && pos < 180){
    pos++;
    servo.write(pos);
    delay(10);
  }
}

void range(){
  int microsec;
  int cm;
  if(millis()-count>600){
    microsec = ultrasonic.timing ();
    cm= ultrasonic.convert (microsec, Ultrasonic::CM);
    Serial.print('\n');
    Serial.print("TOTAL DISTANCE : ");
    Serial.print(cm);
    Serial.print(" cm");
    delay(100);
    count=millis();
  }
}
void loop(){
  String teste = joystick();
  servoMotor (teste);
  dcMotor(teste);
}