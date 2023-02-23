#include <Servo.h>        //add Servo Motor library            
#include <NewPing.h>
Servo servo_motor;

#define motora1 13
#define motorb1 12
#define motora2 7
#define motorb2 6
#define enA 11
#define enB 5

int max_speed = 200;

//ultrasonic sensor
#define TRIG A5
#define ECHO A4


#define maximum_distance 200
boolean goesForward = false;
int distance = 100;


NewPing sonar(TRIG, ECHO, maximum_distance);

void setup() {
  Serial.begin(9600);
  
  pinMode(motora1, OUTPUT);
  pinMode(motorb1, OUTPUT);
  pinMode(motora2, OUTPUT);
  pinMode(motorb2, OUTPUT);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  
  servo_motor.attach(3); //our servo pin
  
  servo_motor.write(115);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop() {

  Serial.print("dist: ");
  Serial.println(distance);

  //detect the object.
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 15){
    Stop();
    delay(300);
    backward();
    delay(400);
    Stop();
    delay(300);
    distanceRight = lookRight();
    Serial.print("distR: ");
    Serial.println(distanceRight);
    delay(300);
    distanceLeft = lookLeft();
    Serial.print("distL: ");
    Serial.println(distanceLeft);
    delay(300);

    if (distance >= distanceLeft){
      right();
      Stop();
    }
    else{
      left();
      Stop();
    }
  }
  else{
    forward(); 
  }
    distance = readPing();
}


int lookRight(){  
  servo_motor.write(50);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
}

int lookLeft(){
  servo_motor.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
  delay(100);
}


int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}


void Stop() {
  digitalWrite(motora1, LOW);
  digitalWrite(motorb1, LOW);
  digitalWrite(motora2, LOW);
  digitalWrite(motorb2, LOW);
}
void forward() {

  if(!goesForward){

  goesForward=true;
  digitalWrite(motora1, HIGH);
  digitalWrite(motorb1, LOW);
  digitalWrite(motora2, HIGH);
  digitalWrite(motorb2, LOW);

  analogWrite(enA, max_speed);
  analogWrite(enB, max_speed);
  }
  
}

void backward() {
  

    goesForward=false;

  digitalWrite(motora1, LOW);
  digitalWrite(motorb1, HIGH);
  digitalWrite(motora2, LOW);
  digitalWrite(motorb2, HIGH);

  analogWrite(enA, max_speed);
  analogWrite(enB, max_speed);

}
void right() {
  digitalWrite(motora1, LOW);
  digitalWrite(motorb1, HIGH);
  digitalWrite(motora2, HIGH);
  digitalWrite(motorb2, LOW);

  analogWrite(enA, max_speed);
  analogWrite(enB, max_speed);
  delay(500);
}
void left() {
  digitalWrite(motora1, HIGH);
  digitalWrite(motorb1, LOW);
  digitalWrite(motora2, LOW);
  digitalWrite(motorb2, HIGH);

  analogWrite(enA, max_speed);
  analogWrite(enB, max_speed);
  delay(500);
}
void turnAround() {
  digitalWrite(motora1, LOW);
  digitalWrite(motorb1, HIGH);
  digitalWrite(motora2, HIGH);
  digitalWrite(motorb2, LOW);

  analogWrite(enA, max_speed);
  analogWrite(enB, max_speed);
  delay(1000);
}
