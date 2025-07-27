// 아두이노 스케치: 배열 값 콘솔 출력

// 정수형 배열 선언 및 초기화
// 여기에 원하는 정수 값들을 넣어주세요.
int myNumbers[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

// 배열의 크기(요소의 개수)를 계산합니다.
// sizeof(myNumbers)는 배열 전체의 바이트 크기,
// sizeof(myNumbers[0])는 배열 요소 하나(int)의 바이트 크기입니다.
const int arraySize = sizeof(myNumbers) / sizeof(myNumbers[0]);

void setup() {
  Serial.begin(9600); // 시리얼 통신 시작 (보드레이트 9600)

  Serial.println("--- 배열 요소 출력 시작 ---");

  // for 루프를 사용하여 배열의 모든 요소를 순회하며 출력합니다.
  // 인덱스는 0부터 (arraySize - 1)까지 증가합니다.
  for (int i = 0; i < arraySize; i++) {
    Serial.print("myNumbers["); // 배열 이름과 대괄호 출력
    Serial.print(i);            // 현재 인덱스 출력
    Serial.print("] = ");       // 등호 출력
    Serial.println(myNumbers[i]); // 해당 인덱스의 배열 값 출력 후 줄 바꿈
    delay(100); // 각 출력 사이에 약간의 지연 시간을 둡니다 (선택 사항)
  }

  Serial.println("--- 배열 요소 출력 완료 ---");
}

void loop() {
  // 배열 값 출력은 setup()에서 한 번만 이루어지므로,
  // loop() 함수에서는 특별히 할 작업이 없습니다.
  // 만약 loop()에서 반복적으로 출력하고 싶다면 setup()의 코드를 loop()로 옮기면 됩니다.
}