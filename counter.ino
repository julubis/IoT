int bilangan, tombol1, tombol2;

void setup() {
  // put your setup code here, to run once:
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  tombol1 = digitalRead(D2);
  tombol2 = digitalRead(D3);
  if(tombol1==LOW && bilangan < 10) {
    delay(500);
    bilangan++;
    Serial.println(bilangan);
  }
  if(tombol2==LOW && bilangan > 0) {
    delay(500);
    bilangan--;
    Serial.println(bilangan);
  }
}
