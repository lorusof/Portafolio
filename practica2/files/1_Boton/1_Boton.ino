const int ledPin = 13;  // Pin del LED
const int buttonPin = 8; // Pin del botón
int buttonState = 0;  // Variable para leer el estado del botón

void setup() {
    pinMode(ledPin, OUTPUT);  // Configurar el LED como salida
    pinMode(buttonPin, INPUT_PULLUP);  // Activar resistencia pull-up interna
}

void loop() {
    buttonState = digitalRead(buttonPin);  // Leer el estado del botón

    if (buttonState == LOW) {  // El botón está presionado (LOW por pull-up)
        digitalWrite(ledPin, LOW);  // Apagar LED
    } else {
        digitalWrite(ledPin, HIGH);  // Encender LED
    }
}
