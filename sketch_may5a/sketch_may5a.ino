#include <Wire.h>
#include "DFRobot_EnvironmentalSensor.h"

DFRobot_EnvironmentalSensor sensor(0x22, &Wire);  // I2C address (change if needed)

void setup() {
  Serial.begin(9600);
  delay(1000);
  Wire.begin();

  if (sensor.begin()) {
    Serial.println("Failed to initialize SEN0501 sensor.");
    while (1);
  }

  Serial.println("SEN0501 initialized.");
}

void loop() {
  float temperature = sensor.getTemperature(1);  // 1 = Celsius (this works per earlier error)
  float humidity = sensor.getHumidity();         // works with 0 arguments

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(2000);
}
