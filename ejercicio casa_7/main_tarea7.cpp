//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//****** Alumno: Garcia Villavicencio Danahe Itzel ***********//
//******** Fecha de entrega: 08 Octubre 2018 ***************//
//*************				PRACTICA 7				**********//
//*************			Visual Studio 2017				******//
//************************************************************//
//**********Este programa simula un sistema solar ************//
//********** agregando colores y luz a los planetas***********//
//*************           materiales          ****************//
//**** Para mover el teclado:    *****************************//
//****  Derecha: teclas 'A' 'a'      *************************//
//****  Izquierda: teclas 'D' 'd'    *************************//
//****  Arriba: teclas 'Q' 'q'       *************************//
//****  Abajo: teclas 'E' 'e'         ************************//
//****  Acercar: teclas 'W' 'w'      *************************//
//****  Alejar: teclas 'S' 's'       *************************//
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
float camaraZ = 0.0;
float camaraX = 0.0;
float camaraY = 0.0;


GLfloat LuzAmbientalSol[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat LuzDifusaSol[] = { 1.0f, 1.0f, 1.0f, 1.0f };				// Specular Light Values
GLfloat LuzEspecularSol[] = { 0.0f, 1.0f, 1.0f, 1.0f };			// Light Position
GLfloat LuzPosicionSol[] = { 0.0f, 0.0f, 0.0f, 10.0f };

GLfloat AmbientalMercurio[] = { 0.5f, 0.5f, 0.5f, 1.0f };        //color
GLfloat DiffuseMercurio[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Mercurio
GLfloat SpecularMercurio[] = { 1.0f, 0.5f, 0.0f, 1.0f };
GLfloat ShininessMercurio[] = { 50.0 };

GLfloat AmbientalVenus[] = { 1.0, 0.3, 0.0, 1.0f };
GLfloat DiffuseVenus[] = { 0.8f, 0.8f, 0.8f, 1.0f };			//Venus
GLfloat SpecularVenus[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat ShininessVenus[] = { 50.0 };

GLfloat AmbientalTierra[] = { 0.0f, 1.0f, 1.0f, 1.0f };
GLfloat DiffuseTierra[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// Tierra
GLfloat SpecularTierra[] = { 0.5, 0.5, 0.8, 1.0 };
GLfloat ShininessTierra[] = { 50.0 };

GLfloat AmbientalLuna[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat DiffuseLuna[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat SpecularLuna[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat ShininessLuna[] = { 50.0 };

GLfloat AmbientalMarte[] = { 1.0f, 0.0f, 0.0f, 1.0f };
GLfloat DiffuseMarte[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat SpecularMarte[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat ShininessMarte[] = { 50.0 };


GLfloat AmbientalLuna2[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat DiffuseLuna2[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// Luna2
GLfloat SpecularLuna2[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat ShininessLuna2[] = { 50.0 };

GLfloat AmbientalJupiter[] = { 1.0, 0.7, 0.6, 1.0f };
GLfloat DiffuseJupiter[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// jupiter
GLfloat SpecularJupiter[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat ShininessJupiter[] = { 50.0 };

GLfloat AmbientalLuna3[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat DiffuseLuna3[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Luna3
GLfloat SpecularLuna3[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat ShininessLuna3[] = { 50.0 };


GLfloat AmbientalSaturno[] = { 0.5, 1.0, 0.5, 1.0f };
GLfloat DiffuseSaturno[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// saturno
GLfloat SpecularSaturno[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat ShininessSaturno[] = { 50.0 };

GLfloat AmbientalAnillo[] = { 1.0, 0.6, 0.0, 1.0f };
GLfloat DiffuseAnillo[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// anillo
GLfloat SpecularAnillo[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat ShininessAnillo[] = { 50.0 };

GLfloat AmbientalUrano[] = { 0.2, 0.0, 1.0,1.0f };
GLfloat DiffuseUrano[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// urano
GLfloat SpecularUrano[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat ShininessUrano[] = { 50.0 };

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glLightfv(GL_LIGHT1, GL_AMBIENT, LuzAmbientalSol);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LuzDifusaSol);
	glLightfv(GL_LIGHT1, GL_SPECULAR, LuzEspecularSol);

	glEnable(GL_LIGHT1);

}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX,camaraY,-5.0+camaraZ);			//camara

	glLightfv(GL_LIGHT1, GL_POSITION, LuzPosicionSol),
		glEnable(GL_LIGHTING);

	glPushMatrix();//sistema solar

		glPushMatrix();//inicio sol
			glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
			glDisable(GL_LIGHTING);
			glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
			glutSolidSphere(1.9, 12, 12);  //Draw Sun (radio,H,V);
			glEnable(GL_LIGHTING);
		glPopMatrix();//final sol

	glPushMatrix();//Mercurio
		glRotatef(mercurio, 0.0, 1.0, 0.0);	//Traslacion
		glTranslatef(3.2, 0, 0);        //que tan lejos estara del sol
		glRotatef(mercurio, 0, 1, 0); //Rotaci—n
			//cambio la variable de color
			glMaterialfv(GL_FRONT, GL_AMBIENT, AmbientalMercurio);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, DiffuseMercurio);
			glMaterialfv(GL_FRONT, GL_SPECULAR, SpecularMercurio);
			glMaterialfv(GL_FRONT, GL_SHININESS, ShininessMercurio);
			glutSolidSphere(0.3, 8, 8);  //Draw Sun (radio,H,V);
		glPopMatrix();//final mercurio

		glPushMatrix();//venus
			glRotatef(venus, 0.0, 1.0, 0.0);	//Traslacion
			glTranslatef(4.2, 0, 0);
			glRotatef(venus, 0, 1, 0); //Rotaci—n
			glMaterialfv(GL_FRONT, GL_AMBIENT, AmbientalVenus);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, DiffuseVenus);
			glMaterialfv(GL_FRONT, GL_SPECULAR, SpecularVenus);
			glMaterialfv(GL_FRONT, GL_SHININESS, ShininessVenus);
			glutSolidSphere(0.4, 8, 8);
		glPopMatrix();//final venus

		glPushMatrix();//tierra
			glRotatef(tierra, 0.0, 1.0, 0.0);	//Traslacion
			glTranslatef(5.2, 0, 0);
			glRotatef(tierra, 0, 1, 0); //Rotaci—n
			glMaterialfv(GL_FRONT, GL_AMBIENT, AmbientalTierra);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, DiffuseTierra);
			glMaterialfv(GL_FRONT, GL_SPECULAR, SpecularTierra);
			glMaterialfv(GL_FRONT, GL_SHININESS, ShininessTierra);
			glutSolidSphere(0.4, 8, 8);
			glPushMatrix();//luna de la tierra
				glRotatef(luna, 0.0, 1.0, 0.0);	//Traslacion
				glTranslatef(0.7, 0, 0);
				glRotatef(luna, 0, 1, 0); //Rotaci—n
				glMaterialfv(GL_FRONT, GL_AMBIENT, AmbientalLuna);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, DiffuseLuna);
				glMaterialfv(GL_FRONT, GL_SPECULAR, SpecularLuna);
				glMaterialfv(GL_FRONT, GL_SHININESS, ShininessLuna);
				glutSolidSphere(0.2, 8, 8);  //Draw Sun (radio,H,V);
			glPopMatrix();//final de luna
		glPopMatrix();//final de tierra

		glPushMatrix();//marte
			glRotatef(marte, 0.0, 1.0, 0.0);	//Traslacion
			glTranslatef(7.2, 0, 0);
			glRotatef(marte, 0, 1, 0); //Rotaci—n
			glMaterialfv(GL_FRONT, GL_AMBIENT, AmbientalMarte);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, DiffuseMarte);
			glMaterialfv(GL_FRONT, GL_SPECULAR, SpecularMarte);
			glMaterialfv(GL_FRONT, GL_SHININESS, ShininessMarte);
			glutSolidSphere(0.3, 8, 8);  //Draw Sun (radio,H,V);
			//se agregan 2 lunas
			glPushMatrix();//luna1
				glRotatef(luna, 0.0, 1.0, 0.0);	//Traslacion
				glTranslatef(0.5, 0, 0);
				glRotatef(luna, 0, 1, 0); //Rotaci—n
				glMaterialfv(GL_FRONT, GL_AMBIENT, AmbientalLuna);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, DiffuseLuna);
                glMaterialfv(GL_FRONT, GL_SPECULAR, SpecularLuna);
                glMaterialfv(GL_FRONT, GL_SHININESS, ShininessLuna);
				//glColor3f(0.5, 0.5, 0.5);	//color gris
				glutSolidSphere(0.1, 3, 3);  //Draw Sun (radio,H,V);
			glPopMatrix();//fin luna1
			glPushMatrix();//luna2
			glRotatef(luna2, 0.0, -1.0, 0.0);	//Traslacion
				glTranslatef(0.5, 0, 0);
				glRotatef(luna2, 0, 1, 0); //Rotaci—n
				glMaterialfv(GL_FRONT, GL_AMBIENT, AmbientalLuna2);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, DiffuseLuna2);
                glMaterialfv(GL_FRONT, GL_SPECULAR, SpecularLuna2);
                glMaterialfv(GL_FRONT, GL_SHININESS, ShininessLuna2);
				//glColor3f(0.5, 0.5, 0.5);	//color gris
				glutSolidSphere(0.1, 6, 6);  //Draw Sun (radio,H,V);
			glPopMatrix();//luna2
		glPopMatrix();//marte

		glPushMatrix();//jupiter
			glRotatef(jupiter, 0.0, 1.0, 0.0);	//Traslacion
			glTranslatef(10.2, 0, 0);
			glRotatef(jupiter, 0, 1, 0); //Rotaci—n
			glMaterialfv(GL_FRONT, GL_AMBIENT, AmbientalJupiter);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, DiffuseJupiter);
			glMaterialfv(GL_FRONT, GL_SPECULAR, SpecularJupiter);
			glMaterialfv(GL_FRONT, GL_SHININESS, ShininessJupiter);
			//glColor3f(1.0, 0.7, 0.6);	//color rosa
			glutSolidSphere(0.9, 8, 8);  //Draw Sun (radio,H,V);
			glPushMatrix();//luna
				glRotatef(jupiter, 0.0, 1.0, 1.0);	//Traslacion
				glTranslatef(1.0, 0, 0);
				glRotatef(luna, 0, -1, 0); //Rotaci—n
				glMaterialfv(GL_FRONT, GL_AMBIENT, AmbientalLuna);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, DiffuseLuna);
                glMaterialfv(GL_FRONT, GL_SPECULAR, SpecularLuna);
                glMaterialfv(GL_FRONT, GL_SHININESS, ShininessLuna);
				glColor3f(0.5, 0.5, 0.5);	//color gris
				glutSolidSphere(0.2, 8, 8);  //Draw Sun (radio,H,V);
			glPopMatrix();//final luna
			glPushMatrix();//luna2
				glRotatef(jupiter, 0.0, -1.0, 0.0);	//Traslacion
				glTranslatef(1.0, 0, 0);
				glRotatef(luna2, 0, 1, 0); //Rotaci—n
				glMaterialfv(GL_FRONT, GL_AMBIENT, AmbientalLuna2);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, DiffuseLuna2);
                glMaterialfv(GL_FRONT, GL_SPECULAR, SpecularLuna2);
                glMaterialfv(GL_FRONT, GL_SHININESS, ShininessLuna2);
				//glColor3f(0.5, 0.5, 0.5);	//color gris
				glutSolidSphere(0.2, 8, 8);  //Draw Sun (radio,H,V);
			glPopMatrix();//final luna2
			glPushMatrix();//luna3
				glRotatef(jupiter, 0.0, 1.0, 1.0);	//Traslacion
				glTranslatef(1.0, 0, 0);
				glRotatef(luna3, 0, 1, 0); //Rotaci—n
				glMaterialfv(GL_FRONT, GL_AMBIENT, AmbientalLuna3);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, DiffuseLuna3);
                glMaterialfv(GL_FRONT, GL_SPECULAR, SpecularLuna3);
                glMaterialfv(GL_FRONT, GL_SHININESS, ShininessLuna3);
				//glColor3f(0.5, 0.5, 0.5);	//color gris
				glutSolidSphere(0.2, 8, 8);  //Draw Sun (radio,H,V);
			glPopMatrix();//final luna3
		glPopMatrix();//final jupiter

		glPushMatrix();//saturno
			glRotatef(saturno, 0.0, 1.0, 0.0);	//Traslacion
			glTranslatef(13.2, 0, 0);
			glRotatef(saturno, 0, 1, 0); //Rotaci—n
			glMaterialfv(GL_FRONT, GL_AMBIENT, AmbientalSaturno);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, DiffuseSaturno);
            glMaterialfv(GL_FRONT, GL_SPECULAR, SpecularSaturno);
            glMaterialfv(GL_FRONT, GL_SHININESS, ShininessSaturno);
			//glColor3f(0.5, 1.0, 0.5);	//color verde agua
			glutSolidSphere(1.0, 8, 8);  //Draw Sun (radio,H,V);

		glPushMatrix();//anillo saturno
			glRotatef(saturno, 1.0, 0.0, 0.0);	//Traslacion
			//glColor3f(1.0, 0.6, 0.0);	//color naranja
			glMaterialfv(GL_FRONT, GL_AMBIENT, AmbientalAnillo);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, DiffuseAnillo);
            glMaterialfv(GL_FRONT, GL_SPECULAR, SpecularAnillo);
            glMaterialfv(GL_FRONT, GL_SHININESS, ShininessAnillo);
			glutSolidTorus(0.2, 2, 5, 10);//anillo
			glPopMatrix();//final de anillo
		glPopMatrix();//final de saturno

		glPushMatrix();//urano
			glRotatef(urano, 0.0, 1.0, 0.0);	//Traslacion
			glTranslatef(16, 0, 0);
			glRotatef(urano, 0, 1, 0); //Rotaci—n
			glMaterialfv(GL_FRONT, GL_AMBIENT, AmbientalUrano);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, DiffuseUrano);
            glMaterialfv(GL_FRONT, GL_SPECULAR, SpecularUrano);
            glMaterialfv(GL_FRONT, GL_SHININESS, ShininessUrano);
			//glColor3f(0.2, 0.0, 1.0);	//color azul
			glutSolidSphere(0.8, 8, 8);  //Draw Sun (radio,H,V);
		glPopMatrix();//final de urano

	glPopMatrix();//fin SistemaSolar

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
		mercurio = (mercurio - 5) % 360;
		venus = (venus - 4) % 360;
		tierra = (tierra - 2) % 360;
		luna = (luna - 1) % 360;
		luna2 = (luna2 - 2) % 360;
		luna3 = (luna3 - 3) % 360;
		marte = (marte - 3) % 360;
		jupiter = (jupiter - 2) % 360;
		saturno = (saturno - 1) % 360;
		urano = (urano - 1) % 360;

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

		case 'q':
		case 'Q':
			camaraY -= 0.5f;
			break;
		case 'e':
		case 'E':
			camaraY += 0.5f;
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
  glutInitWindowSize  (500, 500);	// Tama–o de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut funci—n de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut funci—n en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut funci—n de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          //

  return 0;
}
