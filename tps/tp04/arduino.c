/* 
Exercício Prático 04 - Em grupo

--> Membros: Daniel Victor Costa, Marcella Santos Belchior e Mariana Almeida Mendonça.

--> Projeto : ULA 4bits usando Arduino + programa externo tradutor de comandos.
*/

#define LED0 10   // Bit menos significativo (LSB)
#define LED1 11
#define LED2 12
#define LED3 13   // Bit mais significativo (MSB)

#define TAMANHO_MEMORIA 256 //para armazenar as instruções do programa .hex

int memoria[TAMANHO_MEMORIA]; //array que vai  simular a memória da ULA, armazenando as instruções

int PC = 0; // var. para atuar como o Program Counter (PC), indicando a próxima instrução a ser executada

bool programaCarregado = false; // flag para indicar se o programa .hex já foi carregado na memória

int W; // var. para armazenar o resultado da execução de cada instrução na ULA

//SETUP
void setup() {
 
  Serial.begin(9600);
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  
  Serial.println("Pronto para receber o programa .hex (cole intrucoes e envie).");
  Serial.println("Envie 'INICIAR' para comecar a execucao.");
  
  for (int i = 0; i < TAMANHO_MEMORIA; i++) { // inicializa toda a memória com (-1) para indicar que a posição está vazia,
    memoria[i] = -1;
  }
}

//LOOP
void loop() {
  
  if (!programaCarregado) { // verifica se o programa ainda não foi carregado na memória
    carregarProgramaManualmente(); //// chama a função para carregar o programa .hex manualmente via serial
  } else {
    executarPrograma();
  }
}

void carregarProgramaManualmente() {
  // Verifica se há dados disponíveis na serial
  if (Serial.available() <= 0) {
    return;
  }

  // Lê a linha completa e remove espaços extras
  String linhaCompleta = Serial.readStringUntil('\n');
  linhaCompleta.trim();

  // Caso especial: comando INICIAR
  if (linhaCompleta.equalsIgnoreCase("INICIAR")) {
    programaCarregado = true;
    PC = 0;
    Serial.println("\nIniciando a execucao do programa.");
    return;
  }

  // Se já tiver programa carregado, ignora novas instruções
  if (programaCarregado) {
    return;
  }

  // Processa cada instrução na linha
  int indiceInicio = 0;
  for (int i = 0; i <= linhaCompleta.length(); i++) {
    // Verifica fim da instrução (espaço ou fim da string) -> Retira a expressão a ser lida
    if (i == linhaCompleta.length() || linhaCompleta.charAt(i) == ' ') { // Quando é espaço ou o final é porque não existe mais instrução
      String instrucaoStr = linhaCompleta.substring(indiceInicio, i); // Exemplo, começou em 0 e foi até aonde o i parou
      instrucaoStr.trim(); 
      
      // Ignora strings vazias
      if (instrucaoStr.length() == 0) {
        indiceInicio = i + 1; // Inicia da próxima posição que não é um espaço
        continue; // Reinicia a variável
      }

      // Verifica tamanho da instrução
      if (instrucaoStr.length() != 3) { // Mais uma validação: String tem tamanho 3? 
        Serial.print("ERRO: Instrucao '");
        Serial.print(instrucaoStr);
        Serial.println("' deve ter exatamente 3 caracteres");
        indiceInicio = i + 1;
        continue;
      }

      // Verifica caracteres válidos
      bool caracteresInvalidos = false; // Mais uma validação
      for (int j = 0; j < 3; j++) { // Lê letra por letra
        char c = instrucaoStr[j]; // Essa letra é válida? Não tem coisa maluca?
        if (!(c >= '0' && c <= '9') && !(c >= 'A' && c <= 'F')) {
          Serial.print("ERRO: Caractere invalido '");
          Serial.print(c);
          Serial.println("' na instrucao");
          caracteresInvalidos = true;
          break;
        }
      }
      
      if (caracteresInvalidos) { // Se for válido
        indiceInicio = i + 1;
        continue;
      }

      // Verifica espaço na memória
      if (PC >= TAMANHO_MEMORIA) {
        Serial.println("ERRO: Memoria cheia! Nao foi possivel carregar mais instrucoes.");
        break;
      }

      // Converte e armazena a instrução válida
      int X = hexToInt(instrucaoStr[0]);
      int Y = hexToInt(instrucaoStr[1]);
      int S = hexToInt(instrucaoStr[2]);
      
      memoria[PC] = (X << 8) | (Y << 4) | S;
      
      Serial.print("Carregado na memoria[");
      Serial.print(PC);
      Serial.print("]: ");
      Serial.println(instrucaoStr);
      
      PC++;
      indiceInicio = i + 1;
    }
  }

  Serial.println("Programa carregado na memoria. Envie 'INICIAR' para executar.");
}

void executarPrograma() { //executa o programa carregado na memória
  
  if (PC < TAMANHO_MEMORIA && memoria[PC] != -1) {  // verifica se o contador  está dentro do limite e se a posição atual tem instrução válida (-1 indica vazio)
   
    int instrucao = memoria[PC];
    int X = (instrucao >> 8) & 0xF; // extrai o valor de X da instrução (bits mais significativos)
    int Y = (instrucao >> 4) & 0xF; // extrai o valor de Y da instrução (bits intermediários)
    int S = instrucao & 0xF; // extrai o código da operação S da instrução (bits menos significativos)

    W = executarInstrucao(X, Y, S);

    //Print/DUMP da memória:
    Serial.print("PC: "); Serial.print(PC);
    Serial.print(" | Mem["); Serial.print(PC); Serial.print("]: ");
    Serial.print(instrucao, HEX); // Mostra a instrução completa em hexadecimal
    Serial.print(" (X="); Serial.print(X, HEX);
    Serial.print(", Y="); Serial.print(Y, HEX);
    Serial.print(", S="); Serial.print(S, HEX);
    Serial.print(") -> W: "); Serial.println(W, HEX);

    exibirResultado(W); // chama a função para exibir o resultado W nos LEDs
    PC++; // incrementa o Program Counter para a próxima instrução
    delay(2000); // delay pra facilitar a visualização
  }
  else if (programaCarregado) { // se o contador atingiu o final do programa carregado (encontrou -1 ou o limite da memória)
    Serial.println("\nFim da execucao do programa.");
    programaCarregado = false; // Reseta a flag para permitir o carregamento de um novo programa
    PC = 0; //reinicia o contador
    for (int i = 0; i < TAMANHO_MEMORIA; i++) { //limpa a memória para receber o novo .hex
      memoria[i] = -1;
    }
   
    Serial.println("Pronto para receber um novo programa .hex.");
    Serial.println("Envie as linhas e depois 'INICIAR'.");
  }
}

int hexToInt(char c) { //convertendo os valores
  if (c >= '0' && c <= '9') return c - '0'; // val. do ascii - 0 ( 48 em ascii)
  if (c >= 'A' && c <= 'F') return c - 'A' + 10; // val. do ascii - A (65) + 10
  
  return 0;
}

int executarInstrucao(int A, int B, int op) {
  switch (op) {
    case 0x0: return 0;       // Zero lógico
    case 0x1: return 1;       // Um lógico
    case 0x2: return A;       // Copia A
    case 0x3: return B;       // Copia B
    case 0x4: return ~A & 0xF; // NOT A
    case 0x5: return ~B & 0xF; // NOT B
    case 0x6: return A & ~B;  // A . B'
    case 0x7: return ~A & B;  // A' . B
    case 0x8: return A ^ B;   // A ⊕ B
    case 0x9: return(~A ^ ~B) & 0xF; // (A' ⊕ B')
    case 0xA: return ~(~A ^ ~B) & 0xF; // (A' ⊕ B')'
    case 0xB: return A & B;   // A . B
    case 0xC: return ~(A & B) & 0xF; // (A . B)'
    case 0xD: return ~(A | B)& 0xF;   // (A + B)'
    case 0xE: return (A | B) & 0xF; // (A + B)
    case 0xF: return ~((~A)|(~B)) & 0xF; // (A' + B')'
    default: return 0;
  }
}//  0xF -> garante que o resultado fique limitado a 4bits ( 1111 )


void exibirResultado(int W) { //exibe o resultado fazendo shits, arrastando os bits para pegar a posição certa
  digitalWrite(LED0, W & 0x1);
  digitalWrite(LED1, (W >> 1) & 0x1);
  digitalWrite(LED2, (W >> 2) & 0x1);
  digitalWrite(LED3, (W >> 3) & 0x1);
}
