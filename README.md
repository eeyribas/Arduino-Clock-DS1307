# Arduino-Clock-DS1307
Contains examples using the DS1307 module with Arduino. These examples include DisplayingTimeWithNextionScreen, DisplayingTimeWithRTCLib and SetTime. These examples:

1. DisplayingTimeWithNextionScreen: The time value is displayed on the interface designed on the Nextion screen.

2. DisplayingTimeWithRTCLib: The time value is sent to the Serial Monitor using the RTCLib library.

3. SetTime: The time value is set in the chip of the DS1307 module.

Programming Language: C/C++ Programming Language

IDE: Arduino IDE Version - 2.2.0

Arduino Used: Arduino Uno, Arduino Mega

Arduino Libraries: 

1. nextion-master.zip: This library enables the use of the Nextion screen. Include this library in your Arduino IDE. 

2. RTClib-master.zip: This library enables the use of the DS1307 module. Include this library in your Arduino IDE.

Arduino Connection Diagram:

1. Arduino-Nextion Connection Diagram: The Nextion screen is connected to Arduino's pins D3 and D4. 

2. Arduino-DS1307 Module Connection Diagram: The DS1307 module is connected to the Arduino's pins A4 and A5.

Nextion Screen Design: Upload the designs found in the 'Nextion Screen Design File' to your Nextion screen using an SD card.