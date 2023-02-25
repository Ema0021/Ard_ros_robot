// Arduino Line Follower Robot Code: vedere https://circuitdigest.com/microcontroller-projects/arduino-uno-line-follower-robot, sistemare anche rispettivi motori 

#define enA 11//Enable1 L293 Pin enA 
#define in1 13 //Motor1  L293 Pin in1 
#define in2 12 //Motor1  L293 Pin in1 
#define in3 7 //Motor2  L293 Pin in1 
#define in4 6 //Motor2  L293 Pin in1 
#define enB 5 //Enable2 L293 Pin enB 

#define R_S 4//ir sensor Right
#define L_S 2 //ir sensor Left

void setup(){ 

pinMode(R_S, INPUT); 
pinMode(L_S, INPUT); 

pinMode(enA, OUTPUT); 
pinMode(in1, OUTPUT); 
pinMode(in2, OUTPUT); 

pinMode(enB, OUTPUT);
pinMode(in3, OUTPUT); 
pinMode(in4, OUTPUT); 


digitalWrite(enA, HIGH); 
digitalWrite(enB, HIGH); 

delay(1000);

}

void loop(){  

//if Right Sensor and Left Sensor are at White color then it will call forword function
if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){
  forward();
 } 
   
//if Right Sensor is Black and Left Sensor is White then it will call turn Right function 
if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)){
  turnRight();
  } 
  
//if Right Sensor is White and Left Sensor is Black then it will call turn Left function
if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)){
  turnLeft();
  }  

//if Right Sensor and Left Sensor are at Black color then it will call Stop function
if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 1)){
  Stop();
  } 
}

void forward(){  //forword

digitalWrite(in1, HIGH); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 

}

void turnRight(){ //turnRight

digitalWrite(in1, LOW);  //Right Motor forword Pin 
digitalWrite(in2, HIGH); //Right Motor backword Pin  
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 

}

void turnLeft(){ //turnLeft

digitalWrite(in1, HIGH); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
digitalWrite(in3, HIGH); //Left Motor backword Pin 
digitalWrite(in4, LOW);  //Left Motor forword Pin 

}

void Stop(){ //stop

digitalWrite(in1, LOW); //Right Motor forword Pin 
digitalWrite(in2, LOW); //Right Motor backword Pin 
digitalWrite(in3, LOW); //Left Motor backword Pin 
digitalWrite(in4, LOW); //Left Motor forword Pin 

}
