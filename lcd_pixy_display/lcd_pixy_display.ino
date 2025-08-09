//
// LCD와 Pixy2를 연동하여 감지된 객체 정보를 표시하는 프로그램
// 첫 번째 블록의 sig, x, y, age 값을 LCD에 출력
// 1초마다 갱신
//

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Pixy2.h>

// LCD 초기화 (I2C 주소: 0x27, 16x2 디스플레이)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pixy2 객체 생성
Pixy2 pixy;

// 타이밍 변수
unsigned long previousMillis = 0;
const long interval = 1000; // 1초 간격

void setup()
{
  // 시리얼 통신 시작
  Serial.begin(115200);
  Serial.println("LCD Pixy Display Starting...");
  
  // LCD 초기화
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  // 초기 메시지 표시
  lcd.setCursor(0, 0);
  lcd.print("Pixy2 Display");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  
  // Pixy2 초기화
  pixy.init();
  
  delay(2000); // 초기화 대기
  lcd.clear();
}

void loop()
{
  unsigned long currentMillis = millis();
  
  // 1초마다 실행
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    // 블록 감지
    pixy.ccc.getBlocks();
    
    // LCD 클리어
    lcd.clear();
    
    if (pixy.ccc.numBlocks > 0) {
      // 감지된 블록이 있는 경우
      Serial.print("Detected ");
      Serial.println(pixy.ccc.numBlocks);
      
      // 첫 번째 블록 정보 가져오기
      Block block = pixy.ccc.blocks[0];
      
      // 첫 번째 줄: sig와 x 값 표시
      lcd.setCursor(0, 0);
      lcd.print("S:");
      lcd.print(block.m_signature);
      lcd.print(" X:");
      lcd.print(block.m_x);
      
      // 두 번째 줄: y와 age 값 표시
      lcd.setCursor(0, 1);
      lcd.print("Y:");
      lcd.print(block.m_y);
      lcd.print(" A:");
      lcd.print(block.m_age);
      
      // 시리얼로도 출력
      Serial.print("Block 0: sig:");
      Serial.print(block.m_signature);
      Serial.print(" x:");
      Serial.print(block.m_x);
      Serial.print(" y:");
      Serial.print(block.m_y);
      Serial.print(" age:");
      Serial.println(block.m_age);
      
    } else {
      // 감지된 블록이 없는 경우
      lcd.setCursor(0, 0);
      lcd.print("No blocks");
      lcd.setCursor(0, 1);
      lcd.print("detected");
      
      Serial.println("No blocks detected");
    }
  }
}
