int LED_1 = 2;
int LED_2 = 3;
int LED_3 = 4;
int LED_4 = 5;
int LED_5 = 6;
int pinBuzzer = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);

  Serial.begin(9600);
}



void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0/1023.0);
  Serial.println(voltage);
  
  for (int i = LED_1; i <= 6; i++) {
    digitalWrite(i, HIGH);
    digitalWrite((i + 1) % 6, HIGH);
    digitalWrite((i + 2) % 6, HIGH);
    digitalWrite((i + 3) % 6, HIGH);
    digitalWrite((i + 4) % 6, HIGH);
    digitalWrite(pinBuzzer, HIGH);
    delay(800);
    digitalWrite(i, LOW);
    digitalWrite((i + 1) % 6, LOW);
    digitalWrite((i + 2) % 6, LOW);
    digitalWrite((i + 3) % 6, LOW);
    digitalWrite((i + 4) % 6, LOW);
    digitalWrite(pinBuzzer, LOW);
  }

  delay(2000);

  for (int i = LED_1; i <= 6; i++) {
    digitalWrite(i, HIGH);
    digitalWrite(pinBuzzer, HIGH);
    delay(800);
    digitalWrite(i, LOW);
    digitalWrite(pinBuzzer, LOW);
  }

  delay(2000);

  for (int i = LED_1; i <= 6; i++) {
    digitalWrite(i, HIGH);
    digitalWrite((i + 2) % 7, HIGH);
    digitalWrite(pinBuzzer, HIGH);
    delay(800);
    digitalWrite(i, LOW);
    digitalWrite(pinBuzzer, LOW);
    digitalWrite((i + 2) % 7, LOW);
  }
}
