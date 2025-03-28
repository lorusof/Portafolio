const int button1 = 2;  // Primer botón
const int button2 = 3;  // Segundo botón
const int ledPin = 13;  // LED

void setup() {
    pinMode(button1, INPUT_PULLUP);  // Activar resistencia pull-up interna
    pinMode(button2, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
}

void loop() {
    // Leer el estado de los botones (LOW = presionado, HIGH = no presionado)
    int state1 = digitalRead(button1);
    int state2 = digitalRead(button2);

    // Solo enciende el LED si ambos botones están en HIGH (no presionados)
    if (state1 == HIGH && state2 == HIGH) {
        digitalWrite(ledPin, HIGH);  // Enciende LED
    } else {
        digitalWrite(ledPin, LOW);   // Apaga LED
    }
}
