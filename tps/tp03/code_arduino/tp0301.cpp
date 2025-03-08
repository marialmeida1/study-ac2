const int ledBlue = 10;
const int ledRed = 13;
const int ledGreen = 11;
const int ledYellow = 12;

void setup() {
    pinMode(ledBlue, OUTPUT);
    pinMode(ledRed, OUTPUT);
    pinMode(ledGreen, OUTPUT);
    pinMode(ledYellow, OUTPUT);
}

void loop() {
    // 3 ciclos com vermelho ligado
    for (int i = 0; i < 3; i++) {
        blinkBlue();
        digitalWrite(ledRed, HIGH);
    }
    digitalWrite(ledRed, LOW);

    // 4 ciclos com verde ligado
    for (int i = 0; i < 4; i++) {
        blinkBlue();
        digitalWrite(ledGreen, HIGH);
    }
    digitalWrite(ledGreen, LOW);

    // 2 ciclos com amarelo ligado
    for (int i = 0; i < 2; i++) {
        blinkBlue();
        digitalWrite(ledYellow, HIGH);
    }
    digitalWrite(ledYellow, LOW);
}

void blinkBlue() {
    digitalWrite(ledBlue, HIGH);
    delay(1000);
    digitalWrite(ledBlue, LOW);
    delay(1000);
}
