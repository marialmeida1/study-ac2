int ledA = 13;  // LED vermelho (a)
int ledB = 12;  // LED amarelo (b)
int ledOutput = 11;  // LED verde (Saída ULA)
int ledCarryOut = 10;  // LED azul (Vai1)

void setup() {
    Serial.begin(9600);
    pinMode(ledA, OUTPUT);
    pinMode(ledB, OUTPUT);
    pinMode(ledOutput, OUTPUT);
    pinMode(ledCarryOut, OUTPUT);
}

void loop() {
    if (Serial.available() >= 3) {  
        // Lendo os três valores
        int a = Serial.read() - '0';  // Converte char para int
        int b = Serial.read() - '0'; 
        int opCode = Serial.read() - '0';

        int output = 0, carryOut = 0;

        // Operações da ULA
        switch (opCode) {
            case 0:  // AND (a & b)
                output = a & b;
                break;
            case 1:  // OR (a | b)
                output = a | b;
                break;
            case 2:  // NOT (a)
                output = !a;
                break;
            case 3:  // Soma (a + b)
                output = (a + b) % 2;  // Soma binária
                carryOut = (a + b) / 2;  // carryOut (carry)
                break;
        }

        // Exibir no Serial Monitor
        Serial.print("a = "); Serial.print(a);
        Serial.print(", b = "); Serial.print(b);
        Serial.print(", OpCode = "); Serial.print(opCode);
        Serial.print(" -> Saída = "); Serial.print(output);
        Serial.print(", Vai1 = "); Serial.println(carryOut);

        // Atualizar LEDs
        digitalWrite(ledA, a);
        digitalWrite(ledB, b);
        digitalWrite(ledOutput, output);
        digitalWrite(ledCarryOut, carryOut);
    }
}
