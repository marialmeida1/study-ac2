# Trabalho Prático 02 - Arquitetura de Computadores

**Aluno:** Mariana Almeida Mendonça
### **Questão 01** 

Para esse projeto foi usado quatro LEDs (vermelho, verde, amarelo e azul), além de quatro resistências de 1kΩ. Para completar a montagem do circuito, foi utilizada uma protoboard e uma placa Arduino.

Sobre o programa, foram usados três métodos, sendo dois deles padrão do Arduino. O primeiro é o método `setup`, responsável pela configuração dos pinos de cada LED, especificando a porta e o tipo de saída. O segundo é o método `loop`, que define a lógica do funcionamento do semáforo, garantindo que o LED azul pisque a cada 1 segundo e alternando entre os LEDs vermelho, verde e amarelo em seus respectivos tempos.

Por fim, foi criado um método auxiliar chamado `piscarAzul`, que facilita a repetição do efeito de piscar do LED azul, tornando o código mais organizado e modularizado.

![[Pasted image 20250308165113.png]]

## **Questão 02**