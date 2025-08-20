/*
  웹캠 객체 탐지 프로젝트와 연동되는 아두이노 스케치

  기능:
  - 웹 브라우저로부터 'person : 숫자' 형식의 시리얼 데이터를 수신합니다.
  - 사람 수(person)에 따라 LED를 제어합니다.
    - 0명: 모든 LED 끔
    - 1명: 빨간색 LED 켬 (3번 핀)
    - 2명 이상: 파란색 LED 켬 (4번 핀)

  연결:
  - 빨간색 LED: 디지털 3번 핀
  - 파란색 LED: 디지털 4번 핀
*/

// LED 핀 번호를 상수로 정의하여 가독성과 유지보수성을 높입니다.
const int RED_LED_PIN = 3;
const int BLUE_LED_PIN = 4;

void setup() {
  // 시리얼 통신을 9600 bps로 시작합니다.
  // 웹 코드의 port.open({ baudRate: 9600 }) 설정과 일치해야 합니다.
  Serial.begin(9600);

  // LED 핀들을 출력(OUTPUT) 모드로 설정합니다.
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);

  // 프로그램 시작 시 모든 LED를 끈 상태로 초기화합니다.
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(BLUE_LED_PIN, LOW);

  // 아두이노가 준비되었음을 시리얼 모니터에 출력합니다.
  Serial.println("Arduino is ready. Waiting for data...");
}

void loop() {
  // 시리얼 버퍼에 읽을 데이터가 있는지 확인합니다.
  if (Serial.available() > 0) {
    // '\n' (줄바꿈) 문자를 만날 때까지 문자열을 읽어옵니다.
    // JavaScript 코드에서 `line + '\r\n'`으로 보내므로 정상적으로 수신됩니다.
    String receivedString = Serial.readStringUntil('\n');

    // 수신된 데이터가 "person"으로 시작하는지 확인합니다.
    // 다른 객체("cat", "dog" 등)의 데이터는 무시합니다.
    if (receivedString.startsWith("person")) {
      
      // 콜론(:) 문자의 위치를 찾습니다.
      int colonIndex = receivedString.indexOf(':');
      
      // 콜론이 문자열 내에 존재하는 경우
      if (colonIndex != -1) {
        // 콜론 다음 위치부터 문자열을 잘라내고, 앞뒤 공백을 제거한 후 정수로 변환합니다.
        // 예: "person : 2" -> " 2" -> "2" -> 2
        String countString = receivedString.substring(colonIndex + 1);
        countString.trim();
        int personCount = countString.toInt();

        // 감지된 사람 수에 따른 LED 제어 로직
        if (personCount == 0) {
          // 사람이 없으면 모든 LED를 끕니다.
          digitalWrite(RED_LED_PIN, LOW);
          digitalWrite(BLUE_LED_PIN, LOW);
        } else if (personCount == 1) {
          // 사람이 1명이면 빨간 LED만 켭니다.
          digitalWrite(RED_LED_PIN, HIGH);
          digitalWrite(BLUE_LED_PIN, LOW);
        } else { // personCount >= 2
          // 사람이 2명 이상이면 파란 LED만 켭니다.
          digitalWrite(RED_LED_PIN, LOW);
          digitalWrite(BLUE_LED_PIN, HIGH);
        }
      }
    }
  }
}