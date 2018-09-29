//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): Garcia Villavicencio Danahe Itzel*********************************//
//************* Practica 6      ****//
//*************	 Visual Estudio 2017										******//
//*************	 Fecha de entrega: 28 Septiembre 2018					*******//
//******	Este programa simula un	átomo***//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol = 0, 
	mercurio = 0,
	venus = 0,
	tierra = 0,
	luna = 0,
	marte = 0,
	luna2 = 0,
	jupiter = 0,
	luna3 = 0,
	saturno = 0,
	urano = 0;
float anillo = 0; //se elige flotante porque el movimiento tiene que ser mas lento


float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[]= { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX,0.0,-5.0+camaraZ);			//camara
	
	glPushMatrix();//atomo
		glPushMatrix();//nucleo
			glRotatef(sol,0.0,1.0,0.0);	//El Sol gira sobre su eje
			glColor3f(1.0,1.0,0.0 );	//Sol amarillo
			glutSolidSphere(1.9,12,12);  //Draw Sun (radio,H,V);
			glPushMatrix();//anillo
				glRotatef(mercurio, -1.0, 0.0, 0.0);	//Traslacion
				glColor3f(1.0, 0.6, 0.0);	//color naranja
				glRotatef(mercurio, 0.0, 0.0, 1.0); //Rotación
				glutSolidTorus(0.1, 3.2, 5, 10);//anillo
			glPopMatrix();//final de anillo
			
			glPushMatrix();//anillo
				glRotatef(sol, 1.0, 0.0, 0.0);	//Traslacion
				glColor3f(1.0, 0.6, 0.0);	//color naranja
				glRotatef(venus, 0.0, 0.0, 1.0); //Rotación
				glutSolidTorus(0.1, 3.9, 5, 10);//anillo
			glPopMatrix();//final de anillo

			glPushMatrix();//anillo 3
				glRotatef(sol, 0.0, 1.0, -1.0);	//Traslacion
				glColor3f(1.0, 0.6, 0.0);	//color naranja
				glRotatef(tierra, 0.0, 0.0, -1.0); //Rotación
				glutSolidTorus(0.1, 5.2, 5, 10);//anillo
			glPopMatrix();//final de anillo

			glPushMatrix();//anillo 4 
			glRotatef(sol, 0.0, 1.0, 1.0);	//Traslacion
			glColor3f(1.0, 0.6, 0.0);	//color naranja
			glRotatef(marte, 0.0, 0.0, 1.0); //Rotación
			glutSolidTorus(0.1, 7.2, 5, 10);//anillo
			glPopMatrix();//final de anillo

			glPushMatrix();//anillo 5
				glRotatef(sol, 0.0, -1.0, -1.0);	//Traslacion
				glColor3f(1.0, 0.6, 0.0);	//color naranja
				glRotatef(jupiter, 0.0, 1.0, 0.0); //Rotación
				glutSolidTorus(0.1, 10.2, 5, 10);//anillo
			glPopMatrix();//final de anillo

			glPushMatrix();//anillo 6
				glRotatef(sol, 0.0, 1.0, 1.0);	//Traslacion
				glColor3f(1.0, 0.6, 0.0);	//color naranja
				glRotatef(saturno, 0.0, 1.0, 0.0); //Rotación
				glutSolidTorus(0.1, 13.2, 5, 10);//anillo
			glPopMatrix();//final de anillo

			glPushMatrix();//anillo 7
				glRotatef(sol, 0.0, -1.0, 1.0);	//Traslacion
				glColor3f(1.0, 0.6, 0.0);	//color naranja
				glRotatef(urano, 0.0, 1.0, 0.0); //Rotación
				glutSolidTorus(0.1, 16, 5, 10);//anillo
			glPopMatrix();//final de anillo
		glPopMatrix();//final sol

		//creacion de las moleculas
		glPushMatrix();//Mercurio
			glRotatef(sol, 0.0, 0.0, 1.0);	//Traslacion
			glTranslatef(3.2,0,0);        //que tan lejos estara del sol
			glRotatef(mercurio, 0, 1, 0); //Rotación
			glColor3f(0.5, 0.5, 0.5);	//color gris
			glutSolidSphere(0.3, 8, 8);  //Draw Sun (radio,H,V);
		glPopMatrix();
		
		glPushMatrix();//venus
			glRotatef(sol, 0.0, 1.0, 0.0);	//Traslacion
			glTranslatef(3.9, 0, 0);
			glRotatef(venus, 0, 1, 0); //Rotación
			glColor3f(1.0, 0.3, 0.0);	//color naranja
			glutSolidSphere(0.4, 8, 8);  //Draw Sun (radio,H,V);
		glPopMatrix();//final venus
	
		glPushMatrix();//tierra
			glRotatef(sol, 0.0, 0.0, -1.0);	//Traslacion
			glTranslatef(5.2, 0, 0);
			glRotatef(tierra, 0, 1, 0); //Rotación
			glColor3f(0.0, 0.4, 1.0);	//color azul
			glutSolidSphere(0.4, 8, 8);  //Draw Sun (radio,H,V);
		glPopMatrix();//final tierra

		glPushMatrix();//marte
			glRotatef(sol, 0.0, -1.0, 0.0);	//Traslacion
			glTranslatef(7.2, 0, 0);
			glRotatef(marte, 0, 1, 0); //Rotación
			glColor3f(1.0, 0.0, 0.3);	//color rosa
			glutSolidSphere(0.3, 8, 8);  //Draw Sun (radio,H,V);
		glPopMatrix();//final marte

		glPushMatrix();//jupiter
			glRotatef(sol, 0.0, -1.0, -1.0);	//Traslacion
			glTranslatef(10.2, 0, 0);
			glRotatef(jupiter, 0, 1, 0); //Rotación
			glColor3f(1.0, 0.7, 0.6);	//color rosa
			glutSolidSphere(0.9, 8, 8);  //Draw Sun (radio,H,V);
		glPopMatrix();//final jupiter

		glPushMatrix();//saturno
			glRotatef(sol, 0.0, -1.0, 1.0);	//Traslacion
			glTranslatef(13.2, 0, 0);
			glRotatef(saturno, 1, 1, 0); //Rotación
			glColor3f(0.5, 1.0, 0.5);	//color verde agua
			glutSolidSphere(1.0, 8, 8);  //Draw Sun (radio,H,V);
		glPopMatrix();

		glPushMatrix();//urano
		glRotatef(sol, 0.0, 1.0, 1.0);	//Traslacion
			glTranslatef(16, 0, 0);
			glRotatef(urano, 0, 1, 0); //Rotación
			glColor3f(0.2, 0.0, 1.0);	//color azul
			glutSolidSphere(0.8, 8, 8);  //Draw Sun (radio,H,V);
		glPopMatrix();//final de urano
	glPopMatrix();//final del sistema solar
	
	glutSwapBuffers ( );

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if(dwElapsedTime >= 30)
	{
		sol = (sol - 5) % 360;
		mercurio = (mercurio - 4) % 360;
		venus = (venus - 3) % 360;
		tierra = (tierra - 2) % 360;
		marte = (marte - 1) % 360;
		jupiter = (jupiter + 2) % 360;
		saturno = (saturno) % 360;
		anillo = anillo + 0.5;
		urano = (urano - 2) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
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
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			camaraZ +=0.5f;
			break;
		case 's':
		case 'S':
			camaraZ -=0.5f;
			break;
		case 'a':
		case 'A':
			camaraX -= 0.5f;
			break;
		case 'd':
		case 'D':
			camaraX += 0.5f;
			break;

		case 'i':		//Movimientos de Luz
		case 'I':
			
			break;
		case 'k':
		case 'K':
			
			break;

		case 'l':   //Activamos/desactivamos luz
		case 'L':
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
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		
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
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}