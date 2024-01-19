int toggle, tombol1, tombol2, nilai;

void setup() {
  // put your setup code here, to run once:
  pinMode(D12, OUTPUT);
  pinMode(D13, OUTPUT);
  pinMode(D3, INPUT);
  pinMode(D2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  nilai=analogRead(A0);
  tombol1=digitalRead(D3);
  tombol2=digitalRead(D2);
  if(tombol1==LOW) {
    delay(500);
    toggle = 1;
  }
  if(tombol2==LOW) {
    delay(500);
    toggle = 2;
  }

  if(toggle==1) {
    digitalWrite(D12, HIGH);
    digitalWrite(D13, LOW);
    analogWrite(D9, nilai/4);
    analogWrite(D10, 0);
  }else if(toggle==2) {
    digitalWrite(D12, LOW);
    digitalWrite(D13, HIGH);
    analogWrite(D9, 0);
    analogWrite(D10, nilai/4);
  }else {
    digitalWrite(D12, LOW);
    digitalWrite(D13, LOW);
    analogWrite(D9, 0);
    analogWrite(D10, 0);
  }
  analogWrite(D11, 0);
}
