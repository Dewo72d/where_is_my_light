#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "wifi_ssid";
const char* password = "wifi_password";

WiFiClient client;

int server_on = 0;
int is_send = 0;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n WiFi");


  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WIFI IS LIFE");
  } else {
    Serial.println("WiFi IS DEAD");
  }
}

void sendToServer() {
  HTTPClient http;

  if (http.begin(client, "http://www.google.com")) { //you can change this url to any site
    int httpCode = http.GET();
    http.end();

    if (httpCode > 0) {

      if (httpCode == HTTP_CODE_OK) {
        http.begin(client, "http://0.0.0.0:3001/light?&token=your_token"); //pasete your IP PORT and token from index.js 
        http.addHeader("Content-Type", "text/plain");
        http.POST("");
        http.end();
        Serial.println("SVETA >>>> ");
        is_send = 1;
      }
    } else {
      Serial.println("HTTP-NO INTERNET");
    }

  } else {
    Serial.println("CAN NOT GET SERVER");
  }
}



void loop() {
  HTTPClient http;

  if (server_on == 0) {
    http.begin(client, "http://0.0.0.0:3001/ping"); //pasete your IP PORT
    http.addHeader("Content-Type", "text/plain");
    http.GET();
    http.end();
    Serial.println("PING >>>> ");

    int httpCode = http.GET();
    if (httpCode == HTTP_CODE_OK) {
      server_on = 1;
    }

  } else if (server_on == 1 && is_send == 0) {
    sendToServer();
  }

  delay(15000); //15sec
}