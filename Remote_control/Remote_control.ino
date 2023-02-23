#define motora1 13
#define motorb1 12
#define motora2 7
#define motorb2 6
#define enA 11
#define enB 5

#define max_speed 200
#define min_speed 100

boolean goesForward = false;
char val;

void setup() {
  Serial.begin(9600);
  
  pinMode(motora1, OUTPUT);
  pinMode(motorb1, OUTPUT);
  pinMode(motora2, OUTPUT);
  pinMode(motorb2, OUTPUT);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  stop();

}

void loop()
{
  while (Serial.available() > 0)
  {
  val = Serial.read();
  Serial.println(val);
  }

  if( val == 'F') // Forward
    {
      goesForward=true;
      
      digitalWrite(motora1, HIGH);
      digitalWrite(motorb1, LOW);
      digitalWrite(motora2, HIGH);
      digitalWrite(motorb2, LOW);
      
      analogWrite(enA, max_speed);
      analogWrite(enB, max_speed);
  }
  
  else if(val == 'B') // Backward
    {
      goesForward=false;
      
      digitalWrite(motora1, LOW);
      digitalWrite(motorb1, HIGH);
      digitalWrite(motora2, LOW);
      digitalWrite(motorb2, HIGH);
      
      analogWrite(enA, max_speed);
      analogWrite(enB, max_speed);
    }
  
    else if(val == 'L') //Left
    {  
      digitalWrite(motora1, HIGH);
      digitalWrite(motorb1, LOW);
      digitalWrite(motora2, LOW);
      digitalWrite(motorb2, HIGH);
      
      analogWrite(enA, max_speed);
      analogWrite(enB, max_speed);
      delay(500);
    }
    else if(val == 'R') //Right
    {
      digitalWrite(motora1, LOW);
      digitalWrite(motorb1, HIGH);
      digitalWrite(motora2, HIGH);
      digitalWrite(motorb2, LOW);
      
      analogWrite(enA, max_speed);
      analogWrite(enB, max_speed);
      delay(500);
    }
    
  else if(val == 'S') //Stop
    {  
      digitalWrite(motora1, LOW);
      digitalWrite(motorb1, LOW);
      digitalWrite(motora2, LOW);
      digitalWrite(motorb2, LOW);
    }
  else if(val == 'I') //Forward Right
    {
    digitalWrite(motora1, HIGH);
    digitalWrite(motorb1, LOW);
    digitalWrite(motora2, LOW);
    digitalWrite(motorb2, LOW);

    analogWrite(enA, min_speed);
    analogWrite(enB, min_speed);
    delay(500);

    
    }
  else if(val == 'J') //Backward Right
    {
    digitalWrite(motora1, LOW);
    digitalWrite(motorb1, HIGH);
    digitalWrite(motora2, LOW);
    digitalWrite(motorb2, LOW);

    
    analogWrite(enA, min_speed);
    analogWrite(enB, min_speed);
    delay(500);

    }
   else if(val == 'G') //Forward Left
    {
    digitalWrite(motora1, LOW);
    digitalWrite(motorb1, LOW);
    digitalWrite(motora2, HIGH);     
    digitalWrite(motorb2, LOW);

    
    analogWrite(enA, min_speed);
    analogWrite(enB, min_speed);
    delay(500);

    }
  else if(val == 'H') //Backward Left
    {
    digitalWrite(motora1, LOW);
    digitalWrite(motorb1, LOW);
    digitalWrite(motora2, LOW);
    digitalWrite(motorb2, HIGH);

     
    analogWrite(enA, min_speed);
    analogWrite(enB, min_speed);
    delay(500);

    }
}
