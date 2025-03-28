int cuenta = 0;

void setup() {
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(2, INPUT_PULLUP); // Resistencia pull-up interna
}

void loop() {
    if (digitalRead(2) == HIGH) { // Botón presionado (LOW por pull-up)
        cuenta++;
        delay(500); // Evita rebotes

        if (cuenta > 4) { 
            cuenta = 0; // Reinicia la secuencia
        }
    }

    if (cuenta == 0) {
        digitalWrite(13, LOW);
        digitalWrite(12, LOW);
        digitalWrite(11, LOW);
        digitalWrite(10, LOW);
    } 
    else if (cuenta == 1) {
        digitalWrite(13, HIGH);
        digitalWrite(12, LOW);
        digitalWrite(11, LOW);
        digitalWrite(10, LOW);
    } 
    else if (cuenta == 2) {
        digitalWrite(13, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(11, LOW);
        digitalWrite(10, LOW);
    } 
    else if (cuenta == 3) {
        digitalWrite(13, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(10, LOW);
    } 
    else if (cuenta == 4) {
        digitalWrite(13, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(10, HIGH);
    }
}
