#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>
//Personal data
#include "config.h"
//Html page
#include "index_html.h"

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", index_html);
}

void handleData()
{
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    server.send(500, "application/json", "{\"error\":\"Eroare la citirea senzorului\"}");
    return;
  }

  // Construim un obiect JSON: {"temp": 24.5, "hum": 55.0}
  String json = "{\"temp\":" + String(temp, 1) + ",\"hum\":" + String(hum, 1) + "}";
  server.send(200, "application/json", json);
}

void setup() {
  Serial.begin(115200);
  //Sensor
  dht.begin();
  //Wifi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Se conectează la Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectat cu succes!");

  Serial.print("Adresa IP a serverului: http://");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/data", handleData);
  server.begin();
}

void loop() {
  server.handleClient();
}
