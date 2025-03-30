#include <Servo.h>
Servo servoMotor;
int valor;
int pos;
void setup() {
  servoMotor.attach(9);
}
void loop() {
  valor = analogRead(A1);
  pos = map(valor, 0, 1023, 0, 180);
  servoMotor.write(pos);
  delay(1000);
}