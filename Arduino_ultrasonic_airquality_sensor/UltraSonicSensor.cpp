#include <IoTkit.h>    // include IoTkit.h to use the Intel IoT Kit
#include <Ethernet.h>  // must be included to use IoTkit
#include <aJSON.h>
int trig = 7;
int echo = 6;
//int buz = 9;
IoTkit iotkit;
float level=0;
void setup()
{
   Serial.begin(115200);
   iotkit.begin();
   pinMode(trig,OUTPUT);
   pinMode(echo, INPUT);
}

void loop()
{
  int duration, distance;
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);

  duration =pulseIn(echo, HIGH);
  distance = (duration/2)/29.1;
if(distance<100)
  {
    Serial.println(distance);
    Serial.println("cm");

  }/*if( distance <= 10 )
  {
  //digitalWrite( buz, HIGH);
  tone(buz,100,10);
  }*/
  if(distance<=6){
    level=4;
    Serial.println("Filled need to pick up");
  }else  if(6<distance && distance<=12){
    level=3;
    Serial.println("Half Filled");
  }else if(13<distance && distance<=18){
    level=2;
    Serial.println("Half Filled");
  }else if(distance>19){
    level=1;
    Serial.println("Almost empty");
  }
  level=level*2.5;
   iotkit.send("ultra", level); 
  delay(1000);
  delay(200);  
}
