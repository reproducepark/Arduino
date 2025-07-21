int echoPin = 7;
int trigPin = 8;
int ledPin = 4; // 4번 핀을 LED 출력 핀으로 설정

void setup() {
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledPin, OUTPUT); // LED 핀을 출력으로 설정
}

void loop() {
  long duration, distance;

  // 트리거 핀으로 펄스를 내보냄
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // 10^-6초 = 1 마이크로초
  // 2 * 10 ^ -6초 = 2 마이크로초
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 에코 핀으로 펄스 길이를 측정
  duration = pulseIn(echoPin, HIGH);

  // 거리 계산 (밀리미터 단위, 음속 340m/s 사용)
  // 거리 = (음속 * 시간) / 2
  // 음속: 340 m/s = 0.34 mm/us
  distance = (duration * 0.34) / 2;

  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println("mm\n");

  // 거리가 50mm 이하면 LED 켜기, 아니면 끄기
  if (distance <= 50) {
    digitalWrite(ledPin, HIGH); // LED 켜기
  } else {
    digitalWrite(ledPin, LOW);  // LED 끄기
  }

  delay(3000); // 3초 대기
}