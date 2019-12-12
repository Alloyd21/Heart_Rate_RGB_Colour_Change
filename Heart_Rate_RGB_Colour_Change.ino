#include <RGBLED.h>
RGBLED rgbLed(9,8,7,COMMON_ANODE);

int SensorPin0= 0;
float HeartSensor=0;

void setup() 
{
  HeartSensor= analogRead(SensorPin0);   
  
  Serial.begin(9600);
  pinMode(10, INPUT); // Setup for leads off detection LO +
  pinMode(11, INPUT); // Setup for leads off detection LO -
}
void loop() 

{
Serial.println(analogRead(A0));
   if(HeartSensor > 501)
   {rgbLed.writeRGB(255,0,0);} // If heart rate is high then turn LED Red
        
     else if(HeartSensor > 300 && HeartSensor < 500 )
     {rgbLed.writeRGB(0,255,0);} // If heart rate is average then turn LED Green
      
       else//(HeartSensor < 299)
       {rgbLed.writeRGB(0,0,255);} // If heart rate is low then turn LED Blue
      
        delay(1000);
}
