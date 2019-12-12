# Heart Rate RGB Colour Change


## Introduction

This project was built for Bradbury Club at Sacred Heart College in the wearable technology group. 
The goal was to incorporate bio sensors and lights into a wearable item. The group decided on a wearable dress that incorporated RGB strip lighting and fibre optic lights weaved into the fabric of the dress that would be controlled by an arduino and a heart rate monitor. The Arduino would change the colour of the lights based on the heart rate of the individual. 
Red for high, Green for average and blue for low. 

## Setup 

### Parts

- Arduino Uno
- Sparkfun Heart Rate Monitor AD8232
- 3 x 220k Resistors
- 1 x Common Annode RGB LED
- 1 x Breadboard
- Jumper Wire
- Bio-medical pads
- Bio-medical pad cables
*Optional
- RGB Strip Lighting 5v 
- Fibre Optic Decorative Strands


### Install Library 

*This project uses the RGB LED Library by BretStateham*

To install the "RGBLED" library on your computer:

1. Download the lastest zip file from this repository: https://github.com/BretStateham/RGBLED/archive/master.zip

2. Now, open the Arduino IDE, and from the menu select "Sketch" -> "Include Library" -> "Add .ZIP Library", and select the RGBLED zip file from your computer.

![Install Library](https://i.imgur.com/tlYi5qJ.png)


## Wire the LEDs

1. Identify the Annode Pin of the LED. The annode pin is the longest pin. Connect this pin to the 5v Line on the Arduino
2. Connect the remaining pins to the Digital Out pins on the Arduino. In this instance we will be using pins 9,8,7 for R,G,B.
3. Use a 220k Resistor inbetween each RGB pin and the arduino.
![CommonAnnode](https://i.imgur.com/ASuCcwb.png)
![LED Setup](https://raw.githubusercontent.com/BretStateham/RGBLED/master/images/02010-commonanodecircuit.png)

## Wire the Heart Rate Sensor

The heart rate sensor can be directly attached the the breadboard via the soldered on connections. If the connectors are not yet soldered on, go ahead and solder them directly to the sensor board.

| Board Label   | Pin Function  | Arduino Connection |
| ------------- | ------------- | ------------------ |
| GND  | Ground  | GND
| 3.3v  | 3.3v Power Supply  | 3.3v
| Output | Output Signal | A0
| LO- | Leads-off Detect - | 11
| LO+ | Leads-off Detect + | 10
| SDN | Shutdown | Not Used

Once they are are connected to the arduino you can use the Biomedical Pad wire to connect to this sensor board.

## Sensor Pad Placement

Connect the pads to the individual according the the chart and diagram below. 

| Cable Colour | Signal | 
| ------------ | ------------- | 
| Black | Right Arm |
| Blue | Left Arm | 
| Red | Right Leg |

![Sensor Pad Placement](https://cdn.sparkfun.com/r/600-600/assets/learn_tutorials/2/5/0/body.png)



## Code 

Use the code below to copy into the Arduino IDE or use the file in the respository. 

```
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
```

Upload this code to your arduino and leave it connected to the computer as you now want to visualise the data

The serial data is hard to visualize if you are just viewing the values. If you are using Arduino IDE v1.6.6+, there is an option to view the data on a graph using the Arduino Serial Plotter as one option. In the Arduino IDE, select Tools > Serial Plotter. You should see a waveform similar to the image below when the sensors are placed correctly and not moving.
![SerialPlotter](https://cdn.sparkfun.com/assets/learn_tutorials/2/5/0/AD8232_Heart_Rate_Arduino_Serial_Plotter.jpg)

The RGB LED should also be lighting up to the coresponding colours in the code. 
