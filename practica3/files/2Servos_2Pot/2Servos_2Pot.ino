#include <Servo.h>
Servo myservo1;
Servo myservo2;
int valor1, valor2, pos1, pos2;
void setup() {
  myservo1.attach(9);
  myservo2.attach(2);
}
void loop() {
  valor1 = analogRead(A0);
  valor2 = analogRead(A1);
  pos1 = map(valor1, 0, 1023, 0, 180);
  pos2 = map(valor2, 0, 1023, 0, 180);
  myservo1.write(pos1);
  myservo2.write(pos2);
  delay(10);
}