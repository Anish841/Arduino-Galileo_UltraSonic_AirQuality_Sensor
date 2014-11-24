#include <IoTkit.h>    // include IoTkit.h to use the Intel IoT Kit
#include <Ethernet.h>  // must be included to use IoTkit
#include <aJSON.h>
int check=0;
IoTkit iotkit;  
void setup() {
 Serial.begin(115200);
 iotkit.begin();
}

void loop() {
  // put your main code here, to run repeatedly: 
  int a =analogRead(A0);
  Serial.println(a);
  if(a<350){
    Serial.println("Fresh Air");
  }else if(a>350 && a< 450){
    Serial.println("Somewhat polluted");
  }else if(a>450){
    Serial.println("Polluted Air");
  }
  iotkit.send("airsense", a); 
  delay(1000);
}
 
