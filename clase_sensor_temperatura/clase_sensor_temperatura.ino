int Led = 3;
int pot = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(Led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Enciende el Led utilizando la señal de entrada de un potenciometro  
  int sensorValue = analogRead(A0);
  float voltaje = sensorValue / 4;  // El potenciometro va de 0 - 1020 y queremos que vaya de 0 - 255

  Serial.println(voltaje);
  delay(20);

  analogWrite(Led, voltaje);
  delay(50);

  // Enciende progresivamente el Led y después de 1 segundo lo apaga progresivamente

  // for (int i = 0; i <255; i++) {
  //   analogWrite(Led, i);
  //   delay(20);
  // }

  // delay(1000);

  // for (int j = 255; j>=0; j--) {
  //   analogWrite(Led, j);
  //   delay(20);
  // }

}
