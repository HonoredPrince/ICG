# Trabalho Individual 1

# Rasterização de Linhas
![Figure]()

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
![DrawBox]()

## 2° Funçao - BDrawMyLine()
A função principal da atividade, ela que faz a rasterização de uma linha de cor interpolada utilizando o algoritmo de Bresenham modificado para existir o funcionamento nos 8 octantes, primeiro ela determina através de vários "if's" qual octante a coordenada passada pertence, para assim aplicar a simetria através das trocas de variáveis e inversões de sinais no eixo x e y.

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





