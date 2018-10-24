#include <SoftwareSerial.h>
SoftwareSerial BlueTooth(3, 9); // (TXD, RXD) of HC-06

char BT_input; // to store input character received via BT.

void setup()  
{
  pinMode(5,OUTPUT);              // Right Motor
  pinMode(6,OUTPUT);              // Right Motor
  pinMode(10,OUTPUT);             // Left Motor
  pinMode(11,OUTPUT);             // Left Motor
  BlueTooth.begin(9600);
}

void loop() 
{
  if (BlueTooth.available())
  {
    BT_input = (BlueTooth.read());
    if (BT_input=='a')                       // Move Forward
    {
      BlueTooth.println("\n");
      BlueTooth.println("Moving Forward");
      analogWrite(5,100);
      analogWrite(6,0);
      analogWrite(10,100);
      analogWrite(11,0);
    }
    
    if (BT_input=='b')                          // Not Moving
    {
      BlueTooth.println("\n");  
      BlueTooth.println("Not Moving");
      analogWrite(5,0);
      analogWrite(6,0);
      analogWrite(10,0);
      analogWrite(11,0);
    }

     if (BT_input=='c')              // Moving Backwards
    {
      BlueTooth.println("\n");  
      BlueTooth.println("Moving Backward");
      analogWrite(5,0);
      analogWrite(6,100);
      analogWrite(10,0);
      analogWrite(11,100);
    }

    if (BT_input=='d')                 // Moving Left
    {
      BlueTooth.println("\n");  
      BlueTooth.println("Moving Left");
      analogWrite(5,100);
      analogWrite(6,0);
      analogWrite(10,0);
      analogWrite(11,0);
    }

    if (BT_input=='e')                 // Moving Right
    {
      BlueTooth.println("\n");  
      BlueTooth.println("Moving Right");
      analogWrite(5,0);
      analogWrite(6,0);
      analogWrite(10,100);
      analogWrite(11,0);
    }

    if (BT_input=='f')                   // Moving in Full Speed
    {
      BlueTooth.println("\n");
      BlueTooth.println("Moving Full speed");
      analogWrite(5,255);
      analogWrite(6,0);
      analogWrite(10,255);
      analogWrite(11,0);
    }
  }
}


