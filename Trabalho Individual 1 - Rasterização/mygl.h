#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include "math.h"

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************


//Manuseamento mais fácil para os parâmetros com a definição destas classes, uma para a cor(RGB), outra para os vetores(coordenadas tipo (x,y)) 

class cor{
	public:
		float r, g, b, a;

		cor(int r, int g, int b, int a){
		
			this->r = r;
			this->g = g;
			this->b = b;
			this->a = a;
		}
};

class vetor{
	public:
		int x, y;

		vetor(int x, int y){
			
			this->y = y;
			this->x = x;
		}
};


void PutPixel(vetor vt, cor c)
{
	FBptr[4*vt.x + (4*vt.y*IMAGE_WIDTH) + 0] = c.r;
	FBptr[4*vt.x + (4*vt.y*IMAGE_WIDTH) + 1] = c.g;
	FBptr[4*vt.x + (4*vt.y*IMAGE_WIDTH) + 2] = c.b;
	FBptr[4*vt.x + (4*vt.y*IMAGE_WIDTH) + 3] = c.a;
}

/*Desenha um quadrado com uma diagonal, utilizando somente a funcão PutPixel()*/

void DrawBox()
{
	for(unsigned int i = 0; i<512; i++)
	{
		PutPixel(vetor(i,0), cor(255,127,0,255));
		PutPixel(vetor(0,i), cor(255,127,0,255));
		PutPixel(vetor(i,i), cor(255,127,0,255));
		PutPixel(vetor(IMAGE_WIDTH-1,i), cor(255,127,0,255));
		PutPixel(vetor(i,IMAGE_HEIGHT-1), cor(255,127,0,255));
	}
}

/*Algoritmo de Bresenham para todos os octantes, o sinal muda para negativo dependendo de qual variação no eixo é negativa, e ocorre inversão dos valores de x por y, quando a variação no eixo y é maior do que no eixo x*/

void BDrawMyLine(vetor vt1, vetor vt2, cor c1, cor c2)
{		
	
	//Variáveis temporárias que são usadas para receber os valores na hora da troca de eixo e nas inversões, e calcular o DX e DY adequados	
	int tempDx = vt2.x - vt1.x;
	int tempDy = vt2.y - vt1.y;
	int x1, y1, x2, y2;

	//Verificação de que octante a linha pertence, uma vez verificado é feita as devidas trocas de eixo e inversões de sinal

	int octante;


	if (tempDx >= 0)
	{
		if (tempDy >= 0)
		{
			if (tempDx >= tempDy)
			{
				octante = 0;
				x1 = vt1.x;
				x2 = vt2.x;
				y1 = vt1.y;
				y2 = vt2.y;
			}
			if (tempDx < tempDy)
			{
				octante = 1;
				x1 = vt1.y;
				x2 = vt2.y;
				y1 = vt1.x;
				y2 = vt2.x;
			}
		}
		if (tempDy < 0)
		{
			if (tempDx >= -tempDy)
			{
				octante = 7;
				x1 = vt1.x;
				x2 = vt2.x;
				y1 = -vt1.y;
				y2 = -vt2.y;
			}
			if (tempDx < -tempDy)
			{
				octante = 6;
				x1 = -vt1.y;
				x2 = -vt2.y;
				y1 = vt1.x;
				y2 = vt2.x;
			}
		}
	}
	if (tempDx < 0)
	{
		if (tempDy >= 0)
		{
			if (-tempDx >= tempDy)
			{
				octante = 3;
				x1 = -vt1.x;
				x2 = -vt2.x;
				y1 = vt1.y;
				y2 = vt2.y;
			}
			if (-tempDx < tempDy)
			{
				octante = 2;
				x1 = vt1.y;
				x2 = vt2.y;
				y1 = -vt1.x;
				y2 = -vt2.x;
			}
		}
		if (tempDy < 0)
		{
			if (-tempDx >= -tempDy)
			{
				octante = 4;
				x1 = -vt1.x;
				x2 = -vt2.x;
				y1 = -vt1.y;
				y2 = -vt2.y;
			}
			if (-tempDx < -tempDy)
			{
				octante = 5;
				x1 = -vt1.y;
				x2 = -vt2.y;
				y1 = -vt1.x;
				y2 = -vt2.x;
			}
		}
	}

	//Bresenham: Variáveis e o método em si retirado do pŕoprio algortimo de Bresenham que desenha no primeiro octante que irá ser implementado ao lado das condições e modificações para o 		    		funcionamento nos 8 octantes
	float Dx = x2 - x1;
	float Dy = y2 - y1;
	float dm = Dy/Dx;
	float m = 0;
	int y =  y1;

	//Interpolação de cor: é feita a diferença e é obtido essas variações que vão até o fim da linha, usa o Dx nas iterações pois no laço que vai criar a linha de pixeis a variação de ""x"" é usada como     		parâmentro do laço
	cor c = c1;
	float dr = (c2.r - c1.r) / Dx;
	float dg = (c2.g - c1.g) / Dx;
	float db = (c2.b - c1.b) / Dx;

	for (int x = x1; x < x2; ++x)
	{
		// Interpolação de cor na pŕatica
		c.r = c.r + dr;
		c.g = c.g + dg;
		c.b = c.b + db;
	

		// Aqui ocorre a mudança para o primeiro octante novamente com as trocas e inversões feitas, com a utilização do if dentro do laço determinar a ordem e o sinal de cada octante
		
		if(octante == 0){ 
			PutPixel(vetor(x, y), c);
		}
		if(octante == 1){ 
			PutPixel(vetor(y, x), c);
		}
		if(octante == 2){ 
			PutPixel(vetor(-y, x), c);
		}
		if(octante == 3){ 
			PutPixel(vetor(-x, y), c);
		}
		if(octante == 4){ 
			PutPixel(vetor(-x, -y), c);
		}
		if(octante == 5){ 
			PutPixel(vetor(-y, -x), c);
		}
		if(octante == 6){ 
			PutPixel(vetor(y, -x), c);
		}
		if(octante == 7){ 
			PutPixel(vetor(x, -y), c);
		}
		
		//Incrementação do algoritmo de Bresenham para o os eixos x e y, ou ambos

		m = m + dm;

		if (m >= 0.5)
		{
			++y;
			--m;
		}
	}
}

// Desenha um triângulo, usando a função BDrawMyLine(), basicamente desenhando 3 linhas em ciclo
void BDrawMyTriangle(vetor vt1, vetor vt2, vetor vt3, cor c1, cor c2, cor c3)
{
	BDrawMyLine(vt1, vt2, c1, c2);
	BDrawMyLine(vt2, vt3, c2, c3);
	BDrawMyLine(vt3, vt1, c3, c1); 
}

//Checagem do funcionamento do código para os 8 octantes, desenha linhas em todos os oito octantes

void ChecagemOctantes()
{
	for (int i = 0; i < 360; i++) {
		BDrawMyLine(vetor(256, 256), vetor(256 + 256*cos(i*180/3.14), 256 + 256*sin(i*180/3.14)), cor(255, 0, 0, 255), cor (0, 0, 255, 255));
	}
}

		
#endif // _MYGL_H_

