#define APNAME "WIFI_AP_NAME"
#define PASSWORD "wifi_password"
#define APIKEY "api-key"
#define KODE_SENSOR1 "1"
#define KODE_SENSOR2 "2"
#define KODE_SENSOR3 "6"
#include <DHT.h>
#include "pemantauan.h"
DHT dht(D4, DHT11);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFiConnect();
  dht.begin();
}
void loop() {
  // put your main code here, to run repeatedly:
  float sensor1=dht.readTemperature();
  float sensor2=dht.readHumidity();
  float sensor3=0+random(2);
  aktifkanPemantauan(PERMENIT,sensor1,sensor2,sensor3);
}
