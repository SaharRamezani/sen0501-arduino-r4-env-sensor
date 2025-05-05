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
  float humidity = sensor.getHumidity();   

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  Serial.print("Ultraviolet Intensity: ");
  Serial.print(sensor.getUltravioletIntensity());
  Serial.println(" mw/cm2");
  Serial.print("LuminousIntensity: ");
  Serial.print(sensor.getLuminousIntensity());
  Serial.println(" lx");
  Serial.print("Atmospheric pressure: ");
  Serial.print(sensor.getAtmospherePressure(HPA));
  Serial.println(" hpa");
  Serial.print("Altitude: ");
  Serial.print(sensor.getElevation());
  Serial.println(" m");
  Serial.println("-------------------------------");

  delay(2000);
}
