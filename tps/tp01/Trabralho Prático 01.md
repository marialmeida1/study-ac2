
# Trabalho Prático 01 - Arquitetura de Computadores

**Aluno:** Mariana Almeida Mendonça | Marcella Santos Belchior
### Questão 01 

###### Circuito

![[Pasted image 20250227113909.png]]

###### Usando o Meio Somador de 1bit

![[Pasted image 20250227114019.png]]

### Questão 02

Tabela verdade a partir do circuito gerado na atividade anterior, meio somador.

| A   | B   | R   | C   |
| --- | --- | --- | --- |
| 0   | 0   | 0   | 0   |
| 0   | 1   | 1   | 0   |
| 1   | 0   | 1   | 0   |
| 1   | 1   | 0   | 1   |

### Questão 03

Com base em datasheets de componentes eletrônicos, os circuitos integrados da família 74LS, fornecem essas portas. Sendo eles:

- **74LS86:** no qual possuí quatro (4) portas XOR, de duas (2) entradas. Link para acesso: https://www.futurlec.com/74LS/74LS86.shtml
- **74LS08**: possúi quatro (4) portas AND, de duas (2) entradas. Link para acesso: https://www.futurlec.com/74LS/74LS08.shtml


### Questão 04

Em ambos componentes a portas VCC e GND se encontram respectivamente na portas de localização, 14 e 7.

## Pergunta 01

*"O que acontece se um dos terminais de entrada de uma porta lógica não estiver conectado em 0 ou 1 (eletricamente ele deverá estar flutuando, ou seja não conectado a nenhum nível lógico)."*

**Resposta:** Se um dos terminais de entrada de uma porta lógica não estiver conectado a 0 ou 1, ele ficará flutuando, ou seja, sem um nível lógico definido. Isso pode fazer com que a porta lógica interprete a entrada de forma instável, variando entre 0 e 1 de maneira imprevisível devido a interferências externas e ruídos elétricos. Esse comportamento pode gerar resultados inesperados no circuito, causando falhas na lógica digital e até um aumento no consumo de energia.

### Questão 05

| ![[Pasted image 20250228110030.png]] | ![[Pasted image 20250228110046.png]] |
| ------------------------------------ | ------------------------------------ |
| ![[Pasted image 20250228110058.png]] | ![[Pasted image 20250228110109.png]] |


### Questão 06 - 07 - 08 

###### Circuito no TinkerCad

![[Somador Copleto.png]]

###### Circuito no Logisim

![[Pasted image 20250228114805.png]]


### Questão 09

###### Tabela Verdade - Somador Completo

| a   | b   | c   | x   | y   |
| --- | --- | --- | --- | --- |
| 0   | 0   | 0   | 0   | 0   |
| 0   | 0   | 1   | 1   | 0   |
| 0   | 1   | 0   | 1   | 0   |
| 0   | 1   | 1   | 0   | 1   |
| 1   | 0   | 0   | 1   | 0   |
| 1   | 0   | 1   | 0   | 1   |
| 1   | 1   | 0   | 0   | 1   |
| 1   | 1   | 1   | 1   | 1   |
### Questão 10

Um somador de 4 bits é um circuito digital que realiza a soma de dois números binários de 4 bits (A e B) utilizando quatro somadores completos (full adders) conectados em cascata. Cada somador recebe dois bits correspondentes das parcelas (Ai e Bi) e um carry-in (vai-um) da etapa anterior, gerando um bit da soma (Si) e um carry-out para o próximo estágio. O primeiro somador recebe um carry-in inicial de 0, e o carry-out do último somador pode indicar um overflow. 

![[Pasted image 20250228120146.png]]


## Pergunta 2

O principal problema de tempo nesse tipo de somador é a propagação do carry. Como o carry-out de um somador completo depende do carry-in do estágio anterior, ele precisa percorrer todos os bits da soma antes que o resultado final seja válido. Isso gera um atraso cumulativo, tornando o somador mais lento à medida que o número de bits aumenta.
## Pergunta 3

Se cada porta lógica tem um atraso médio de 10 ns, vemos que um somador de 1bit possuí um atraso médio de 30 ns. Portanto, como o tempo é acumulativo em um somador de 4bits, o tempo total seria de 90 ns. Visto que, após o primeiro bit, os demais somadores gastam 20 ns.

## Pergunta 4

Para um somador de **32 bits**, seria necessário conectar **32 full adders** em cascata. No entanto, isso aumentaria significativamente o tempo de propagação do carry, tornando a soma mais lenta.

## Pergunta 5

Se cada porta demora 10 ns, e cada bit gera um atraso de 30 ns no primeiro e 20 ns nos demais,o tempo total para um somador de 32 bits será (31 × 20) + 20 = 620 ns. A frequência de operação é o inverso do tempo por operação:

$$
f = \frac{1}{650 \times 10^{-9}} = 1.54 \text{ MHz}
$$
$$

$$


Ou seja, o somador pode operar a aproximadamente 1,54 MHz.

## Pergunta 6

Para aumentar a velocidade, pode-se utilizar um somador com antecipação de carry (carry lookahead adder - CLA), que calcula o carry de forma paralela, reduzindo significativamente o tempo de propagação. 

### Calculadora de 4bits

###### Resultado Final

![[Pasted image 20250228163830.png]]
		
###### Decodificador
![[Pasted image 20250228163858.png]]]

#### Somador 4Bit
![[Pasted image 20250228163920.png]]