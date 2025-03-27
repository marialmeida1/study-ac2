# Projeto de Conversão de Mnemônicos para Hardware Externo

## Sobre o Projeto
Este projeto consiste em desenvolver dois programas: um para o hardware externo (Arduino) e outro para o PC, que atuará como interface com o usuário. O objetivo é transformar um programa escrito pelo usuário em mnemônicos, convertê-los em um novo programa e transmiti-lo ao hardware externo via porta serial. O resultado da execução será observado em 4 LEDs conectados ao hardware.

## Funcionamento do Programa no PC
O código em Python tem a função de converter expressões mnemônicas em códigos hexadecimais, gerando um arquivo de saída que será enviado ao Arduino.

### Principais Componentes do Código:
1. **Função `hex(letter)`**: Converte números de 0 a 15 para suas respectivas representações hexadecimais.
2. **Função `mnemonico(expression)`**: Converte mnemônicos para seus valores hexadecimais equivalentes.
3. **Função `writeFile(x, y, w)`**: Escreve os valores convertidos no arquivo de saída `testeula.hex`.
4. **Processamento do arquivo `testeula.ula`**: Lê comandos do usuário, extrai valores de `X=`, `Y=`, e `W=`, e os converte para hexadecimal antes de gravar no arquivo de saída.

## Circuito Utilizado
Para este projeto, utilizamos um circuito desenvolvido no Tinkercad. Você pode acessá-lo através do seguinte link:
[Visualizar Circuito no Tinkercad](https://www.tinkercad.com/things/3n9hLuUYzOA/editel?returnTo=%2Fdashboard&sharecode=g1nA9nHAZ3y0GM-ZTKhsFxv8AoiVXOFZHlN0Lnd5kos)

## Participantes
- **Daniel Victor Costa**
- **Marcella Santos Belchior**
- **Mariana Almeida Mendonça**

## Como Executar o Programa
1. Certifique-se de ter o Python instalado.
2. Execute o programa de conversão para gerar o arquivo `testeula.hex`.
3. Envie o arquivo gerado ao hardware externo via porta serial.
4. Observe o comportamento dos LEDs no hardware conectado.

Este projeto visa demonstrar como transformar comandos escritos pelo usuário em códigos mnemônicos e transmitir esses códigos para um hardware externo de forma automatizada.