// A0 핀에서 가변 저항의 값을 읽고, 10번 핀에 연결된 LED의 밝기를 제어하는 코드

// LED가 연결된 핀 번호
const int ledPin = 10;

void setup() {
  // 시리얼 통신을 시작합니다.
  Serial.begin(9600);
}

void loop() {
  // A0 핀에서 아날로그 값을 읽습니다.
  int sensorValue = analogRead(A0);

  // 가변 저항의 값에 따라 LED의 밝기를 조절합니다.
  int brightness = map(sensorValue, 190, 700, 0, 255);
  if (brightness < 0) {
    brightness = 0;
  } else if (brightness > 255) {
    brightness = 255;
  }
  analogWrite(ledPin, brightness);
  // 읽은 값을 시리얼 모니터에 출력합니다.
  Serial.print("가변 저항 값: ");
  Serial.print(sensorValue);
  Serial.print("  LED 레벨: ");
  Serial.println(brightness);

  // 잠시 기다립니다.
  delay(50);
}
