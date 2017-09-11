#include "main.h"
#include <math.h>

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************	
	// Chame aqui as funções do mygl.h
	//*************************************************************************
	
	//DrawBox();

	//BDrawMyLine(vetor(128,128), vetor(384, 384), cor(255,0,0,255), cor(0,0,255,255));

	//ChecagemOctantes();

	BDrawMyTriangle(vetor(128,383), vetor(256,127), vetor(384,384), cor(255,0,0,255), cor(0,0,255,255), cor(255,0,0,255));
	
	
	//Desenha uma figura composta por triângulos 	
	/*BDrawMyTriangle(vetor(0,511), vetor(128,256), vetor(256, 511), cor(255,127,0,255), cor(0,255,255,255), cor(255,127,0,255));
	BDrawMyTriangle(vetor(256,511), vetor(384,256), vetor(512, 511), cor(255,127,0,255), cor(0,255,255,255), cor(255,127,0,255));
	BDrawMyTriangle(vetor(128,256), vetor(256,1), vetor(384,256), cor(255,127,0,255), cor(0,255,255,255), cor(255,127,0,255));	
	BDrawMyTriangle(vetor(128,256), vetor(256,127), vetor(384,256), cor(255,127,0,255), cor(0,255,255,255), cor(255,127,0,255));
	BDrawMyTriangle(vetor(128,256), vetor(256,383), vetor(384,256), cor(255,127,0,255), cor(0,255,255,255), cor(255,127,0,255));*/
}	
//


//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

