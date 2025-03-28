#include <Servo.h>

// Definir los pines de los servos
const int servoPin1 = 7;
const int servoPin2 = 3;
const int servoPin3 = 4;
const int servoPin4 = 5;

// Crear los objetos Servo
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

// Definir los pines de los potenciometros
const int potPin1 = A0;
const int potPin2 = A1;
const int potPin3 = A2;
const int potPin4 = A3;

void setup() {
  // Iniciar los servos
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
  
  // Configurar los pines de los potenciometros como entradas (por defecto lo son)
}

void loop() {
  // Leer los valores de los potenciometros (valor entre 0 y 1023)
  int potValue1 = analogRead(potPin1);
  int potValue2 = analogRead(potPin2);
  int potValue3 = analogRead(potPin3);
  int potValue4 = analogRead(potPin4);
  
  // Mapear los valores de los potenciometros (de 0-1023) al rango de los servos (0-180 grados)
  int angle1 = map(potValue1, 0, 1023, 0, 180);
  int angle2 = map(potValue2, 0, 1023, 0, 180);
  int angle3 = map(potValue3, 0, 1023, 0, 180);
  int angle4 = map(potValue4, 0, 1023, 0, 180);
  
  // Mover los servos a la posición indicada por los potenciometros
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);
  servo4.write(angle4);
  
  // Esperar un poco para evitar lecturas demasiado rápidas
  delay(10);
}
