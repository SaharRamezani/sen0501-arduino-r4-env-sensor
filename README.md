# sen0501-arduino-r4-env-sensor
Working with Arduino R4 WiFi and environmental sensor (DFRobot SEN0501)

install the library for these two devices and remove the "string.h" library from the library code of this sensor:

the file with problem:
/home/username/Arduino/libraries/DFRobot_EnvironmentalSensor/src/DFRobot_EnvironmentalSensor.h

delete this line:
#include "String.h"
