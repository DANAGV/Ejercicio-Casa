//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//***** Alumno (s): Garcia Villavicencio Danahe***************//
//********     fecha de entrega: 25 Septiembre 2018***********//
//**********	Visual estudio 2017					**********//
//	para poder manipular el movimiento del robot se necesitara del teclado como se indica	
//	en todos los casos puede ser minúscula o mayúscula	//
//**********	movimientos del eje "x" con teclas:	
//*****		"A" lado izquierdo,					"D" lado derecho	******//
//***********	movimientos del eje "y" con teclas:	******//
//****		"Q" hacia arriba						"E" hacia abajo ***//
//*********movimiento del eje z con teclas: ********//
//*****		"W" hacia enfrente           "S" hacia atras//
//Para los brazos del robot son:
//     brazo derecho "C" abajo   "c"  arriba
//		brazo izquierdo    "Z"  ARRIBA     z   ABAJO
//
//************************************************************//
//************************************************************//
#include "Main.h"

float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f,
	movCodo = 0.0,
	movCodo2 = 0.0,
	movMuñeca = 0.0,
	movDedo1 = 0.0,
	movDedo1a = 0.0,
	movDedo2 = 0.0,
	movDedo2a = 0.0,
	movDedo3 = 0.0,
	movDedo3a = 0.0,
	movDedo4 = 0.0,
	movDedo4a = 0.0,	movDedo5 = 0.0,
	movDedo5a = 0.0;
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
			glColor3f(1.0,0.0,0.0);
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

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, transY, transZ);//0
		//poner codigo aqui
		
		/************CODIGO CLASE*******/
		
		//glRotatef(45, 0, 0, 1); //primero el angulo, después el eje donde queremos que rote
		//glScalef(4, 6, 1); //puede ser de cualquier tamaño en cualquier eje
		//prisma();
		//glTranslatef(1.0, 1.0, 0);
		//prisma();
		//glTranslatef(0.0, -2.0, 0);
		//prisma();
  		
		glPushMatrix();//TORSO 
			glTranslatef(0.0, 2.0, 0.0);
			glScalef(10, 10, 5);
			prisma();
		glPopMatrix();
		
		glPushMatrix();//CUELLO
			glTranslatef(0.0, 7.5, 0.0);
			glScalef(4.0, 1.0, 5.0);
			prisma();
		glPopMatrix();
		
		glPushMatrix();//CABEZA
			glTranslatef(0.0, 10.5, 0.0);
			glScalef(6.0, 5.0, 5.0);
			prisma();
		glPopMatrix();

		//BRAZO DERECHO
		glPushMatrix();//articulación 1
			glRotatef(movCodo, 0.0, 0.0, 1.0);
			glTranslatef(5.5, 5.5, 0.0);
			glScalef(1.0, 3.0, 5.0);
			prisma();
		glPopMatrix();

		glPushMatrix();//antebrazo 1
			glRotatef(movCodo, 0.0, 0.0, 1.0);
			glTranslatef(7.5, 5.5, 0.0);
			glScalef(3.0, 3.0, 5.0);
			prisma();
		glPopMatrix();

		glPushMatrix();//articulación 2
			glRotatef(movCodo, 0.0, 0.0, 1.0);
			glTranslatef(9.5, 5.5, 0.0);
			glScalef(1.0, 3.0, 5.0);
			prisma();
		glPopMatrix();

		glPushMatrix();//antebrazo 2
			glRotatef(movCodo, 0.0, 0.0, 1.0);
			glTranslatef(11.5, 5.5, 0.0);
			glScalef(3.0, 3.0, 5.0);
			prisma();
		glPopMatrix();

		glPushMatrix();//muñeca
			glRotatef(movCodo, 0.0, 0.0, 1.0);
			glTranslatef(13.5, 5.5, 0.0);
			glScalef(1.0, 3.0, 5.0);
			prisma();
		glPopMatrix();

		//MANO DERECHA
		glPushMatrix();
			glRotatef(movCodo, 0.0, 0.0, 1.0);
			glTranslatef(15.0, 5.5, 0.0);
			glScalef(2.0, 4.0, 5.0);
			prisma();
		glPopMatrix();


		//BRAZO IZQUIERDO
		glPushMatrix();//articulación 1
			glRotatef(movCodo2, 0.0, 0.0, 1.0);
			glTranslatef(-5.5, 5.5, 0.0);
			glScalef(1.0, 3.0, 5.0);
			prisma();
		glPopMatrix();

		glPushMatrix();//antebrazo 1
			glRotatef(movCodo2, 0.0, 0.0, 1.0);
			glTranslatef(-7.5, 5.5, 0.0);
			glScalef(3.0, 3.0, 5.0);
			prisma();
		glPopMatrix();

		glPushMatrix();//articulación 2
			glRotatef(movCodo2, 0.0, 0.0, 1.0);
			glTranslatef(-9.5, 5.5, 0.0);
			glScalef(1.0, 3.0, 5.0);
			prisma();
		glPopMatrix();

		glPushMatrix();//antebrazo 2
			glRotatef(movCodo2, 0.0, 0.0, 1.0);
			glTranslatef(-11.5, 5.5, 0.0);
			glScalef(3.0, 3.0, 5.0);
			prisma();
		glPopMatrix();
		
		glPushMatrix();//muñeca
			glRotatef(movCodo2, 0.0, 0.0, 1.0);
			glTranslatef(-13.5, 5.5, 0.0);
			glScalef(1.0, 3.0, 5.0);
			prisma();
			glPopMatrix();
	
		glPushMatrix();//MANO IZQUIERDA
			glRotatef(movCodo2, 0.0, 0.0, 1.0);
			glTranslatef(-15.0, 5.5, 0.0);
			glScalef(2.0, 4.0, 5.0);
			prisma();
		glPopMatrix();

		//CINTURA
		glPushMatrix();
			glTranslatef(0.0, -4.0, 0.0);
			glScalef(9.0, 2.0, 5.0);
			prisma();
		glPopMatrix();
		
		//CADERA
		glPushMatrix();
			glTranslatef(0.0, -6.5, 0.0);
			glScalef(10.0, 3.0, 5.0);
			prisma();
		glPopMatrix();

		//PIERNA DERECHA
		glPushMatrix();//articulación 1
			glTranslatef(3.5, -8.5, 0.0);
			glScalef(3.0, 1.0, 5.0);
			prisma();
		glPopMatrix();

		glPushMatrix();//muslo
			glTranslatef(3.5, -10.5, 0.0);
			glScalef(3.0, 3.0, 5.0);
			prisma();
		glPopMatrix();

		glPushMatrix();//rodilla
			glTranslatef(3.5, -12.5, 0.0);
			glScalef(3.0, 1.0, 5.0);
			prisma();
		glPopMatrix();

		glPushMatrix();//pantorrilla
			glTranslatef(3.5, -14.5, 0.0);
			glScalef(3.0, 3.0, 5.0);
			prisma();
		glPopMatrix();

		glPushMatrix();//tobillo
			glTranslatef(3.5, -16.5, 0.0);
			glScalef(3.0,1.0, 5.0);
			prisma();
		glPopMatrix();

		glPushMatrix();//PIE DERECHO
			glTranslatef(3.5, -18.0, 0.0);
			glScalef(4.0, 2.0, 5.0);
			prisma();
		glPopMatrix();

		//PIERNA IZQUIERDA
		glPushMatrix();//articulación 1
			glTranslatef(-3.5, -8.5, 0.0);
			glScalef(3.0, 1.0, 5.0);
			prisma();
		glPopMatrix();
		
		glPushMatrix();//muslo
			glTranslatef(-3.5, -10.5, 0.0);
			glScalef(3.0, 3.0, 5.0);
			prisma();
		glPopMatrix();

		glPushMatrix();//rodilla
			glTranslatef(-3.5, -12.5, 0.0);
			glScalef(3.0, 1.0, 5.0);
			prisma();
		glPopMatrix();

		glPushMatrix();//pantorrilla
			glTranslatef(-3.5, -14.5, 0.0);
			glScalef(3.0, 3.0, 5.0);
			prisma();
		glPopMatrix();

		glPushMatrix();//tobillo
			glTranslatef(-3.5, -16.5, 0.0);
			glScalef(3.0, 1.0, 5.0);
			prisma();
		glPopMatrix();

		glPushMatrix();//PIE IZQUIERDO
			glTranslatef(-3.5, -18.0, 0.0);
			glScalef(4.0, 2.0, 5.0);
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
	glFrustum (-0.9, 0.9, -0.9, 0.9, 0.1, 50.0);

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
		
		case 'd':
		case 'D':
			transX += 0.3f;
			break;
		
		case 'a':
		case 'A':
			transX -= 0.3f;
			break;
		
		case 'q':
		case 'Q':
			transY += 0.3f;
			break;

		case 'e':
		case 'E':
			transY -= 0.3f;
			break;		case 'c':
			if (90.0 > movCodo)
				movCodo += 1.0f;
			break;

		case 'C':
			if (-100.0 < movCodo)
				movCodo -= 1.0f;
			break;		case 'z':
			if (90.0 > movCodo2)
				movCodo2 += 1.0f;
			break;

		case 'Z':
			if (-100.0 < movCodo2)
				movCodo2 -= 1.0f;
			break;
		case 'm':
			if (5.0 > movMuñeca)
				movMuñeca += 2.5;
			break;
		case 'M':
			if (-95.0 < movMuñeca)
				movMuñeca -= 2.5;
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
  glutCreateWindow    ("Practica 4"); // Nombre de la Ventana
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



