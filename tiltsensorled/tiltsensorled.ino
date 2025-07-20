int tilt = 3;

void setup() {
  Serial.begin(9600);      // 시리얼 통신을 시작, 통신속도는 (9600)
  pinMode(3, INPUT);       // 3번 핀을 입력으로 설정
  pinMode(4, OUTPUT);      // 4번 핀을 출력으로 설정
}

void loop() {
  int a = digitalRead(tilt);  // 디지털 3번 핀의 신호를 읽어 변수 a에 저장

  if (a == HIGH) {            // a가 HIGH (센서가 기울어짐)이면
    Serial.println("ball UP");  // 시리얼 모니터에 "ball UP" 출력
    digitalWrite(4, HIGH);    // 4번 핀을 HIGH로 설정
    delay(1000);              // 1초간 대기
  }
  else {                      // a가 HIGH가 아니면 (센서가 평평함)
    Serial.println("ball DOWN"); // 시리얼 모니터에 "ball DOWN" 출력
    digitalWrite(4, LOW);     // 4번 핀을 LOW로 설정
    delay(1000);              // 1초간 대기
  }
}