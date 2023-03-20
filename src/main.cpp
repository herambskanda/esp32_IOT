#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <DHT.h>

#include <htmlsrc.h>
#include <pinmacros.h>
#include <wifi_login.h>

WebServer server(80);
DHT dht(dht_pin, DHT11);


float readDHTTemperature();
float readDHTHumidity();
float us_distance();
float weight();


void handleRoot() {
  char htmlscript[1500];

  snprintf(htmlscript, 1500, htmlsrc, readDHTTemperature(), readDHTHumidity(), us_distance(), weight());

  server.send(200, "text/html", htmlscript);
  digitalWrite(onboard_led, HIGH);
  delay(100);
  digitalWrite(onboard_led, LOW);

}

void setup(void) {

  Serial.begin(115200);
  
  pinMode(onboard_led, OUTPUT);
  pinMode(us_trig, OUTPUT);
  pinMode(us_echo, INPUT);
  
  dht.begin();
    
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }
  server.on("/", handleRoot);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  delay(2);
  
}


float readDHTTemperature() {

  float t = dht.readTemperature();
  if (isnan(t)) {    
    Serial.println("Failed to read from DHT sensor!");
    return -1;
  }
  else {
    Serial.println(t);
    return t;
  }
}

float readDHTHumidity() {

  float h = dht.readHumidity();
  if (isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
    return -1;
  }
  else {
    Serial.println(h);
    return h;
  }
}

float us_distance() {
  float duration;
  float distance;
  digitalWrite(us_trig, LOW);
  delay(5);
  digitalWrite(us_trig, HIGH);
  delay(10);
  digitalWrite(us_trig, LOW);

  duration = pulseIn(us_echo, INPUT);
  distance = duration * 0.0343 * 0.5;
  Serial.println(distance);
  return distance;
}

float weight() {
  return 404.404;
}

