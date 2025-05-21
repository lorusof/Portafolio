#include <Servo.h>
#include <SoftwareSerial.h>
 
 
SoftwareSerial bluetooth(2,3);// Pines HC05
 
// Servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
 
// Variables para almacenar posiciones
int pos = 0;
int pos2 = 0;
int pos3 = 0;
int pos4 = 0;
int pos5 = 0;
 
void setup() {
  // Comunicación serial
  Serial.begin(9600);
  bluetooth.begin(9600);
 
  // Asignar pines de servos
  servo1.attach(12);
  servo1.write(90);
  servo2.attach(11);
  servo2.write(90);
  servo3.attach(9);
  servo3.write(90);
  servo4.attach(6);
  servo4.write(90);
  servo5.attach(5);
  servo5.write(90);
}
 
void loop() {
  // Datos disponibles

  if (bluetooth.available() > 0) {
    pos = bluetooth.read();
    Serial.println(pos);
    pos2 = bluetooth.read();
    Serial.println(pos2);
    pos3= bluetooth.read();
    Serial.println(pos3);
    pos4 = bluetooth.read();
    Serial.println(pos4);
    pos5 = bluetooth.read();
    Serial.println(pos5);
    Serial.println("");
    servo1.write(pos);
    servo2.write(pos2);
    servo3.write(pos3);
    servo4.write(pos4);
    servo5.write(pos5);
    delay(10);
    
  }
}
