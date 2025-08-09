// 16x2 LCD용 LiquidCrystal_I2C 라이브러리
#include <LiquidCrystal_I2C.h>

// 16x2 LCD의 I2C 주소는 보통 0x27 또는 0x3F입니다. 
// 사용 중인 LCD의 주소에 맞게 변경하세요.
LiquidCrystal_I2C lcd(0x27, 16, 2);  

// 텍스트를 전환하기 위한 변수
bool showHello = true;
unsigned long previousMillis = 0;
const long interval = 2000; // 2초마다 텍스트를 전환

void setup() {
  lcd.init();      // LCD 초기화
  lcd.backlight(); // 백라이트 켜기
}

void loop() {
  unsigned long currentMillis = millis();

  // 2초(interval)가 지났는지 확인
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // 화면을 지우고 텍스트를 전환
    lcd.clear();

    if (showHello) {
      // "Hello!" 메시지 표시
      lcd.setCursor(5, 0); // 첫 번째 줄 가운데
      lcd.print("Hello!");
      
      lcd.setCursor(0, 1); // 두 번째 줄 시작점
      lcd.print("Nice to meet you!");
    } else {
      // 경과된 시간 표시
      lcd.setCursor(2, 0); // 첫 번째 줄 가운데
      lcd.print("Elapsed Time"); // 'Current Time' -> 'Elapsed Time'으로 수정

      // 경과 시간을 분, 초로 계산
      unsigned long seconds = currentMillis / 1000;
      unsigned long minutes = seconds / 60;
      seconds %= 60;
      
      lcd.setCursor(5, 1); // 두 번째 줄 가운데
      lcd.print(minutes);
      lcd.print(":");
      // 초가 한 자리 수일 때 앞에 0을 붙여서 두 자리로 표시
      if (seconds < 10) {
        lcd.print("0");
      }
      lcd.print(seconds);
    }
    
    // 다음 루프를 위해 상태 전환
    showHello = !showHello;
  }
}