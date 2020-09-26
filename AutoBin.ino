#include <Servo.h> 
Servo myservo;

int trigPin = 10;   
int echoPin = 11;  
long duration, cm;

   
void setup() 
{ 
  myservo.attach(7);
  Serial.begin(115200);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT); 
} 
void loop() 
{       
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
 


  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  cm = (duration/2) / 29.1;

    
  if(cm <= 17)
  {            
        myservo.write(0); 
        delay(5000);      
        Serial.println("ฝาถังขยะได้ถูกเปิดออก");      
      //  myservo.write(180); 
      //  delay(1000);            
           
  }//if
  else{
      myservo.write(180);
      
  /*   
    for(pos = 180; pos >= 0; pos -=1)
    {
      myservo.write(pos);
      delay(100);
    }//for
   */
  } 
                 
}
