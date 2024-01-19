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
      Serial.println("Lampu merah telah dinyalakan");
    }
    if(perintah=='m') {
      digitalWrite(D12, LOW);
      Serial.println("Lampu merah telah dimatikan");
    }
    if(perintah=='B') {
      digitalWrite(D13, HIGH);
      Serial.println("Lampu biru telah dinyalakan");
    }
    if(perintah=='b') {
      digitalWrite(D13, LOW);
      Serial.println("Lampu biru telah dimatikan");
    }
  }
}
