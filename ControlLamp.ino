#include <SoftwareSerial.h>
#include <Servo.h>

Servo servo;

void turnSwtich();

int blueTx=2;
int blueRx=3;
SoftwareSerial mySerial(blueTx, blueRx);
String myString="";
int angle = 90;

void setup() {
  mySerial.begin(9600);
}

void loop() {
  while(mySerial.available())
  {
    char myChar = (char)mySerial.read();
    myString+=myChar;
    delay(5);
    servo.attach(5);
    servo.write(90);
    pinMode(LED_BUILTIN, OUTPUT);
  }
  
  if(!myString.equals(""))
  {
    Serial.println("input value: "+myString);

      if(myString=="switch")
      {
        turnSwitch();
      }
      else {
      }
    myString="";
  }
}

void turnSwitch() {
  static bool isOn = true;
  if (isOn) {
    servo.writeMicroseconds(1700);
    isOn = false;
  } else {
    servo.writeMicroseconds(1200);
    isOn = true;
  }
  delay(400);
  servo.detach();
}
