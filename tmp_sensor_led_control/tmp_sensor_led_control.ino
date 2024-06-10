// A0 핀에서 TMP35 센서 값을 읽고, 4번 핀에 연결된 LED를 특정 조건에 켜는 코드

int ledPin = 4;
int tmp_sensor = A0;
float voltage;
float temperature;
int sensor_voltage;

void setup() {
  // 시리얼 통신을 시작합니다.
  Serial.begin(9600);
  pinMode(tmp_sensor, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  sensor_voltage = analogRead(tmp_sensor);
  voltage = sensor_voltage * 5.0 / 1023.0;
  temperature = voltage / 0.01;

  Serial.print("value: ");
  Serial.print(sensor_voltage);
  Serial.print(" voltage: ");
  Serial.println(voltage);
  Serial.print("Temperture: ");
  Serial.println(temperature);


  if (temperature > 25) {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED ON");
  }
  else {
    digitalWrite(ledPin, LOW);
    Serial.println("LED OFF");
  }
  // 잠시 기다립니다.
  delay(500);
}
