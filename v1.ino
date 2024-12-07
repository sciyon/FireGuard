/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-gas-sensor
 */

#include <DHT.h>
#define DHT_SENSOR_PIN  21 // ESP32 pin GPIO21 connected to DHT22 sensor
#define DHT_SENSOR_TYPE DHT22
#define AO_PIN 36  // ESP32's pin GPIO36 connected to AO pin of the MQ2 sensor

DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

void setup() {
  // initialize serial communication
  Serial.begin(9600);

  // set the ADC attenuation to 11 dB (up to ~3.3V input)
  analogSetAttenuation(ADC_11db);
  Serial.println("Warming up the MQ2 sensor");
  delay(20000);  // wait for the MQ2 to warm up

  dht_sensor.begin(); // initialize the DHT sensor
}

void loop() {
  float humi  = dht_sensor.readHumidity();
  float tempC = dht_sensor.readTemperature();
  float tempF = dht_sensor.readTemperature(true);

  int gas = analogRead(AO_PIN);

  Serial.print("Gas: ");
  Serial.print(gas);
  
  Serial.print("\t\tHumidity: ");
  Serial.print(humi);
  Serial.print("%");
  Serial.print("\t\tTemperature: ");
  Serial.print(tempC);
  Serial.print("°C  ~  ");
  Serial.print(tempF);
  Serial.println("°F");
  delay(500);
}
