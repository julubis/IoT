int tombol1, tombol2, toggle1, toggle2;

void setup() {
  // put your setup code here, to run once:
  pinMode(D12, OUTPUT);
  pinMode(D13, OUTPUT);
  pinMode(D3, INPUT);
  pinMode(D2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tombol1 = digitalRead(D3);
  tombol2 = digitalRead(D2);
  if(tombol1 == LOW) {
    delay(500);
    toggle1 = !toggle1;
  }
  if(tombol2 == LOW) {
    delay(500);
    toggle2 = !toggle2;
  }
  digitalWrite(D12, toggle1);
  digitalWrite(D13, toggle2);
}
