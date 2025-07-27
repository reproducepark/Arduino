float temperature;  
int reading;  
int lm35Pin = A0;
int ledPin = 4; // 4번 핀을 LED 핀으로 설정합니다.

void setup()
{
  analogReference(INTERNAL);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); // LED 핀을 출력으로 설정합니다.
  delay(5000);
}

void loop()
{
  reading = analogRead(lm35Pin);
  
  // LM35는 10mV/°C의 비율로 전압을 출력합니다.
  // analogReference(INTERNAL)를 사용했으므로, 내부 기준 전압은 1.1V입니다.
  temperature = (reading * (1.1 / 1024.0)) * 100.0; // 아날로그 값을 온도로 변환

  Serial.print(temperature); 
  Serial.println(" degrees C");

  if (temperature > 33.0) { // 온도가 33도보다 높으면
    digitalWrite(ledPin, HIGH); // LED를 켭니다.
    Serial.println("LED ON"); // 시리얼 모니터에 "LED ON" 출력
  } else { // 그렇지 않으면
    digitalWrite(ledPin, LOW); // LED를 끕니다.
  }
  
  delay(1000);
}