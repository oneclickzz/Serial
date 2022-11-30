
//String cmd = "";

void setup() {
  
  pinMode(13, OUTPUT);
  Serial.begin(9600); //보드레이트
}
void loop() {

//  cmd = "";

  while(Serial.available()) {
//    char c = Serial.read(); //1byte
//    cmd.concat(c);
//    cmd = cmd + String(c);

    String s = Serial.readString(); //1byte

//    if (cmd == "hello") {
    if (s == "안녕") {
      digitalWrite(13, HIGH);
      delay(1000);
      digitalWrite(13, LOW);
      delay(1000);
      digitalWrite(13, HIGH);
      delay(1000);
      digitalWrite(13, LOW);
      delay(1000);
    }

//    if (c == 'q') {
//      digitalWrite(13, HIGH);
//      delay(1000);
//      digitalWrite(13, LOW);
//      delay(1000);
//      digitalWrite(13, HIGH);
//      delay(1000);
//      digitalWrite(13, LOW);
//      delay(1000);
//    }
  }

//  delay(2000);
}
