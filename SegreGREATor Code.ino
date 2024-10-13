#include <Servo.h>

const int soilSensorPin = 9;          
const int servoPin = 8;          
const int trigPin = 10;          
const int echoPin = 11;      

Servo myservo;

void setup() {
  pinMode(servoPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(servoPin);
  Serial.begin(9600);
}

float getDistanceUltrasonic() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.0343 / 2;
  return distance;
}

void loop() {
  float ultrasonicDistance = getDistanceUltrasonic();

 
  Serial.print("Ultrasonic Distance: ");
  Serial.println(ultrasonicDistance);
 
  if (ultrasonicDistance < 15) {
    delay(1000);
    if (digitalRead(soilSensorPin) == HIGH) {
      myservo.write(135);
      delay(1000);

    }
     if (digitalRead(soilSensorPin) == LOW) {
      myservo.write(45);
      delay(1000);
    }
  }
  else {
    myservo.write(90);
  }
}