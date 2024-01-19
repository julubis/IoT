char perintah;

void setup() {
  // put your setup code here, to run once:
  pinMode(D12, OUTPUT);
  pinMode(D13, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) {
    perintah=Serial.read();
    if(perintah=='M') {
      digitalWrite(D12, HIGH);
    }
    if(perintah=='m') {
      digitalWrite(D12, LOW);
    }
    if(perintah=='B') {
      digitalWrite(D13, HIGH);
    }
    if(perintah=='b') {
      digitalWrite(D13, LOW);
    }
  }
}
