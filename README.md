# 교육용 아두이노 코드 모음 📚

이 레포지토리는 아두이노 학습을 위한 다양한 예제 코드를 모아놓은 교육용 프로젝트입니다. 초보자부터 중급자까지 단계별로 아두이노를 학습할 수 있도록 구성되어 있습니다.

## 📋 목차

- [기본 프로그래밍](#기본-프로그래밍)
- [센서 활용](#센서-활용)
- [액추에이터 제어](#액추에이터-제어)
- [디스플레이](#디스플레이)
- [고급 프로젝트](#고급-프로젝트)
- [설치 및 사용법](#설치-및-사용법)

## 🔧 기본 프로그래밍

### array
**배열과 반복문 학습**
- **파일**: `array/array.ino`
- **내용**: 정수형 배열을 선언하고 for문을 사용하여 모든 요소를 시리얼 모니터에 출력
- **학습 목표**: 배열 선언, 초기화, for문 활용
- **필요 부품**: 아두이노 보드

### if_state_arduino
**조건문과 시리얼 통신**
- **파일**: `if_state_arduino/if_state_arduino.ino`
- **내용**: 시리얼 모니터로 정수를 입력받아 양수/음수/0을 판별
- **학습 목표**: if-else 조건문, 시리얼 통신, 사용자 입력 처리
- **필요 부품**: 아두이노 보드

### intfloatdiff
**데이터 타입의 차이**
- **파일**: `intfloatdiff/intfloatdiff.ino`
- **내용**: 정수형과 실수형 나눗셈의 차이점을 비교하여 출력
- **학습 목표**: int와 float 타입의 차이, 형변환
- **필요 부품**: 아두이노 보드

## 💡 LED 제어

### simple3led
**RGB LED 기본 제어**
- **파일**: `simple3led/simple3led.ino`
- **내용**: RGB LED를 사용하여 다양한 색상을 순차적으로 표시
- **학습 목표**: PWM 제어, analogWrite 함수, 색상 혼합
- **필요 부품**: 아두이노 보드, RGB LED, 저항

### switch3led
**스위치와 RGB LED 연동**
- **파일**: `switch3led/switch3led.ino`
- **내용**: 버튼을 누르면 RGB LED가 다양한 색상으로 변화
- **학습 목표**: 디지털 입력, 풀업 저항, 인터랙티브 제어
- **필요 부품**: 아두이노 보드, RGB LED, 푸시 버튼, 저항

### tiltsensorled
**기울기 센서와 LED**
- **파일**: `tiltsensorled/tiltsensorled.ino`
- **내용**: 기울기 센서의 상태에 따라 LED를 제어
- **학습 목표**: 디지털 센서 읽기, 조건부 LED 제어
- **필요 부품**: 아두이노 보드, 기울기 센서, LED, 저항

## 🎵 사운드

### buzzer
**멜로디 연주**
- **파일**: `buzzer/buzzer.ino`
- **내용**: 수동 부저로 "떴다 떴다 비행기" 멜로디 연주
- **학습 목표**: tone 함수, 음계와 주파수, 배열 활용
- **필요 부품**: 아두이노 보드, 수동 부저

## 🌡️ 센서 활용

### temp_sensor
**온도 센서 (LM35)**
- **파일**: `temp_sensor/temp_sensor.ino`
- **내용**: LM35 온도 센서로 온도를 측정하고 임계값에 따라 LED 제어
- **학습 목표**: 아날로그 센서 읽기, 센서 값 변환, 조건부 제어
- **필요 부품**: 아두이노 보드, LM35 온도 센서, LED, 저항

### temphum
**온습도 센서 (DHT11)**
- **파일**: `temphum/temphum.ino`
- **내용**: DHT11 센서로 온도와 습도를 동시에 측정
- **학습 목표**: 디지털 센서 라이브러리 사용, 복합 센서 데이터 처리
- **필요 부품**: 아두이노 보드, DHT11 센서
- **라이브러리**: DHT sensor library

### cds_sensor
**조도 센서 (CDS)**
- **파일**: `cds_sensor/cds_sensor.ino`
- **내용**: 조도 센서로 주변 밝기를 측정하고 LED를 자동 제어
- **학습 목표**: 아날로그 센서, 환경 센싱, 자동화 제어
- **필요 부품**: 아두이노 보드, CDS 조도 센서, LED, 저항

### ultrasonic_sensor
**초음파 거리 센서 (HC-SR04)**
- **파일**: `ultrasonic_sensor/ultrasonic_sensor.ino`
- **내용**: 초음파 센서로 거리를 측정하고 근접시 LED 점등
- **학습 목표**: 디지털 핀 제어, 시간 측정, 물리 공식 적용
- **필요 부품**: 아두이노 보드, HC-SR04 초음파 센서, LED, 저항

## 🔄 액추에이터 제어

### servo_motor
**서보 모터 제어**
- **파일**: `servo_motor/servo_motor.ino`
- **내용**: 서보 모터를 90도와 180도 사이에서 반복 회전
- **학습 목표**: PWM 신호, 서보 라이브러리 사용, 각도 제어
- **필요 부품**: 아두이노 보드, 서보 모터
- **라이브러리**: Servo

## 📺 디스플레이

### lcd_simple
**LCD 기본 출력**
- **파일**: `lcd_simple/lcd_simple.ino`
- **내용**: I2C LCD에 "Hello, world!" 메시지 표시
- **학습 목표**: I2C 통신, LCD 라이브러리 기본 사용법
- **필요 부품**: 아두이노 보드, 16x2 I2C LCD
- **라이브러리**: LiquidCrystal_I2C

### lcd_elapsed_time
**LCD 동적 표시**
- **파일**: `lcd_elapsed_time/lcd_elapsed_time.ino`
- **내용**: LCD에 인사말과 경과 시간을 번갈아 표시
- **학습 목표**: 시간 계산, 동적 디스플레이 갱신, 상태 전환
- **필요 부품**: 아두이노 보드, 16x2 I2C LCD
- **라이브러리**: LiquidCrystal_I2C

## 🤖 고급 프로젝트

### ccc_hello_world
**Pixy2 카메라 모듈**
- **파일**: `ccc_hello_world/ccc_hello_world.ino`
- **내용**: Pixy2 카메라로 색상 감지 및 객체 추적
- **학습 목표**: 컴퓨터 비전, SPI 통신, 고급 센서 활용
- **필요 부품**: 아두이노 보드, Pixy2 카메라 모듈
- **라이브러리**: Pixy2

## 🛠 설치 및 사용법

### 1. 아두이노 IDE 설치
- [아두이노 공식 웹사이트](https://www.arduino.cc/en/software)에서 IDE를 다운로드하고 설치하세요.

### 2. 필요한 라이브러리 설치
각 프로젝트에 필요한 라이브러리를 설치하세요:

- **DHT sensor library**: 아두이노 IDE의 라이브러리 매니저에서 "DHT sensor library" 검색 후 설치
- **LiquidCrystal_I2C**: 라이브러리 매니저에서 "LiquidCrystal_I2C" 검색 후 설치
- **Servo**: 아두이노 IDE에 기본 포함
- **Pixy2**: [Pixy2 Arduino library](https://github.com/charmedlabs/pixy2) 다운로드 후 설치

### 3. 회로 연결
각 프로젝트 폴더의 코드 주석을 참고하여 부품을 올바르게 연결하세요.

### 4. 코드 업로드
1. 아두이노 보드를 컴퓨터에 연결
2. 아두이노 IDE에서 올바른 보드와 포트 선택
3. 원하는 프로젝트 폴더의 `.ino` 파일을 열기
4. 컴파일 후 아두이노에 업로드

## 📖 학습 순서 추천

### 초급 (프로그래밍 기초)
1. `if_state_arduino` - 조건문과 시리얼 통신
2. `array` - 배열과 반복문
3. `intfloatdiff` - 데이터 타입 이해

### 중급 (센서와 액추에이터)
4. `simple3led` - LED 제어 기초
5. `switch3led` - 입력과 출력 연동
6. `buzzer` - 사운드 제어
7. `temp_sensor` - 아날로그 센서
8. `cds_sensor` - 환경 센싱
9. `servo_motor` - 모터 제어

### 고급 (디스플레이와 복합 센서)
10. `lcd_simple` - 디스플레이 기초
11. `lcd_elapsed_time` - 동적 디스플레이
12. `temphum` - 디지털 센서 라이브러리
13. `ultrasonic_sensor` - 거리 측정
14. `tiltsensorled` - 기울기 센서
15. `ccc_hello_world` - 고급 비전 센서

---

**Happy Arduino Coding! 🚀**
