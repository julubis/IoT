int tombol;

void setup() {
  // put your setup code here, to run once:
  pinMode(D12, OUTPUT);
  pinMode(D3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tombol = digitalRead(D3);
  if(tombol==LOW) {
    digitalWrite(D12, HIGH);
  } else {
    digitalWrite(D12, LOW);
  }
}
