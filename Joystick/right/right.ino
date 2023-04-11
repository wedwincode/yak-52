// Пример отправки и приёма структуры через Serial
// ПРИЁМНИК
// Ардуины соединены так:
// приёмник D10 -> отправитель D11
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX
// структура для приёма
// должна соответствовать отпраляемой



struct Str {
  bool var_1;
  bool var_2;
  bool var_3;
  bool var_4;
  bool var_5;
  bool var_6;
  bool var_7;
  bool var_8;
  bool var_9;
  bool var_10;
  bool var_11;
  bool var_12;
  bool var_13;
  bool var_14;
  bool var_15;
  bool var_16;
  bool var_17;
  bool var_18;
  bool var_19;
  bool var_20;
  bool var_21;
  bool var_22;
  bool var_23;
  bool var_24;
};
Str buf;

// USB Joystick with hall effect sensors
// NOTE: This sketch file is for use with Arduino Leonardo and
//       Arduino Micro only.
//------------------------------------------------------------
 
//change these to define which pins your hall effect sensors or potentiometers are connected.
//to change button connections, scroll down to loop()
#define X_PIN A0  //маслорадиатор
#define Y_PIN A1  //жалюзи
#define R_PIN A2  //АРК громкость
#define T_PIN A3  //Громкость
#define Rx_PIN A4  //Кремальера МГц
#define Ry_PIN A5  //Кремальера кГц
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
  51, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, but no Z Axis
  true, true, false,   // No Rx, Ry, or Rz
  true, true,            // Yes rudder, yes throttle
  false, false, false);  // No accelerator, brake, or steering
 
void setup() {
  Serial.begin(9600);
  mySerial.begin(4000);
  // Initialize Button Pins
  for (int i=2;i<14;i++){
    if (i!=10)and(i!=11){ 
      pinMode(i, INPUT_PULLUP);
    }
  }
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

  mySerial.readBytes((byte*)&buf, sizeof(buf));
 
  //read buttons. Change pins and button numbers here, if you want to have different number connected to different pin
  Joystick.setButton(0, !digitalRead(2)); //pin 2 LOW means button 0 PRESSED
  Joystick.setButton(1, !digitalRead(3)); //etc.
  Joystick.setButton(2, !digitalRead(4));
  Joystick.setButton(3, !digitalRead(5));
  Joystick.setButton(4, !digitalRead(6));
  Joystick.setButton(5, !digitalRead(7));
  Joystick.setButton(6, !digitalRead(8));
  Joystick.setButton(7, !digitalRead(9));
  Joystick.setButton(8, !digitalRead(12));
  Joystick.setButton(9, !digitalRead(13));
  
  Joystick.setButton(10, !buf.var_1); //тумблеры начало
  Joystick.setButton(11, buf.var_1);
  Joystick.setButton(12, !buf.var_2);
  Joystick.setButton(13, buf.var_2);
  Joystick.setButton(14, !buf.var_3);
  Joystick.setButton(15, buf.var_3);
  Joystick.setButton(16, !buf.var_4);
  Joystick.setButton(17, buf.var_4);
  Joystick.setButton(18, !buf.var_5);
  Joystick.setButton(19, buf.var_5);
  Joystick.setButton(20, !buf.var_6);
  Joystick.setButton(21, buf.var_6);
  Joystick.setButton(22, !buf.var_7);
  Joystick.setButton(23, buf.var_7);
  Joystick.setButton(24, !buf.var_8);
  Joystick.setButton(25, buf.var_8);
  Joystick.setButton(26, !buf.var_9);
  Joystick.setButton(27, buf.var_9);
  Joystick.setButton(28, !buf.var_10);
  Joystick.setButton(29, buf.var_10);
  Joystick.setButton(30, !buf.var_11);
  Joystick.setButton(31, buf.var_11);
  Joystick.setButton(32, !buf.var_12);
  Joystick.setButton(33, buf.var_12);
  Joystick.setButton(34, !buf.var_13);
  Joystick.setButton(35, buf.var_13);
  Joystick.setButton(36, !buf.var_14);
  Joystick.setButton(37, buf.var_14);
  Joystick.setButton(38, !buf.var_15);
  Joystick.setButton(39, buf.var_15); //тумблеры конец

  Joystick.setButton(40, buf.var_16); // компас начало
  Joystick.setButton(41, buf.var_17);
  Joystick.setButton(42, buf.var_18);
  Joystick.setButton(43, buf.var_19);
  Joystick.setButton(44, buf.var_20);
  Joystick.setButton(45, buf.var_21);
  Joystick.setButton(46, buf.var_22); // компас конец

  Joystick.setButton(47, !buf.var_23); // компас  тумблеры начало
  Joystick.setButton(48, buf.var_23);
  Joystick.setButton(49, !buf.var_24);
  Joystick.setButton(50, buf.var_24); // компас тумблеры конец

 
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
