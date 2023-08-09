# write-to-xl320-with-a-different-serial-port

**Using [Dynamixel XL-320](https://github.com/ROBOTIS-GIT/emanual/blob/master/docs/en/dxl/x/xl320.md) with a different serial port on [OpenCM 9.04](https://github.com/ROBOTIS-GIT/emanual/blob/master/docs/en/parts/controller/opencm904.md) or [OpenCR 1.0](https://github.com/ROBOTIS-GIT/emanual/blob/master/docs/en/parts/controller/opencr10.md)**

>This tools can be used for other boards, but can be used more than 1mbps baudrates on OpenCR 1.0 or up to 1mbps baudrates on OpenCM 9.04

![Result](https://github.com/charlierolando/write-to-xl320-with-a-different-serial-port/blob/master/images/images1.gif)

klik [this](https://github.com/charlierolando/write-to-xl320-with-a-different-serial-port/blob/master/images/images1.gif) when the image doesn't appear

## [How to use:](#how-to-use)

**• See [xl320.ino](https://github.com/charlierolando/write-to-xl320-with-a-different-serial-port/blob/master/xl320.ino)**

**• Change Serial Port:**

```cpp title="editt.cpp"
#define Serial_Port Serial1
```
to

```cpp title="editt.cpp"
#define Serial_Port *Serial_Port
```

**• Change Baudrate configuration:**

```cpp title="editt.cpp"
#define Serial_Baudrate 1000000
```
to

```cpp title="editt.cpp"
#define Serial_Baudrate *Baudrate
```

**• Change ID configuration:**

```cpp title="editt.cpp"
const int xl320_id[3] = {0, 1, 2};
```
to

```cpp title="editt.cpp"
const int xl320_id[*number_of_servos] = {*ID_1, *ID_2};
```

**• Servo Handle:**

```cpp title="editt.cpp"
  // Talking to Serial_Port using Baudrate Serial_Baudrate, so connect servo data line to TX Serial port
  Serial_Port.begin(*Serial_Baudrate);

  xl320.begin(*Serial_Port); // Hand in the serial object you're using
```

**• Set servo speed:**

```cpp title="editt.cpp"
  // Set the joint speed (0 - 1023)
  xl320.setJointSpeed(*servo_ID, *value);
```

**• Set servo LED color:**

```cpp title="editt.cpp"
  char rgb[] = "rgbypcwo";
  // Set LED color (0-7)
  xl320.LED(*servo_ID, &rgb[*value]);
```

**• Set servo pos:**

```cpp title="editt.cpp"
  // Write pos to servo (0 - 1023)
  xl320.moveJoint(*servo_ID, *pos_value);
```

**• Wiring diagram**

Looking from above, with the servo head at the top, wire the left plug of the servo to:

* PIN1: GND
* PIN2: 6 ~ 8.4 Volts (Recommended : 7.4 Volts)
* PIN3: Serial TX

![Dynamixel XL-320 wiring diagram](XL320-wiring.jpg)

**• Other**
>Setting the servo serial baud rate & servoID

We've included some example sketches to help test and setup your servos. Out of the box they're set to communicate via serial at 1Mbps, so you might want to set them down to something more managable by Arduino at 115200.

Follow the instructions in the sketch ```XL320_servo_set_baud_rate_or_id.ino``` and don't forget to power cycle the servos in between setting anything.

Note: when setting the ServoID, the servos default down to 9600 baud, so after you set the servoID you'll need to set the baud rate back up to 115200.

## [References:](#references)

[hackerspace-adelaide/XL320](https://github.com/hackerspace-adelaide/XL320)
