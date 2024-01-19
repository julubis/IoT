#define PERMENIT 1
#define PERJAM 60
#define PERHARI 1440

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
ESP8266WiFiMulti WiFiMulti;

const char* ssid=APNAME;
const char* password= PASSWORD;
String apikey=APIKEY;
const char* serverName = "http://www.pemantauan.com/submission/";
unsigned long counting;

void WiFiConnect() {
  delay(3000);
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(ssid, password);
  Serial.println("Connecting");
  while(WiFiMulti.run() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network! IP address: ");
  Serial.println(WiFi.localIP());
}

void aktifkanPemantauan(int frekuensi,float value1,float value2,float value3) {
  String obyek1=KODE_SENSOR1;
  String obyek2=KODE_SENSOR2;
  String obyek3=KODE_SENSOR3;
  int writeTimeRequired=60000;
  if ((millis() - counting) > frekuensi*writeTimeRequired) {
    if(WiFiMulti.run()== WL_CONNECTED){
      WiFiClient client;
      HTTPClient http;
      http.begin(client, serverName);
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");
      String httpRequestData = "apikey=" + apikey;
      httpRequestData = httpRequestData + "&obyek1=" + obyek1;
      httpRequestData = httpRequestData + "&value1=" + value1;
      httpRequestData = httpRequestData + "&obyek2=" + obyek2;
      httpRequestData = httpRequestData + "&value2=" + value2;
      httpRequestData = httpRequestData + "&obyek3=" + obyek3;
      httpRequestData = httpRequestData + "&value3=" + value3;
      int httpResponseCode = http.POST(httpRequestData);
      if (httpResponseCode > 0) {
        Serial.printf("Mengirim data... code: %d\n", httpResponseCode);
        if (httpResponseCode == HTTP_CODE_OK) {
          const String& payload = http.getString();
          Serial.print("Respon server: ");
          Serial.println(payload);
        }
      } else {
        Serial.printf("Mengirim data... gagal, error: %s\n", http.errorToString(httpResponseCode).c_str());
      }
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    counting = millis();
  }
 }
  
