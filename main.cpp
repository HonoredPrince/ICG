#include "main.h"
#include <math.h>

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************	
	// Chame aqui as funções do mygl.h
	//*************************************************************************
	
	//ChecagemOctantes();
	//BDrawMyLine(vetor(0,0), vetor(198, 456), cor(255,0,0,255), cor(0,0,255,255));
	//BDrawMyTriangle(vetor(167,234), vetor(345,278), vetor(45, 78), cor(255,0,0,255), cor(0,0,255,255), cor(255,0,0,255));
	//DrawBox();
	
	/*BDrawMyTriangle(vetor(0,511), vetor(128,256), vetor(256, 511), cor(255,0,0,255), cor(0,0,255,255), cor(255,0,0,255));
	BDrawMyTriangle(vetor(256,511), vetor(384,256), vetor(512, 511), cor(255,0,0,255), cor(0,0,255,255), cor(255,0,0,255));
	BDrawMyTriangle(vetor(128,256), vetor(256,1), vetor(384,256), cor(255,0,0,255), cor(0,0,255,255), cor(255,0,0,255));	
	BDrawMyTriangle(vetor(128,256), vetor(256,127), vetor(384,256), cor(255,0,0,255), cor(0,0,255,255), cor(255,0,0,255));
	BDrawMyTriangle(vetor(128,256), vetor(256,383), vetor(384,256), cor(255,0,0,255), cor(0,0,255,255), cor(255,0,0,255));*/
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

