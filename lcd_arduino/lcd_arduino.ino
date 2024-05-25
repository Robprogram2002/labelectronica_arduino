#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);  // indica que pines utiliza el lcd
int led_rojo = 9;   
int led_azul = 10;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(led_rojo, OUTPUT);  // establecemos ambos leds como pines de salida
  pinMode(led_azul, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);  // leemos la lectura del sensor
  float x = (sensorValue * 5000.0)/1023;  // convertimos la lectura a voltaje: 0 - 5000 mV  
  float temperatura = x/10;  // convertimmos la lectura a temperatura en grados celcius
  float voltaje = x/4;  // voltaje de 0 - 255
  // ponemos el cursor al inicio del display
  // y escribimos el valor leido de temperatura
  lcd.setCursor(0,0);  
  lcd.print("Temp: ");
  lcd.print(temperatura);
  lcd.print((char)223);
  lcd.print("C");

  // ponemos el cursor en el segundo renglón del lcd
  lcd.setCursor(0,1);
  lcd.print("Mood: ");

  if (temperatura < 29.0) {
    digitalWrite(led_azul, HIGH);
    digitalWrite(led_rojo, LOW);
    lcd.print("Ambiente");
  } else {
    digitalWrite(led_azul, LOW);
    digitalWrite(led_rojo, HIGH);
    lcd.print("Caliente");
  }

  delay(500);
}
