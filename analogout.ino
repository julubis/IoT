int nilai;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  nilai=analogRead(A0);
  analogWrite(D9, nilai/4);
  analogWrite(D10, nilai/4);
  analogWrite(D11, nilai/4);
}
