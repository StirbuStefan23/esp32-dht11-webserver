#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  Serial.printf("Temperatura este %.2f C\n", temp);
  Serial.printf("Umiditatea este %.2f %\n", hum);

  delay(500);
}
