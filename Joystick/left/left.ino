// USB Joystick with hall effect sensors
// NOTE: This sketch file is for use with Arduino Leonardo and
//       Arduino Micro only.
//------------------------------------------------------------
 
//change these to define which pins your hall effect sensors or potentiometers are connected.
//to change button connections, scroll down to loop()
#define X_PIN A0  //крен
#define Y_PIN A1  //тангаж
#define R_PIN A2  //рвскание (педали)
#define T_PIN A3  //РУД
#define Rx_PIN A4  //шаг винта
#define Ry_PIN A5  //триммер
//change these to change trim and limits. Calibrating your joystick in Windows achieves the same thing
#define X_MIN 0
#define X_MAX 1023
#define X_TRIM 0
#define X_INVERT 1
//to invert an axis, change 1 to -1
#define Y_MIN 0
#define Y_MAX 1023
#define Y_TRIM 0
#define Y_INVERT 1
 
#define R_MIN 0
#define R_MAX 1023
#define R_TRIM 0
#define R_INVERT 1
 
#define T_MIN 0
#define T_MAX 1023
#define T_TRIM 0
#define T_INVERT 1

#define Rx_MIN 0
#define Rx_MAX 1023
#define Rx_TRIM 0
#define Rx_INVERT 1

#define Ry_MIN 0
#define Ry_MAX 1023
#define Ry_TRIM 0
#define Ry_INVERT 1
 
#include <Joystick.h>
 
Joystick_ Joystick(0x04,JOYSTICK_TYPE_JOYSTICK,
  12, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, but no Z Axis
  true, true, false,   // No Rx, Ry, or Rz
  true, true,            // Yes rudder, yes throttle
  false, false, false);  // No accelerator, brake, or steering
 
void setup() {
  // Initialize Button Pins
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
 
  // Initialize Joystick Library
  Joystick.begin(false); //false = dont send automatically. We will sendState() at the end of the loop
  Joystick.setXAxisRange(-512, 512);
  Joystick.setYAxisRange(-512, 512);
  Joystick.setRudderRange(-512, 512);
  Joystick.setThrottleRange(-512, 512);
  Joystick.setRxAxisRange(-512, 512);
  Joystick.setRyAxisRange(-512, 512);
}
 
 
void loop() {
  //read buttons. Change pins and button numbers here, if you want to have different number connected to different pin
  Joystick.setButton(0, !digitalRead(2)); //pin 2 LOW means button 0 PRESSED
  Joystick.setButton(1, !digitalRead(3)); //etc.
  Joystick.setButton(2, !digitalRead(4));
  Joystick.setButton(3, !digitalRead(5));
  Joystick.setButton(4, !digitalRead(6));
  Joystick.setButton(5, !digitalRead(7));
  Joystick.setButton(6, !digitalRead(8));
  Joystick.setButton(7, !digitalRead(9));
  Joystick.setButton(8, !digitalRead(10));
  Joystick.setButton(9, !digitalRead(11));
  Joystick.setButton(10, !digitalRead(12));
  Joystick.setButton(11, !digitalRead(13));
 
  //read analog axes
  int value = map(analogRead(X_PIN) + X_TRIM , X_MIN, X_MAX, -512, 512) * X_INVERT;
  Joystick.setXAxis(value);
  value = map(analogRead(Y_PIN) + Y_TRIM , Y_MIN, Y_MAX, -512, 512) *Y_INVERT;
  Joystick.setYAxis(value);
  value = map(analogRead(R_PIN) + R_TRIM , R_MIN, R_MAX, -512, 512) * R_INVERT;
  Joystick.setRudder(value);
  value = map(analogRead(T_PIN) + T_TRIM , T_MIN, T_MAX, -512, 512) * T_INVERT;
  Joystick.setThrottle(value);
  value = map(analogRead(Rx_PIN) + Rx_TRIM , Rx_MIN, Rx_MAX, -512, 512) * Rx_INVERT;
  Joystick.setRxAxis(value);
  value = map(analogRead(Ry_PIN) + Ry_TRIM , Ry_MIN, Ry_MAX, -512, 512) * Ry_INVERT;
  Joystick.setRyAxis(value);
  
  Joystick.sendState();
  delay(10);
}
