#include <SoftwareSerial.h>

// Пример отправки и приёма структуры через Serial
// ОТПРАВИТЕЛЬ
// Ардуины соединены так:
// отправитель D11 -> приёмник D10
SoftwareSerial mySerial(50, 51); // RX, TX

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

void setup() {
  Serial.begin(9600);
  mySerial.begin(4000);
  // Initialize Button Pins
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
//pinMode(10, INPUT_PULLUP);
//pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  pinMode(22, INPUT_PULLUP);
  pinMode(23, INPUT_PULLUP);
  pinMode(24, INPUT_PULLUP);
  pinMode(25, INPUT_PULLUP);
  pinMode(26, INPUT_PULLUP);
  pinMode(27, INPUT_PULLUP);
 
}
 
 
void loop() {

  Str buf;
  
  buf.var_1 = digitalRead(2);
  buf.var_2 = digitalRead(3);
  buf.var_3 = digitalRead(4);
  buf.var_4 = digitalRead(5);
  buf.var_5 = digitalRead(6);
  buf.var_6 = digitalRead(7);
  buf.var_7 = digitalRead(8);
  buf.var_8 = digitalRead(9);
  buf.var_9 = digitalRead(12);
  buf.var_10 = digitalRead(13);
  buf.var_11 = digitalRead(14);
  buf.var_12 = digitalRead(15);
  buf.var_13 = digitalRead(16);
  buf.var_14 = digitalRead(17);
  buf.var_15 = digitalRead(18);
  buf.var_16 = digitalRead(19);
  buf.var_17 = digitalRead(20);
  buf.var_18 = digitalRead(21);
  buf.var_19 = digitalRead(22);
  buf.var_20 = digitalRead(23);
  buf.var_21 = digitalRead(24);
  buf.var_22 = digitalRead(25);
  buf.var_23 = digitalRead(26);
  buf.var_24 = digitalRead(27);
  
  mySerial.write((byte*)&buf, sizeof(buf)); //mySerial.write((byte*)&buf, sizeof(buf));
  
  delay(10);
}
