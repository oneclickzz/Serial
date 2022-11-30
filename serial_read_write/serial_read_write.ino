#include <Servo.h> 

int SERVO_PIN = 9;

Servo servo;

void setup() {
  
  Serial.begin(9600);
  servo.attach(SERVO_PIN);

  for (int angle=0; angle<180; angle++) {
    servo.write(angle);
    delay(10);
  }

  servo.write(0);
}

void loop() {

  //서보모터의 명령을 파악
  String cmd = serialRead();
  //cmd 는 "" 값을 기본으로 한다..

  if (cmd == "") {
    return;
  }
  
  int angle = cmd.toInt();

// 여기시점에 angle이 ? >= 0 숫자


  //명령에 따른 동작
//  int angle = 0;
  servo.write(angle);
  delay(200);

  //처리된 결과를 출력
  serialWrite(cmd);

}

String serialRead() {
  String str = "";

//  while(true) {
//    char c = Serial.read();
//    if (c == '\0') {
//      break;
//    }
//    str.concat(c);
//  }
  
  while(Serial.available()) {
    char c = Serial.read();
//    String c = Serial.readString();
    str.concat(c);
    delay(5);
  }
  return str;
}
void serialWrite(String str) {
  // 비어있거나 null인 문자열은 통신금지
  if (str == NULL || str.length() <= 0) {return;}

  Serial.print("서보모터각도: ");

  for (int i=0;i<str.length();i++) {
    Serial.print(str.charAt(i));
  }
//  Serial.print(str);
//  Serial.write(64);
  Serial.print('\n');
}
