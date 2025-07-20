void setup() {
  Serial.begin(9600); // 시리얼 통신 시작
  Serial.println("--- 나눗셈 결과 비교 ---");

  // 정수 나눗셈
  int num1_int = 10;
  int num2_int = 3;
  int result_int = num1_int / num2_int; // 정수 / 정수
  
  Serial.print("\n[정수 나눗셈]\n");
  Serial.print(num1_int);
  Serial.print(" / ");
  Serial.print(num2_int);
  Serial.print(" = ");
  Serial.println(result_int); // 결과: 3 (소수점 버림)
  Serial.println("-> 정수끼리의 나눗셈은 소수점 이하를 버리고 정수 부분만 남깁니다.");

  // 실수 나눗셈 (방법 1: 피연산자 중 하나를 float으로 명시적 형변환)
  int num3_int = 10;
  int num4_int = 3;
  float result_float1 = (float)num3_int / num4_int; // (float)정수 / 정수
  
  Serial.print("\n[실수 나눗셈 - 방법 1: 형변환 사용]\n");
  Serial.print("(float)");
  Serial.print(num3_int);
  Serial.print(" / ");
  Serial.print(num4_int);
  Serial.print(" = ");
  Serial.println(result_float1, 4); // 소수점 4자리까지 출력
  Serial.println("-> 한쪽을 실수형으로 바꾸면 실수 나눗셈이 됩니다.");

  // 실수 나눗셈 (방법 2: 둘 다 float 변수로 선언)
  float num5_float = 10.0; // 소수점을 붙여 float으로 선언
  float num6_float = 3.0;  // 소수점을 붙여 float으로 선언
  float result_float2 = num5_float / num6_float; // 실수 / 실수
  
  Serial.print("\n[실수 나눗셈 - 방법 2: 변수 선언 시 float 사용]\n");
  Serial.print(num5_float, 1); // 소수점 1자리까지 출력
  Serial.print(" / ");
  Serial.print(num6_float, 1); // 소수점 1자리까지 출력
  Serial.print(" = ");
  Serial.println(result_float2, 4); // 소수점 4자리까지 출력
  Serial.println("-> 실수형 변수끼리의 나눗셈은 정확한 실수 결과를 얻습니다.");

  Serial.println("\n------------------------------");
  Serial.println("프로그램이 종료되었습니다. (Loop는 더 이상 실행되지 않습니다.)");
}

void loop() {
  // setup()에서 모든 것을 처리했으므로, loop()에서는 아무것도 하지 않습니다.
}