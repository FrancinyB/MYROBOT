#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); // Instancia um objeto MFRC522
char st[20];

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Aproxime o seu cartao do leitor...");
}

void loop() {
 
  if (mfrc522.PICC_IsNewCardPresent()) 
  {
  return;
  }
    if (mfrc522.PICC_ReadCardSerial()) 
  {
  return;
  }
  String conteudo = "";
  byte letra;
  
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        Serial.print(!mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(!mfrc522.uid.uidByte[i], HEX);
        conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        conteudo.concat(String(mfrc522.uid.uidByte[i], HEX);
      }
  if (conteudo.substring(1) == "xx xx xx xx")
  {
  Serial.println(1);
  delay(1000);
  }
   if (conteudo.substring(1) == "xx xx xx xx")
  {
  Serial.println(2);
  delay(1000);
  }




  import processing.serial.*;

  Serial myPort;
  printArray(Serial.list());
  
  import processing.serial.*;
  Serial myPort;
  String inString;

  PImage bg;
  PImage blocked;
  PImage open;

  float arcX=200, arcY=350;
  int arcControl=0;

  int bgControl=2;

  float animation;

  void settings() {
  size(400, 600);
  smooth(2);
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[1], 9600);
  myPort.bufferUntil(10);
}

void setup(){
bg = loadImage("Back.png");
blocked = loadImage("Blocked.png");
open =loadImage("Open.png");
}

void serialEvent(Serial p){
inString = p.readString();

float inSerial = float(inString);

if (inSerial == 1) {
  bgControl = 1;
  delay(5000);
  bgControl = 0;
  println("Identificado!");
} else if (inSerial == 2) {
  bgControl = 2;
  delay(5000);
  bgControl = 0;
  println("Não identificado!");
} else {
  bgControl = 0;
}

void draw(){
swtich(bgControl){
case:0;
image(bg, 0, 0);
break;
case:1;
image(open, 0, 0);
break;
case:2;
image(blocked, 0, 0);
break;
}

noFill();
stroke(255-(animation*10), 100+(animation*10), animation*20);
strokeWeight(10);

if (bgControl == 0) {
  if (animation > 3 && animation <= 6) {
    arc(arcx, arcy, 260, 260, radians(-15), radians(15));
    arc(arcx, arcy, 260, 260, radians(165), radians(195));
  } else if (animation > 6 && animation <= 9) {
    arc(arcx, arcy, 260, 260, radians(-15), radians(15));
    arc(arcx, arcy, 260, 260, radians(165), radians(195));
    arc(arcx, arcy, 260, 260, radians(-15), radians(15));
    arc(arcx, arcy, 260, 260, radians(165), radians(195));
  } else if (animation > 9 && animation <= 12) {
    arc(arcx, arcy, 260, 260, radians(-15), radians(15));
    arc(arcx, arcy, 260, 260, radians(165), radians(195));
    arc(arcx, arcy, 260, 260, radians(-15), radians(15));
    arc(arcx, arcy, 260, 260, radians(165), radians(195));
    arc(arcx, arcy, 260, 260, radians(-15), radians(15));
    arc(arcx, arcy, 260, 260, radians(165), radians(195));
  } else if (animation > 12) {
    animation = 0;
  }
  animation += 0.1;
}
}
