int nilai;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  nilai=analogRead(A0);
  Serial.println(nilai);
  delay(100);
}
