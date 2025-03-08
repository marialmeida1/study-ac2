# Trabalho Prático 02 - Arquitetura de Computadores

**Aluno:** Mariana Almeida Mendonça
### **Questão 01** 

Para esse projeto foi usado quatro LEDs (vermelho, verde, amarelo e azul), além de quatro resistências de 1kΩ. Para completar a montagem do circuito, foi utilizada uma protoboard e uma placa Arduino.

Sobre o programa, foram usados três métodos, sendo dois deles padrão do Arduino. O primeiro é o método `setup`, responsável pela configuração dos pinos de cada LED, especificando a porta e o tipo de saída. O segundo é o método `loop`, que define a lógica do funcionamento do semáforo, garantindo que o LED azul pisque a cada 1 segundo e alternando entre os LEDs vermelho, verde e amarelo em seus respectivos tempos.

Por fim, foi criado um método auxiliar chamado `piscarAzul`, que facilita a repetição do efeito de piscar do LED azul, tornando o código mais organizado e modularizado.

![[Pasted image 20250308165113.png]]

## **Questão 02**

Este projeto utiliza um Arduino com quatro LEDs (vermelho, amarelo, verde e azul) para representar os valores de entrada e saída de uma Unidade Lógica e Aritmética (ULA). Através da comunicação serial, três valores são enviados: `a`, `b` e o código da operação (`AND`, `OR`, `NOT` ou `SOMA`). Os LEDs `vermelho` e `amarelo` indicam `a` e `b`, enquanto o `verde` exibe o resultado da operação e o `azul` representa o Carry Out na soma. O código interpreta os valores recebidos, executa a operação correspondente e acende os LEDs de acordo com o resultado, permitindo visualizar as operações lógicas e aritméticas diretamente no hardware.

![[Pasted image 20250308171212.png]]


| x   | Instrução     | Binário | Hexadecimal | Resultado |
| --- | ------------- | ------- | ----------- | --------- |
| 1   | **AND(A,B)**  | 0 1 00  | 0x4         | 0         |
| 2   | **OR(A,B)**   | 1 0 01  | 0x9         | 1         |
| 3   | **SOMA(A,B)** | 1 0 11  | 0xB         | 1         |
| 4   | **NOT(A)**    | 0 0 10  | 0x2         | 1         |
| 5   | **AND(B,A)**  | 1 1 00  | 0xC         | 1         |
### **Resultados**

#### **Instrução 1:**

![[Pasted image 20250308173003.png]]

#### **Instrução 2**

![[Pasted image 20250308173103.png]]

#### **Instrução 3**

![[Pasted image 20250308173226.png]]

#### **Instrução 4**

![[Pasted image 20250308173301.png]]

#### **Instrução 5**

![[Pasted image 20250308173453.png]]

##### OBS: Quando há a ocorrência de "Vai1":

![[Pasted image 20250308174051.png]]