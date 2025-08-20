/*
  사람 위치 기반 LED 제어
  
  기능:
  - 웹캠으로부터 'person:x1,y1|x2,y2' 형식의 시리얼 데이터를 수신합니다.
  - 한 명이라도 오른쪽 절반(x > 0.5)에 있으면 LED를 켭니다.
  - 좌표 시스템: (0,0)은 왼쪽 위, (1,1)은 오른쪽 아래
  
  연결:
  - LED: 디지털 13번 핀 (내장 LED)
*/

const int LED_PIN = 13;  // 내장 LED 핀 사용

void setup() {
  // 시리얼 통신을 9600 bps로 시작합니다.
  Serial.begin(9600);
  
  // LED 핀을 출력 모드로 설정합니다.
  pinMode(LED_PIN, OUTPUT);
  
  // 초기에는 LED를 끕니다.
  digitalWrite(LED_PIN, LOW);
  
  Serial.println("Arduino is ready. Waiting for person position data...");
}

void loop() {
  if (Serial.available() > 0) {
    String receivedString = Serial.readStringUntil('\n');
    receivedString.trim();
    
    // "person:"으로 시작하는지 확인
    if (receivedString.startsWith("person:")) {
      // "person:" 제거하고 좌표 부분만 추출
      String coordinates = receivedString.substring(7); // "person:" 길이는 7
      
      // 좌표 파싱 및 오른쪽 절반 검사
      bool personInRightHalf = checkPersonInRightHalf(coordinates);
      
      // LED 제어
      if (personInRightHalf) {
        digitalWrite(LED_PIN, HIGH);
        Serial.println("Person detected in right half - LED ON");
      } else {
        digitalWrite(LED_PIN, LOW);
        Serial.println("No person in right half - LED OFF");
      }
    }
  }
}

// 좌표 문자열을 파싱하여 오른쪽 절반에 사람이 있는지 확인하는 함수
bool checkPersonInRightHalf(String coordinates) {
  int startPos = 0;
  int pipePos = coordinates.indexOf('|', startPos);
  
  // 파이프(|)로 구분된 각 좌표 쌍을 검사
  while (startPos < coordinates.length()) {
    String coordinatePair;
    
    if (pipePos != -1) {
      coordinatePair = coordinates.substring(startPos, pipePos);
      startPos = pipePos + 1;
      pipePos = coordinates.indexOf('|', startPos);
    } else {
      coordinatePair = coordinates.substring(startPos);
      startPos = coordinates.length();
    }
    
    // 좌표 쌍에서 x, y 값 추출
    int commaPos = coordinatePair.indexOf(',');
    if (commaPos != -1) {
      String xStr = coordinatePair.substring(0, commaPos);
      float x = xStr.toFloat();
      
      // x 좌표가 0.5보다 크면 오른쪽 절반에 있음
      if (x > 0.5) {
        Serial.print("Person found in right half at x=");
        Serial.println(x);
        return true;
      }
    }
  }
  
  return false;
}
