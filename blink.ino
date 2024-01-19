void setup() {
  // put your setup code here, to run once:
  pinMode(D12, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(D12, HIGH);
  delay(500);
  digitalWrite(D12, LOW);
  delay(500);
}
