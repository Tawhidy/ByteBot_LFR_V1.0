#include <DHT.h>

#define DHTPIN 2         // Pin connected to DHT sensor
#define DHTTYPE DHT11    // DHT 11 sensor
#define RELAY_PIN 10     // Pin connected to relay module (humidifier)
#define FAN_PIN 9        // Pin connected to fan or cooler

int humidityThreshold = 90;      // Desired humidity threshold
int temperatureThreshold = 40;   // Desired temperature threshold (in °C)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%  Temperature: ");
  Serial.print(temperature);
  Serial.println("C");

  // Control humidifier
  //if (humidity < humidityThreshold) {
   // digitalWrite(RELAY_PIN, HIGH); // Turn on humidifier
  //} else {
   // digitalWrite(RELAY_PIN, LOW);  // Turn off humidifier
  //}

  // Control fan/cooling system
  if (temperature > temperatureThreshold) {
    digitalWrite(FAN_PIN, HIGH);   // Turn on cooling system
  } else {
    digitalWrite(FAN_PIN, LOW);    // Turn off cooling system
  }

  //delay(2000); // Wait 2 seconds before next reading
}
