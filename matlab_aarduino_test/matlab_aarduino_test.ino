#include <SPI.h>		// incluye libreria interfaz SPI
#include <SD.h>			// incluye libreria para tarjetas SD

#define SSpin 10		// Slave Select en pin digital 10

int receiver = 0;
int voltage_read;

File archivo;			// objeto archivo del tipo File

void setup() {
  Serial.begin(9600);		// inicializa monitor serie a 9600 bps

  Serial.println("Inicializando tarjeta ...");	// texto en ventana de monitor
  if (!SD.begin(SSpin)) {			// inicializacion de tarjeta SD
    Serial.println("fallo en inicializacion !");// si falla se muestra texto correspondiente y
    return;					// se sale del setup() para finalizar el programa
  }
  Serial.println("inicializacion correcta");	// texto de inicializacion correcta
  archivo = SD.open("datos.txt", FILE_WRITE);	// apertura para lectura/escritura de archivo datos.txt

  if (archivo) {  
    for (int i=0; i < 500; i++){			// bucle repite 500 veces
      voltage_read = analogRead(receiver);
      archivo.print(i);				// escribe en tarjeta el valor del indice
      archivo.print(",");			// escribe en tarjeta una coma
      archivo.println(voltage_read);		// escribe en tarjeta el valor del voltaje

      Serial.print(i);
      Serial.print(", ");
      Serial.println(voltage_read);
      delay(1);	
      }
    archivo.close();				// cierre de archivo
    Serial.println("escritura correcta");	// texto de escritura correcta en monitor serie
  } else {
    Serial.println("error en apertura de datos.txt");	// texto de falla en apertura de archivo
  }
}


void loop() {			// funcion loop() obligatoria de declarar pero no utilizada
  // nada por aqui
}


