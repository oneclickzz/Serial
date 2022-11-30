void setup() {
  Serial.begin(9600); //보드레이트

  
}

void loop() {

  for (int i=0;i<10;i++) {
    Serial.print('a');
    delay(200);
  }

  Serial.println();

//  Serial.print('\0');

  delay(1000);
  
  Serial.print('q');
  Serial.println();
}
