const int L1=10,L2=11,L3=12,L4=13;  //CONNECT THE LEDS TO PIN 10,11,12,13 OF THE ARDUINO
const int T7=7,T6=6,T5=5,T4=4; 
const int  button_pin=9;
int trigger_pin = 2;
int echo_pin = 3;
int buzzer_pin = 8; 
int time;

int distance; 


void setup() {
  Serial.begin (9600); 

pinMode(L1,OUTPUT);
pinMode(L2,OUTPUT);
pinMode(L3,OUTPUT);
pinMode(L4,OUTPUT);
pinMode(T4,INPUT); //TAKES THE INPUT FROM THE IR SENSOR(PASSIVE)
pinMode(T5,INPUT);
pinMode(T6,INPUT);
pinMode(T7,INPUT);
pinMode(button_pin,INPUT);
pinMode (trigger_pin, OUTPUT); 
pinMode (echo_pin, INPUT);        
pinMode (buzzer_pin, OUTPUT);

}

void loop() 
{


  while(1)
  {
  if(digitalRead(4)==1)
  {
    digitalWrite(L1,HIGH);
  }
    else 
    {
      digitalWrite(L1,LOW);
    }

 if(digitalRead(5)==1)
  {
    digitalWrite(L2,HIGH);
  }
    else 
    {
      digitalWrite(L2,LOW);
    }
if(digitalRead(6)==1)
  {
    digitalWrite(L3,HIGH);
  }
    else 
    {
      digitalWrite(L3,LOW);
    }
if(digitalRead(7)==1)
  {
    digitalWrite(L4,HIGH);
  }
    else 
    {
      digitalWrite(L4,LOW);
    }


}
   int buttonval = digitalRead(button_pin);

//Now code for the ultrasonic sensor to see if there is any obstruction while parkin it will only work if the button is pressed

if(buttonval==LOW)
{
     digitalWrite (trigger_pin, HIGH);

    delayMicroseconds (10);

    digitalWrite (trigger_pin, LOW);

    time = pulseIn (echo_pin, HIGH);

    distance = (time * 0.034) / 2;

    

  if (distance <= 10) 

        {

        Serial.println (" Door Open ");

        Serial.print (" Distance= ");              

        Serial.println (distance);        

        digitalWrite (buzzer_pin, HIGH);

        delay (500);

        }

  else {

        Serial.println (" OBSTRUCTION");

        Serial.print (" Distance= ");              

        Serial.println (distance);        

        digitalWrite (buzzer_pin, LOW);

        delay (500);        

      } 

  }
}


















