// 수동 부저를 2번 디지털 핀에 연결
const int buzzerPin = 2;

// 음계별 주파수 정의
#define NOTE_C4  262 // 도
#define NOTE_D4  294 // 레
#define NOTE_E4  330 // 미
#define NOTE_F4  349 // 파 (이번 노래에는 사용되지 않지만 참고용)
#define NOTE_G4  392 // 솔 (이번 노래에는 사용되지 않지만 참고용)

// '떴다 떴다 비행기' 멜로디 (음표별 주파수)
int melody[] = {
  // 떴다 떴다 비행기
  NOTE_E4, NOTE_D4, NOTE_C4, NOTE_D4,
  NOTE_E4, NOTE_E4, NOTE_E4, 0, // '기' 뒤에 짧은 쉼표

  // 날아라 날아라
  NOTE_D4, NOTE_D4, NOTE_D4, 0, // '라' 뒤에 짧은 쉼표

  // 높이 높이 날아라
  NOTE_E4, NOTE_E4, NOTE_E4, 0, // '라' 뒤에 짧은 쉼표

  // 우리 비행기
  NOTE_E4, NOTE_D4, NOTE_C4, NOTE_D4,
  NOTE_E4, NOTE_E4, NOTE_E4, 0, // '기' 뒤에 짧은 쉼표

  // 우리 비행기 (마지막 부분)
  NOTE_D4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_C4, 0 // '레레미레도' 마무리 및 긴 쉼표
};

// 각 음표의 지속 시간 (숫자가 작을수록 짧은 음표, 클수록 긴 음표)
// 예를 들어, 4는 4분음표, 2는 2분음표에 해당합니다.
int durations[] = {
  // 떴다 떴다 비행기
  4, 4, 4, 4,
  4, 4, 2, 8, // '미'가 2분음표, 쉼표는 8분쉼표

  // 날아라 날아라
  4, 4, 2, 8, // '레'가 2분음표, 쉼표는 8분쉼표

  // 높이 높이 날아라
  4, 4, 2, 8, // '미'가 2분음표, 쉼표는 8분쉼표

  // 우리 비행기
  4, 4, 4, 4,
  4, 4, 2, 8, // '미'가 2분음표, 쉼표는 8분쉼표

  // 우리 비행기 (마지막 부분)
  4, 4, 4, 4, 1, 1 // 마지막 '도'는 온음표로 길게, 뒤는 긴 쉼표
};

void setup() {
  pinMode(buzzerPin, OUTPUT); // 부저 핀을 출력으로 설정
}

void loop() {
  // 멜로디의 길이를 계산합니다.
  int numberOfNotes = sizeof(melody) / sizeof(melody[0]);

  // 각 음표를 순서대로 연주합니다.
  for (int thisNote = 0; thisNote < numberOfNotes; thisNote++) {
    // 음표의 길이를 계산합니다. (1000ms / 박자수)
    // 예를 들어, durations[thisNote]가 4면 250ms 동안 소리가 납니다.
    int noteDuration = 1000 / durations[thisNote]; 
    
    // 현재 음표가 쉼표(0)가 아닐 때만 소리를 냅니다.
    if (melody[thisNote] != 0) {
      tone(buzzerPin, melody[thisNote], noteDuration);
    } else {
      // 쉼표일 때는 소리를 내지 않고 대기합니다.
      noTone(buzzerPin);
    }

    // 다음 음으로 넘어가기 전 짧은 대기 시간을 둡니다. (음표와 음표 사이 간격)
    // noteDuration의 30% 정도를 쉬는 시간으로 설정하여 음이 명확하게 들리도록 합니다.
    int pauseBetweenNotes = noteDuration * 1.30; 
    delay(pauseBetweenNotes);

    // 혹시 tone() 함수가 아직 끝나지 않았을 경우를 대비하여 소리를 확실히 멈춥니다.
    noTone(buzzerPin);
  }

  // 한 번 노래를 연주한 후 잠시 멈춥니다.
  delay(3000); // 3초 동안 대기 후 다시 노래를 연주합니다.
}