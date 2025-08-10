// 16x2 LCD용 LiquidCrystal_I2C 라이브러리
#include <LiquidCrystal_I2C.h>

// 16x2 LCD의 I2C 주소는 보통 0x27 또는 0x3F입니다. 
// 사용 중인 LCD의 주소에 맞게 변경하세요.
LiquidCrystal_I2C lcd(0x27, 16, 2);  

// 시리얼 입력을 저장할 변수
String inputString = "";
bool stringComplete = false;  // 문자열 입력 완료 여부

void setup() {
  // 시리얼 통신 초기화 (9600 bps)
  Serial.begin(9600);
  
  // LCD 초기화
  lcd.init();      
  lcd.backlight(); 
  
  // 시작 메시지 표시
  lcd.setCursor(0, 0);
  lcd.print("Serial LCD Ready");
  lcd.setCursor(0, 1);
  lcd.print("Max 32 chars");
  
  // 시리얼 모니터에 안내 메시지 출력
  Serial.println("=== Serial to LCD Display ===");
  Serial.println("Send up to 32 characters");
  Serial.println("Auto-split into 2 lines (16 chars each)");
}

void loop() {
  // 시리얼 데이터가 있으면 읽기
  if (Serial.available()) {
    char inChar = (char)Serial.read();
    
    // 줄바꿈 문자가 오면 문자열 처리
    if (inChar == '\n') {
      stringComplete = true;
    } else if (inChar != '\r') {  // 캐리지 리턴은 무시
      inputString += inChar;
    }
  }
  
  // 문자열 입력이 완료되면 LCD에 표시
  if (stringComplete) {
    processInput();
    inputString = "";
    stringComplete = false;
  }
}

void processInput() {
  // 최대 32글자로 제한
  if (inputString.length() > 32) {
    inputString = inputString.substring(0, 32);
  }
  
  // 입력받은 문자열을 시리얼 모니터에 에코
  Serial.print("Received: ");
  Serial.println(inputString);
  
  // LCD 화면 지우기
  lcd.clear();
  
  // 첫 번째 줄 표시 (0~15번째 문자)
  lcd.setCursor(0, 0);
  if (inputString.length() > 0) {
    String line1 = inputString.substring(0, min(16, (int)inputString.length()));
    lcd.print(line1);
  }
  
  // 두 번째 줄 표시 (16~31번째 문자)
  if (inputString.length() > 16) {
    lcd.setCursor(0, 1);
    String line2 = inputString.substring(16);
    lcd.print(line2);
  }
  
  Serial.println("Displayed on LCD");
}
