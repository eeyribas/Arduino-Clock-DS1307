#include <Wire.h>
#include "Nextion.h"

#define DS1307_ADDRESS 0x68

SoftwareSerial nextion_soft_serial(3, 4);
Nextion nextion(nextion_soft_serial, 9600);

void setup() 
{
  Serial.begin(9600);
  Wire.begin();
  
  nextion.init();
  delay(2000);
}

void loop() 
{
  PrintDate();
  delay(1000);
}

void PrintDate() 
{
  Wire.beginTransmission(DS1307_ADDRESS);
  byte zero = 0x00;
  Wire.write(zero);
  Wire.endTransmission();

  Wire.requestFrom(DS1307_ADDRESS, 7);
  int second = BcdToDec(Wire.read());
  int minute = BcdToDec(Wire.read());
  int hour = BcdToDec(Wire.read() & 0b111111);
  int week_day = BcdToDec(Wire.read());
  int month_day = BcdToDec(Wire.read());
  int month = BcdToDec(Wire.read());
  int year = BcdToDec(Wire.read());
  Serial.print("Time: ");
  Serial.print(month_day);
  Serial.print("/");
  Serial.print(month);
  Serial.print("/");
  Serial.print(year);
  Serial.print(" Hour :");
  Serial.print(" ");
  Serial.print(hour);
  Serial.print(":");
  Serial.print(minute);
  Serial.print(":");
  Serial.print(second);
  Serial.println();

  nextion.setComponentText("t0", String(month_day));
  nextion.setComponentText("t1", String(month));
  nextion.setComponentText("t2", String(year));
  nextion.setComponentText("t3", String(hour));
  nextion.setComponentText("t4", String(minute));
  nextion.setComponentText("t5", String(second));

  delay(1);
}

byte BcdToDec(byte val) 
{
  return ((val / 16 * 10) + (val % 16));
}