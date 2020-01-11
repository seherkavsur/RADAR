
#include <Ultrasonic.h>

#include <Servo.h>
Servo myservo;

Ultrasonic sensor(6,5); // (Trig PIN,Echo PIN)
int pos = 1;
long cm=0;
 
int st=0;
 
void setup()
{
Serial.begin(9600);
myservo.attach(9);
}
 
void loop()
{
 
if (pos == 1)
st = 0;
 
if (pos == 180)
st = 1;
 
if (st==0)
pos = pos+1;
 
if (st==1)
pos = pos-1;
 
myservo.write(pos);
 
data();
 
Serial.print(pos); Serial.print( " "); Serial.println(cm);
delay(30);
 
}
 
void data()
{

cm = sensor.Ranging(CM);
if (cm>100)
{
cm = 100;
}
}
