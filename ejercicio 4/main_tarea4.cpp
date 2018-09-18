//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//******* Alumno: GARCIA VILLAVICENCIO DAMAHE ITZEL  *********//
//*************				TAREA 4					******//
//*************			Visual Studio 2015				******//
//************************************************************//
//****Fecha de entrega 18 Sep 2018//
//**** Para mover la figura se utilizan las teclas :   *******//
//****  Derecha: tecla 'A'       *****************************//
//****  Izquierda: tecla 'D'     *****************************//
//****  Arriba: tecla 'Q'        *****************************//
//****  Abajo: tecla 'E'         *****************************//
//****  Acercar: tecla 'W'       *****************************//
//****  Alejar: tecla 'S'        *****************************//
//************************************************************//
#include "Main.h"

float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;
int screenW = 0.0;
int screenH = 0.0;


void InitGL ( void )     // Inicializamos parametros
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

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glColor3f(0.5, 0.4, 0.3);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glColor3f(0.0,0.0,1.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glColor3f(0.0,1.0,0.0);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glColor3f(1.0,1.0,1.0);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glColor3f(0.4,0.2,0.6);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glColor3f(0.8,0.2,0.4);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}


void prisma2(void)
{
	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};

	glBegin(GL_POLYGON);	//Front
	glColor3f(0.0, 0.0, 0.0);
	glVertex3fv(vertice[0]);
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


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, transY, transZ);//0
		
		/************CODIGO TAREA*******/
		
		glPushMatrix();//CUERPO
			glScalef(14.0, 10.0, 4.0);
			prisma();
		glPopMatrix();

		//PATITA DELANTERA IZQUIERDA
		glPushMatrix();//articulación 1
			glTranslatef(-5.5, -5.5, 1.25);
			glScalef(3.0, 1.0, 1.5);
			prisma();
		glPopMatrix();
		
		glPushMatrix();//pierna
			glTranslatef(-5.5, -7.5, 1.25);
			glScalef(3.0, 3.0, 1.5);
			prisma();
		glPopMatrix();

		glPushMatrix();//articulación 2
			glTranslatef(-5.5, -9.5, 1.25);
			glScalef(3.0, 1.0, 1.5);
			prisma();
		glPopMatrix();

		glPushMatrix();//patita
			glTranslatef(-5.5, -11.0, 1.25);
			glScalef(4.0, 2.0, 1.7);
			prisma();
		glPopMatrix();

		//PATITA DELANTERA DERECHA
		glPushMatrix();//articulación 1
			glTranslatef(5.5, -5.5, 1.25);
			glScalef(3.0, 1.0, 1.5);
			prisma();
		glPopMatrix();

		glPushMatrix();//pierna
			glTranslatef(5.5, -7.5, 1.25);
			glScalef(3.0, 3.0, 1.5);
			prisma();
		glPopMatrix();

		glPushMatrix();//articulación 2
			glTranslatef(5.5, -9.5, 1.25);
			glScalef(3.0, 1.0, 1.5);
			prisma();
		glPopMatrix();

		glPushMatrix();//patita
			glTranslatef(5.5, -11.0, 1.25);
			glScalef(4.0, 2.0, 1.7);
			prisma();
		glPopMatrix();

		//PATITA TRASERA IZQUIERDA
		glPushMatrix();//articulación 1
			glTranslatef(-5.5, -5.5, -1.25);
			glScalef(3.0, 1.0, 1.5);
			prisma();
		glPopMatrix();

		glPushMatrix();//pierna
			glTranslatef(-5.5, -7.5, -1.25);
			glScalef(3.0, 3.0, 1.5);
			prisma();
		glPopMatrix();

		glPushMatrix();//articulación 2
			glTranslatef(-5.5, -9.5, -1.25);
			glScalef(3.0, 1.0, 1.5);
			prisma();
		glPopMatrix();

		glPushMatrix();//patita
			glTranslatef(-5.5, -11.0, -1.25);
			glScalef(4.0, 2.0, 1.7);
			prisma();
		glPopMatrix();

		//PATITA TRASERA DERECHA
		glPushMatrix();//articulación 1
			glTranslatef(5.5, -5.5, -1.25);
			glScalef(3.0, 1.0, 1.5);
			prisma();
		glPopMatrix();

		glPushMatrix();//pierna
			glTranslatef(5.5, -7.5, -1.25);
			glScalef(3.0, 3.0, 1.5);
			prisma();
		glPopMatrix();

		glPushMatrix();//articulación 2
			glTranslatef(5.5, -9.5, -1.25);
			glScalef(3.0, 1.0, 1.5);
			prisma();
		glPopMatrix();

		glPushMatrix();//patita
			glTranslatef(5.5, -11.0, -1.25);
			glScalef(4.0, 2.0, 1.7);
			prisma();
		glPopMatrix();

		//CUELLO
		glPushMatrix();
			glTranslatef(0.0, 6.0, 1.5);
			glScalef(8.0, 10.0, 1.0);
			prisma();
		glPopMatrix();

		//CABEZA
		glPushMatrix();//CABECITA
			glTranslatef(0.0, 12.0, 1.7);
			glScalef(12.0, 11.0, 1.0);
			prisma();
		glPopMatrix();

		glPushMatrix();//hocico
			glTranslatef(0.0, 10.0, 2.0);
			glScalef(3.0, 2.0, 0.5);
			prisma2(); // Utilicé una segunda función para el cambio de color
		glPopMatrix();

		glPushMatrix();//ojo derecho
			glTranslatef(3.0, 14.0, 2.0);
			glScalef(2.0, 2.0, 0.5);
			prisma2(); //segunda función prisma
		glPopMatrix();

		glPushMatrix();//ojo izquierdo
			glTranslatef(-3.0, 14.0, 2.0);
			glScalef(2.0, 2.0, 0.5);
			prisma2(); //segunda función prisma
		glPopMatrix();

		//OREJA DERECHA
		glPushMatrix(); //Articulación 1
			glTranslatef(6.5, 15.0, 1.7);
			glScalef(1.0, 4.0, 1.0);
			prisma();
		glPopMatrix();

		glPushMatrix(); //Oreja
			glTranslatef(8.5, 14.0, 1.7);
			glScalef(3.0, 6.0, 1.0);
			prisma();
		glPopMatrix();

		//OREJA IZQUIERDA
		glPushMatrix(); //Articulación 1
			glTranslatef(-6.5, 15.0, 1.7);
			glScalef(1.0, 4.0, 1.0);
			prisma();
		glPopMatrix();

		glPushMatrix(); //Oreja
			glTranslatef(-8.5, 14.0, 1.7);
			glScalef(3.0, 6.0, 1.0);
			prisma();
		glPopMatrix();

		//COLA
		glPushMatrix(); //Oreja
			glTranslatef(0.0, 5.5, -2.3);
			glScalef(4.0, 16.0, 0.3);
			prisma();
		glPopMatrix();

  glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.8, 0.8, -0.8, 0.8, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.3f;
			break;
		
		case 's':
		case 'S':
			transZ -= 0.3f;
			break;
		
		case 'a':
		case 'A':
			transX += 0.3f;
			break;
		
		case 'd':
		case 'D':
			transX -= 0.3f;
			break;
		
		case 'q':
		case 'Q':
			transY += 0.3f;
			break;

		case 'e':
		case 'E':
			transY -= 0.3f;
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		break;
	case GLUT_KEY_LEFT:
		break;
	case GLUT_KEY_RIGHT:
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Tarea 4"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



