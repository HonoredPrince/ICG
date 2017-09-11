# Trabalho Individual 1

# Rasterização de Linhas
![Figure](/Trabalho \Individual \1 \- \Rasterização/images/figure.png)

## Proposta
O trabalho tem como objetivo a rasterização de linhas de cores interpoladas, manuseando bytes RGBA utilizando o algoritmo de Bresenham e aplicando modificações cabíveis para o funcionamento devido nos 8 octantes de um sistema de coordenadas, que foi criado com o intuito de possibilitar o desenho de linhas em dispositivos matriciais, em que basicamente ele utiliza de duas coordenadas, uma reta entre elas e vários pontos médios para ir definindo os pixeis que serão preenchidos na tela fazendo uso da aritmética dos inteiros e compondo a linha, no entanto tal algoritmo é apenas válido para o primeiro octante, ou seja apenas o desenho de linhas entre 0° a 45°.

## Introdução
Na atividade foi requisitado 3 funções, uma que coloca um pixel na coordenada dada, uma que desenha uma linha utilizando o algoritmo modificado para os 8 octantes, e uma função que desenvolve um triângulo.

## Classes
Foi feito 2 classes para o manuseamento facilitado de parâmentros e para uma melhor organização do código, a classe "vetor" que possui objetos que irão ser utilizados como coordenadas, com valores de x e y e a classe "cor" que possui objetos com valores inteiros para RGBA

![Classes]()

## 1°Função - PutPixel()
Foi a função de implementação mais simples, tem como parâmetro um objeto da classe "vetor" e outro da classe "cor", logo possuindo uma coordenada (x,y) e um padrão de cor.
Funciona desta forma: para cada valor da coordenada x, anda-se 4 vezes na posição de memória para localizar o endereço do próximo pixel e para cada valor de y, anda-se o tamanho da resolução total multiplicada por 4 e pelo y, logo como os pixeis estão posicionados lado a lado, é feito o devido preenchimento do pixel na coordenada desejada.

![PutPixel]()

## DrawBox
Função que utiliza 5 chamadas em um laço da função PutPixel() para desenhar um quadrado com uma diagonal.

![DrawBoxC]()

![DrawBoxC]()

## 2° Funçao - BDrawMyLine()
A função principal da atividade, é ela que faz a rasterização de uma linha de cor interpolada utilizando o algoritmo de Bresenham modificado para existir o funcionamento nos 8 octantes, primeiro ela determina através de vários "if's" qual octante a coordenada dada pertence, para assim aplicar a simetria para o primeiro quadrante através das trocas de variáveis e inversões de sinais no eixo x e y, para depois calcular o que é preciso para se utilizar no algoritmo de Bresenham, fazer a interpolação de cores e transpor de volta para o primeiro octante com as trocas feitas e inversões de sinal devidas e assim aplicar o algoritmo.

Octantes: tendo em mente a variação "Dx" e "Dy" no sistema e os valores das coordendas (x,y) 

Obs: Quando |Dx| < |Dy|, ocorre a troca dos valores nos eixos, x recebe y, y recebe x.

Para (Dx >= 0 e Dy >= 0): Octantes 0 e 1 (X positivo, Y posisivo)

Octante 0: Dx >= Dy

Octante 1: Dx < Dy

Para (Dx >= 0 e Dy < 0): Octantes 7 e 6 (X positivo, Y negativo)

Octante 7: Dx >= -Dy

Octante 6: Dx < -Dy

Para (Dx < 0 e Dy >= 0): Octantes 3 e 2 (X negativo, Y posisivo)

Octante 3: -Dx >= Dy

Octante 2: -Dx < Dy

Para (Dx < 0 e Dy < 0): Octantes 4 e 5 (X negativo, Y negativo)

Octante 4: -Dx >= -Dy

Octante 5: -Dx < -Dy

![BDrawPt1]()

Após feita a simetria e armazenado os valores nas váriaveis temporárias, é feito o cálculo de todos os componentes do algoritmo de Bresenham e é feita a interpolação de cores, e depois começa o laço do algoritmo e dentro do laço, as coordenadas com os valores modificados após o processo simétrico, são colocadas de volta aos seus octantes originais através dos condicionais "if's", sendo um para cada octante.

- Interpolação:

A interpolação funciona da seguinte forma: é calculado a variação entre as cores finais e iniciais para cada componente de cor(RGBA), esse valor sendo dividido pelo total de pixels desenhados, assim, obtendo o valor de acréscimo em cada iteração no laço do algoritmo, logo, cada pixel tem seu valor devidamente atualizado para que a interpolação ocorra.

![BDrawPt2]()

- Checagem para o funcionamento do algoritmo para os 8 octantes

Foi feito um teste chamando a função Checagem(), que através de um laço, faz o desenho de linhas no escopo do máximo de octantes possíveis, como na imagem abaixo:

![Checagem]()

Logo, é evidente o funcionamento do algoritmo modificado, já que é desenhado esse círculo que está dentro dos 8 octantes.

## 3° Função - BDrawMyTriangle()
Função de simples implementação, basicamente recebe como parâmetro 3 objetos da classe "vetor" e 3 objetos da classe "cor", que funcionam como 3 vértices de coordenadas(x,y) e cor(RGBA), assim é chamada 3 vezes a função BDrawMyLine() para desenhar as 3 linhas que irão compor o triângulo.

![Triangulo]()










