//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//******** Alumno (s): Garcia Villavicencio Danahe************//
//*****Solo se agrega/cambia el main a practicas pasada*******//
//*************				Visual Studio 2017		**********//
//**************Fecha de entrega: 03/Sep/2018*****************//
//***Se tuvo problemas para poder colocar los parametros**//

//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>
#include "Main.h"

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;


void InitGL(GLvoid)     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void) //se dibija un prisma o cubo
{
	GLfloat vertice[10][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.7 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.7 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.7 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.7 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				{0.0 ,0.5 ,0.5},// vertice 8 V8
				{0.0 ,0.5 ,-0.5}    //VERTICE 9 V9 
	};

	/*LETRA D
	glColor3f(1.0f, 1.0f, 0.0f);

	glBegin(GL_POLYGON);
	glVertex3f(2.0f, 0.0f, -1.0f);
	glVertex3f(2.0f, 5.0f, -1.0f);
	glVertex3f(3.0f, 5.0f, -1.0f);
	glVertex3f(3.0f, 1.0f, -1.0f);
	glVertex3f(5.0f, 1.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(5.0f, 4.0f, -1.0f);
	glVertex3f(5.0f, 1.0f, -1.0f);
	glVertex3f(4.0f, 1.0f, -1.0f);
	glVertex3f(4.0f, 4.0f, -1.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(3.0f, 5.0f, -1.0f);
	glVertex3f(3.0f, 4.0f, -1.0f);
	glVertex3f(5.0f, 4.0f, -1.0f);
	glEnd();

	/*LETRA G
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);

	glVertex3f(6.0f, 0.0f, -1.0f);
	glVertex3f(6.0f, 5.0f, -1.0f);
	glVertex3f(7.0f, 5.0f, -1.0f);
	glVertex3f(7.0f, 1.0f, -1.0f);
	glVertex3f(10.0f, 1.0f, -1.0f);
	glVertex3f(10.0f, 0.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(7.0f, 4.0f, -1.0f);
	glVertex3f(7.0f, 5.0f, -1.0f);
	glVertex3f(10.0f, 5.0f, -1.0f);
	glVertex3f(10.0f, 4.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(8.0f, 2.0f, -1.0f);
	glVertex3f(8.0f, 3.0f, -1.0f);
	glVertex3f(9.0f, 3.0f, -1.0f);
	glVertex3f(9.0f, 2.0f, -1.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(9.0f, 1.0f, -1.0f);
	glVertex3f(9.0f, 3.0f, -1.0f);
	glVertex3f(10.0f, 3.0f, -1.0f);
	glVertex3f(10.0f, 1.0f, -1.0f);
	glEnd();*/




	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 0.0, 0.0);
	glVertex3fv(vertice[0]); //se necesitan 4 vertices
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[8]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glColor3f(0.0, 0.0, 1.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glColor3f(0.0, 1.0, 0.0);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[9]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[8]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom

	glColor3f(0.4, 0.2, 0.6);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[9]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glColor3f(0.8, 0.2, 0.4);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[9]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}


/*

void prisma0(void) //se dibija un prisma o cubo
{
	GLfloat vertice[8][3] = {
				{6.0 ,-4.0, 0.5},    //Coordenadas Vértice 0 V0; cambia profundidad el eje Z
				{0.0 ,-4.0, 0.5},    //Coordenadas Vértice 1 V1
				{0.0 ,-4.0, -0.5},    //Coordenadas Vértice 2 V2
				{6.0 ,-4.0, -0.5},    //Coordenadas Vértice 3 V3
				{6.0 ,-3.0, 0.5},    //Coordenadas Vértice 4 V4
				{6.0 ,-3.0, -0.5},    //Coordenadas Vértice 5 V5
				{0.0 ,-3.0, -0.5},    //Coordenadas Vértice 6 V6
				{0.0 ,-3.0, 0.5},    //Coordenadas Vértice 7 V7
	};


	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 0.0, 0.0);
	glVertex3fv(vertice[0]); //se necesitan 4 vertices
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glColor3f(0.0, 0.0, 1.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glColor3f(0.0, 1.0, 0.0);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom

	glColor3f(0.4, 0.2, 0.6);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glColor3f(0.8, 0.2, 0.4);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void prisma1(void) //se dibija un prisma o cubo
{
	GLfloat vertice[8][3] = {
				{6.0 ,4.0, 0.5},    //Coordenadas Vértice 0 V0; cambia profundidad el eje Z
				{0.0 ,4.0, 0.5},    //Coordenadas Vértice 1 V1
				{0.0 ,4.0, -0.5},    //Coordenadas Vértice 2 V2
				{6.0 ,4.0, -0.5},    //Coordenadas Vértice 3 V3
				{6.0 ,5.0, 0.5},    //Coordenadas Vértice 4 V4
				{6.0 ,5.0, -0.5},    //Coordenadas Vértice 5 V5
				{0.0 ,5.0, -0.5},    //Coordenadas Vértice 6 V6
				{0.0 ,5.0, 0.5},    //Coordenadas Vértice 7 V7
	};


	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 0.0, 0.0);
	glVertex3fv(vertice[0]); //se necesitan 4 vertices
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glColor3f(0.0, 0.0, 1.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glColor3f(0.0, 1.0, 0.0);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom

	glColor3f(0.4, 0.2, 0.6);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glColor3f(0.8, 0.2, 0.4);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}



void prisma2(void) //se dibija un prisma o cubo
{
	GLfloat vertice[8][3] = {
				{0.5 ,-4.0, 0.5},    //Coordenadas Vértice 0 V0; cambia profundidad el eje Z
				{0.0 ,-4.0, 0.5},    //Coordenadas Vértice 1 V1
				{0.0 ,-4.0, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-4.0, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,5.0, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,5.0, -0.5},    //Coordenadas Vértice 5 V5
				{0.0 ,5.0, -0.5},    //Coordenadas Vértice 6 V6
				{0.0 ,5.0, 0.5},    //Coordenadas Vértice 7 V7
	};


	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 0.0, 0.0);
	glVertex3fv(vertice[0]); //se necesitan 4 vertices
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glColor3f(0.0, 0.0, 1.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glColor3f(0.0, 1.0, 0.0);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom

	glColor3f(0.4, 0.2, 0.6);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glColor3f(0.8, 0.2, 0.4);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}


void prisma3(void) //se dibija un prisma o cubo
{
	GLfloat vertice[8][3] = {
				{6.0 ,-4.0, 0.5},    //Coordenadas Vértice 0 V0; cambia profundidad el eje Z
				{5.5 ,-4.0, 0.5},    //Coordenadas Vértice 1 V1
				{5.5 ,-4.0, -0.5},    //Coordenadas Vértice 2 V2
				{6.0 ,-4.0, -0.5},    //Coordenadas Vértice 3 V3
				{6.0 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{6.0 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{5.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{5.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
	};


	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 0.0, 0.0);
	glVertex3fv(vertice[0]); //se necesitan 4 vertices
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glColor3f(0.0, 0.0, 1.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glColor3f(0.0, 1.0, 0.0);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom

	glColor3f(0.4, 0.2, 0.6);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glColor3f(0.8, 0.2, 0.4);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

//Letra D

void prisma4(void) //se dibija un prisma o cubo
{
	GLfloat vertice[8][3] = {
				{-5.0 ,-4.0, 0.5},    //Coordenadas Vértice 0 V0; cambia profundidad el eje Z
				{-5.5 ,-4.0, 0.5},    //Coordenadas Vértice 1 V1
				{-5.5 ,-4.0, -0.5},    //Coordenadas Vértice 2 V2
				{-5.0 ,-4.0, -0.5},    //Coordenadas Vértice 3 V3
				{-5.0 ,5.0, 0.5},    //Coordenadas Vértice 4 V4
				{-5.0 ,5.0, -0.5},    //Coordenadas Vértice 5 V5
				{-5.5 ,5.0, -0.5},    //Coordenadas Vértice 6 V6
				{-5.5 ,5.0, 0.5},    //Coordenadas Vértice 7 V7
	};


	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 0.0, 0.0);
	glVertex3fv(vertice[0]); //se necesitan 4 vertices
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glColor3f(0.0, 0.0, 1.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glColor3f(0.0, 1.0, 0.0);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom

	glColor3f(0.4, 0.2, 0.6);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glColor3f(0.8, 0.2, 0.4);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}



void prisma5(void) //se dibija un prisma o cubo
{
	GLfloat vertice[8][3] = {
				{-2.0 ,-2.0, 0.5},    //Coordenadas Vértice 0 V0; cambia profundidad el eje Z
				{-2.5 ,-2.0, 0.5},    //Coordenadas Vértice 1 V1
				{-2.5 ,-2.0, -0.5},    //Coordenadas Vértice 2 V2
				{-2.0 ,-2.0, -0.5},    //Coordenadas Vértice 3 V3
				{-2.0 ,3.0, 0.5},    //Coordenadas Vértice 4 V4
				{-2.0 ,3.0, -0.5},    //Coordenadas Vértice 5 V5
				{-2.5 ,3.0, -0.5},    //Coordenadas Vértice 6 V6
				{-2.5 ,3.0, 0.5},    //Coordenadas Vértice 7 V7
	};


	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 0.0, 0.0);
	glVertex3fv(vertice[0]); //se necesitan 4 vertices
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glColor3f(0.0, 0.0, 1.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glColor3f(0.0, 1.0, 0.0);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom

	glColor3f(0.4, 0.2, 0.6);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glColor3f(0.8, 0.2, 0.4);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void prisma6(void) //se dibija un prisma o cubo
{
	GLfloat vertice[8][3] = {
				{-2.0 ,3.0, 0.5},    //Coordenadas Vértice 0 V0; cambia profundidad el eje Z
				{-2.5 ,3.0, 0.5},    //Coordenadas Vértice 1 V1
				{-2.5 ,3.0, -0.5},    //Coordenadas Vértice 2 V2
				{-2.0 ,3.0, -0.5},    //Coordenadas Vértice 3 V3
				{-5.0 ,5.0, 0.5},    //Coordenadas Vértice 4 V4
				{-5.0 ,5.0, -0.5},    //Coordenadas Vértice 5 V5
				{-5.5 ,5.0, -0.5},    //Coordenadas Vértice 6 V6
				{-5.5 ,5.0, 0.5},    //Coordenadas Vértice 7 V7
	};


	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 0.0, 0.0);
	glVertex3fv(vertice[0]); //se necesitan 4 vertices
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glColor3f(0.0, 0.0, 1.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glColor3f(0.0, 1.0, 0.0);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom

	glColor3f(0.4, 0.2, 0.6);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glColor3f(0.8, 0.2, 0.4);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void prisma7(void) //se dibija un prisma o cubo
{
	GLfloat vertice[8][3] = {
				{-2.0 ,-2.0, 0.5},    //Coordenadas Vértice 0 V0; cambia profundidad el eje Z
				{-5.0 ,-4.0, 0.5},    //Coordenadas Vértice 1 V1
				{-5.0 ,-4.0, -0.5},    //Coordenadas Vértice 2 V2
				{-2.0 ,-2.0, -0.5},    //Coordenadas Vértice 3 V3
				{-2.5 ,-2.0, 0.5},    //Coordenadas Vértice 4 V4
				{-2.5 ,-2.0, -0.5},    //Coordenadas Vértice 5 V5
				{-5.5 ,-4.0, -0.5},    //Coordenadas Vértice 6 V6
				{-5.5 ,-4.0, 0.5},    //Coordenadas Vértice 7 V7
	};


	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 0.0, 0.0);
	glVertex3fv(vertice[0]); //se necesitan 4 vertices
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glColor3f(0.0, 0.0, 1.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glColor3f(0.0, 1.0, 0.0);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom

	glColor3f(0.4, 0.2, 0.6);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glColor3f(0.8, 0.2, 0.4);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}
*/


void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Poner Código Aquí.

//PARA DIBIJAR OTRO PRISMA
//glTranslated(0,0,-5);
//prisma();

//para rotar
//glRotatef(angleY,0,1,0);
	
	glTranslatef(transX, 0, transZ);
	prisma();

	//prisma0();

	//prisma1();
	
	//prisma2();

	//prisma3();

	//prisma4();

	//prisma5();

	//prisma6();

	//prisma7();

	glutSwapBuffers();
	//glFlush();
	// Swap The Buffers
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.1,20);	
	glFrustum(-.5, .5, -.5, .5, 0.1, 50.0);
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':
	case 'W':
		transZ += 0.2f;
		printf("Posicion en Z: %f\n", transZ);
		break;
	case 's':
	case 'S':
		transZ -= 0.2f;
		printf("Posicion en Z: %f\n", transZ);
		break;
	case 'a':
	case 'A':
		transX -= 0.2f;
		printf("Posicion en X: %f\n", transX);

		break;
	case 'd':
	case 'D':
		transX += 0.2f;
		printf("Posicion en X: %f\n", transX);
		break;
	case 'q':
	case 'Q':
		transY -= 0.2f;
		printf("Posicion en Y: %f\n", transY);

		break;
	case 'e':
	case 'E':
		transY += 0.2f;
		printf("Posicion en Y: %f\n", transY);
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 1.0f;
		break;
		//glutFullScreen ( ); // Full Screen Mode
		//break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 1.0f;
		break;
		//glutReshapeWindow ( 500, 500 ); // Cambiamos tamano de Ventana
		//break;
	case GLUT_KEY_LEFT:
		angleY += 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 1.0f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	//glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 3"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutMainLoop();          // 

	return 0;
}



