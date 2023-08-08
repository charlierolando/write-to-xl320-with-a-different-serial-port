#include "XL320.h"
#define Serial_Port Serial1
#define Serial_Baudrate 1000000

XL320 xl320;

// Set the default servoID to talk to
const int xl320_id[3] = {0, 1, 2};

void setup()
{
  // Talking to Serial_Port using Baudrate Serial_Baudrate, so connect servo data line to Digital TX 1
  Serial_Port.begin(Serial_Baudrate);

  xl320.begin(Serial_Port); // Hand in the serial object you're using

  // Set the joint speed to max!
  for (int i = 0; i < 3; i++)
    xl320.setJointSpeed(xl320_id[i], 1023);

  char rgb[] = "rgbypcwo";
  // Set LED colour (0-7)
  xl320.LED(xl320_id[0], &rgb[0]);
  xl320.LED(xl320_id[1], &rgb[1]);
  xl320.LED(xl320_id[2], &rgb[2]);
}

void loop()
{
  // Set pos value to servo
  int pos_value = 0;

  // Write pos to servo
  for (int i = 0; i < 3; i++)
    xl320.moveJoint(xl320_id[i], pos_value);

  // Delay for 1 second
  delay(1000);

  // Set pos value to servo
  pos_value = 1023;

  // Write pos to servo
  for (int i = 0; i < 3; i++)
    xl320.moveJoint(xl320_id[i], pos_value);

  // Delay for 1 second
  delay(1000);
}
