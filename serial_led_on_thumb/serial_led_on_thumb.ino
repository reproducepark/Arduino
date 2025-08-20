/*
  웹 기반 제스처 인식을 통한 LED 제어
  - 웹 페이지로부터 시리얼 통신으로 제스처 데이터를 수신합니다.
  - "Thumb_Up" 수신 시: 3번 핀 LED 켜기
  - "Thumb_Down" 수신 시: 4번 핀 LED 켜기
  - 그 외: 모든 LED 끄기
*/

// LED가 연결된 핀 번호를 상수로 정의합니다.
const int thumbUpLedPin = 3;
const int thumbDownLedPin = 4;

void setup() {
  // 시리얼 통신을 시작합니다. 전송 속도(Baud rate)는 웹 코드와 동일하게 9600으로 설정합니다.
  Serial.begin(9600);

  // LED 핀들을 출력(OUTPUT) 모드로 설정합니다.
  pinMode(thumbUpLedPin, OUTPUT);
  pinMode(thumbDownLedPin, OUTPUT);

  // 프로그램 시작 시 모든 LED를 끈 상태로 초기화합니다.
  digitalWrite(thumbUpLedPin, LOW);
  digitalWrite(thumbDownLedPin, LOW);

  // 아두이노가 준비되었음을 시리얼 모니터에 출력합니다 (디버깅용).
  Serial.println("Arduino is ready. Waiting for gesture data...");
}

void loop() {
  // 시리얼 버퍼에 수신된 데이터가 있는지 확인합니다.
  if (Serial.available() > 0) {
    // 줄바꿈 문자(\n)를 만날 때까지 들어온 데이터를 하나의 문자열로 읽습니다.
    String receivedData = Serial.readStringUntil('\n');

    // 문자열 앞뒤의 불필요한 공백이나 제어 문자를 제거합니다.
    receivedData.trim();

    // 수신된 데이터에 "Thumb_Up" 문자열이 포함되어 있는지 확인합니다.
    // indexOf() 함수는 특정 문자열이 없으면 -1을 반환합니다.
    if (receivedData.indexOf("Thumb_Up") != -1) {
      // '엄지 올리기' 동작 감지
      digitalWrite(thumbUpLedPin, HIGH);  // 3번 핀 LED 켜기
      digitalWrite(thumbDownLedPin, LOW);   // 4번 핀 LED 끄기
      Serial.println("Received: Thumb_Up -> Pin 3 ON"); // 디버깅 메시지
    }
    // "Thumb_Up"이 아니라면 "Thumb_Down"이 포함되어 있는지 확인합니다.
    else if (receivedData.indexOf("Thumb_Down") != -1) {
      // '엄지 내리기' 동작 감지
      digitalWrite(thumbUpLedPin, LOW);    // 3번 핀 LED 끄기
      digitalWrite(thumbDownLedPin, HIGH); // 4번 핀 LED 켜기
      Serial.println("Received: Thumb_Down -> Pin 4 ON"); // 디버깅 메시지
    }
    // 두 제스처에 해당하지 않는 다른 데이터가 수신된 경우
    else {
      // 모든 LED를 끕니다.
      digitalWrite(thumbUpLedPin, LOW);
      digitalWrite(thumbDownLedPin, LOW);
    }
  }
}