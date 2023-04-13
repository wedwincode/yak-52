#include <SoftwareSerial.h>

// Пример отправки и приёма структуры через Serial
// ОТПРАВИТЕЛЬ
// Ардуины соединены так:
// отправитель D11 -> приёмник D10
SoftwareSerial mySerial(11, 10); // RX, TX

struct Str {
  bool arr[27];
};

void setup() {
  Serial.begin(9600);
  mySerial.begin(4000);
  // Initialize Button Pins
  for (int i=2;i<31;i++){
    if ((i!=10)&&(i!=11)){ 
      pinMode(i, INPUT_PULLUP);
    }
  }
}
 
 
void loop() {

  Str buf;

  for (int i=0;i<8;i++) {
    buf.arr[i] = digitalRead(i+2);
  }
  for (int i=8;i<27;i++) {
    buf.arr[i] = digitalRead(i+4);
  }
  

  /*buf.var_1 = digitalRead(2);
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
  buf.var_25 = digitalRead(28);
  buf.var_26 = digitalRead(29);
  buf.var_27 = digitalRead(30);*/
  
  mySerial.write((byte*)&buf, sizeof(buf)); //mySerial.write((byte*)&buf, sizeof(buf));
  
  delay(10);
}
