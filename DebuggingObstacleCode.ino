

int in1 = 9;  // Left motor
int in2 = 10;

int in4 = 6; //right motor
int in3 = 5;

int i=1;  

int lsonartrig=7; //ultrasonic sensor
int  lsonarecho=4;
int rsonartrig=3;
int rsonarecho=2;
int cm=0;
int time=0;
int cm1=0;
int ir=12;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup(){
 pinMode(in1, HIGH);
  pinMode(in2, HIGH);
  pinMode(in3, HIGH);
  pinMode(in4, HIGH);
 pinMode(ir, OUTPUT);
 Serial.begin(9600);
 }

void loop(){ 
if(i=1)
{
  checkArea(1000);
  //Serial.println(i);
 // Serial.println("end");
  //exit(0);
  }
}
int checkArea(int radar)
{
  turnRight();
  Serial.println("right");
  delay(radar);
   Serial.print(radar);
      Serial.print("s");
      Serial.println("");
  stop();
  Serial.println("First stop");
  time = readUltrasonicDistance(lsonartrig, lsonarecho);
  cm = 0.01723 * time;
  Serial.print(cm);
      Serial.print("cm");
      Serial.println("");
  if(cm<=30)
    {
      turnLeft();
      Serial.println("left");
      delay(radar+radar);
      Serial.print(radar+radar);
      Serial.print("s");
      Serial.println("");
      stop();
      Serial.println("2nd stop");
      time = readUltrasonicDistance(lsonartrig, lsonarecho);
      cm = 0.01723 * time;
      if(cm<30)
      {
      turnRight();
      Serial.println("2nd right");
      delay(radar);  
      Serial.print(radar);
      Serial.print("s");
      Serial.println("");
      }
      else return 2;
      Serial.println("Testing");
    }
    else return 1;
    
    
    
}
void evadeRight(int radar)
  {
    Serial.println("executing evadeRight protocol");
    forward();
    delay(radar);
    stop();
    turnLeft();
    delay(radar);
    forward();
    delay(radar);
    turnRight();
    delay(radar);
    stop();
  }
  

  
void evadeLeft(int radar)
  {
    Serial.println("executing evadeLef=t protocol");
    forward();
    delay(radar);
    stop();
    turnRight();
    delay(radar);
    forward();
    delay(radar);
    turnLeft();
    delay(radar);
    stop();
  }
 void stop(){
 digitalWrite(in1, LOW);  // Turn off motors
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW); 
}

void forward(){
 digitalWrite(in1, HIGH); 
digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);  
}

void backward(){
 digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);  
}


void turnRight(){
digitalWrite(in1, HIGH); 
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);  
}

void turnLeft(){
digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);   
}
