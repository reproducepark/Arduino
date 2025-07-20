// 아두이노 스케치

void setup() {
  Serial.begin(9600); // 시리얼 통신 시작 (보드레이트 9600)
  Serial.println("정수를 입력하세요 (시리얼 모니터에 입력 후 Enter):");
}

void loop() {
  if (Serial.available() > 0) { // 시리얼 포트에 데이터가 들어왔는지 확인
    int number = Serial.parseInt(); // 시리얼 포트에서 정수 값을 읽어옴

    if (Serial.peek() == '\n' || Serial.peek() == '\r') { // 다음 문자가 개행 문자(Enter)인지 확인
      // 입력 버퍼 비우기 (남아있는 개행 문자 처리)
      while (Serial.available()) {
        Serial.read();
      }

      // 조건문 시작
      if (number > 0) {
        Serial.print(number);
        Serial.println("는 양수입니다.");
      } else if (number < 0) {
        Serial.print(number);
        Serial.println("는 음수입니다.");
      } else {
        Serial.print(number);
        Serial.println("는 0입니다.");
      }
      Serial.println("\n정수를 다시 입력하세요:"); // 다음 입력을 위한 안내 메시지
    }
  }
}