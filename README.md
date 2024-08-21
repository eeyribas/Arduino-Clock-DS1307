# Arduino-Clock-DS1307-Examples
The repository contains examples using the DS1307 chip with Arduino. There are three examples available:

1. DisplayingTimeWithNextionScreen: The time value is displayed on the interface designed on the Nextion screen.

2. DisplayingTimeWithRTCLib: The time value is sent to the Serial Monitor using the RTCLib library.

3. SetTime: The time value is set in the DS1307 chip.

Arduino Used: Arduino Uno, Arduino Mega

Arduino IDE Version: 2.2.0

Arduino Libraries: The nextion-master.zip file in the repository is for using the Nextion screen. The RTClib-master.zip file in the repository allows us to use the DS1307 clock module. Please include these files in your Arduino IDE.

Arduino Connection: The Nextion screen is connected to Arduino pins D3 and D4. The DS1307 module is connected to Arduino pins A4 and A5.

Nextion Screen Design: Upload the designs found in the 'Nextion Screen Design File' to your Nextion screen using an SD card.