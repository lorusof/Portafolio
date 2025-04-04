#include <Servo.h>
#include <SoftwareSerial.h>

// Definir servos
Servo servoBase;      // Base
Servo servoBrazo;     // Brazo
Servo servoAntebrazo; // Antebrazo
Servo servoPinza;     // Pinza

// Bluetooth
SoftwareSerial miBT(2, 3);  // RX, TX

// Pines de los servos
const int pinServoBase = 8;
const int pinServoBrazo = 12;
const int pinServoAntebrazo = 10;
const int pinServoPinza = 11;

void setup() {
  // Asignar pines a servos
  servoBase.attach(pinServoBase);
  servoBrazo.attach(pinServoBrazo);
  servoAntebrazo.attach(pinServoAntebrazo);
  servoPinza.attach(pinServoPinza);

  // Inicializar servos en posición neutra
  servoBase.write(90);
  servoBrazo.write(120);
  servoAntebrazo.write(180);
  servoPinza.write(90);

  // Iniciar comunicación
  Serial.begin(9600);
  miBT.begin(9600);
  Serial.println("🟢 Sistema iniciado. Esperando comandos...");
}

void loop() {
  if (miBT.available()) {
    String comando = miBT.readStringUntil('x');  // Leer hasta 'x'
    
    if (comando.length() > 1) { 
      char letra = comando.charAt(comando.length() - 1);  // Último carácter (la letra)
      String numeroStr = comando.substring(0, comando.length() - 1); // El resto es el número
      int numero = numeroStr.toInt(); // Convertir a entero

      Serial.print("📩 Comando recibido: ");
      Serial.print(letra);
      Serial.print(" → ");
      Serial.println(numero);

      switch (letra) {
        case 'a': servoPinza.write(numero); break;
        case 'b': servoAntebrazo.write(numero); break;
        case 'c': servoBrazo.write(numero); break;
        case 'd': servoBase.write(numero); break;
        default: Serial.println("❌ Comando inválido"); return;
      }
      Serial.println("✅ Comando ejecutado correctamente");
    } else {
      Serial.println("❌ Comando inválido");
    }
  }
}

