#include <Wire.h>

#define DS1307_ADDRESS 0x68

byte zero = 0x00;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  
  SetDateTime();
}

void loop()
{
  PrintDate();
  delay(1000);
}

void SetDateTime()
{
  byte second = 0;
  byte minute = 54;
  byte hour = 16;
  byte week_day = 2;
  byte month_day = 10;
  byte month = 8;
  byte year = 18;

  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero);
  Wire.write(DecToBcd(second));
  Wire.write(DecToBcd(minute));
  Wire.write(DecToBcd(hour));
  Wire.write(DecToBcd(week_day));
  Wire.write(DecToBcd(month_day));
  Wire.write(DecToBcd(month));
  Wire.write(DecToBcd(year));
  Wire.write(zero);
  Wire.endTransmission();
}

byte DecToBcd(byte val)
{
  return ((val / 10 * 16) + (val % 10));
}

byte BcdToDec(byte val)
{
  return ((val / 16 * 10) + (val % 16));
}

void PrintDate()
{
  Wire.beginTransmission(DS1307_ADDRESS);
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
  Serial.print(month);
  Serial.print("/");
  Serial.print(month_day);
  Serial.print("/");
  Serial.print(year);
  Serial.print(" ");
  Serial.print(hour);
  Serial.print(":");
  Serial.print(minute);
  Serial.print(":");
  Serial.println(second);
}
