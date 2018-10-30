//Semestre 2019 - 1
//************** Alumno (s): *********************************//
//*************       Garcia Villavicencio Danahe        ******//
//************ Visual Studio 2017	*************//
//***** Fecha de entrega: 29 Octuvre 2018***//
//************************************************************//
//****** Mano que realiza las señas OK PAZ Y ROCK *******//
//***** Teclas de manipulacion de la mano***//
//********Dedo pulgar (completo) "V" enfrente "v" atras ---- (mitad) "P" enfrente "p" atras	************//
//********Dedo indice (completo) "Y" enfrente "y" atras ---- (mitad) "U" enfrente "u" atras	************//
//********Dedo pulgar (completo) "N" enfrente "n" atras ---- (mitad) "M" enfrente "m" atras	************//
//********Dedo pulgar (completo) "J" enfrente "j" atras ---- (mitad) "B" enfrente "b" atras	************//
//********Dedo meñique (completo) "T" enfrente "t" atras ---- (mitad) "R" enfrente "r" atras	************//
//********	Muñeca "C"************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include "cmodel/CModel.h"
#include "Main.h"

static GLuint ciudad_display_list;	//Display List for the Monito

									//NEW// Keyframes
									//Variables de dibujo y manipulacion									// 1)
float	transX = 0.0,
transZ = -5.0f,
angleX = 0.0,
angleY = 0.0,
Hombro = 0.0,
Codo = 0.0,
Dedo1 = 0.0,
Dedo1a = 0.0,
Dedo2 = 0.0,
Dedo2a = 0.0,
Dedo3 = 0.0,
Dedo3a = 0.0,
Dedo4 = 0.0,
Dedo4a = 0.0,
Dedo5 = 0.0,
Dedo5a = 0.0;
#define MAX_FRAMES 50
int i_max_steps = 90;
int i_curr_steps = 0;

typedef struct _frame
{
	float transX;
	float inctransx;
	float transZ;
	float inctransz;
	float angleX;
	float incanglex;
	float angleY;
	float incangley;
	float Hombro;
	float movHombro;
	float Codo;
	float movCodo;
	float Dedo1;
	float movDedo1;
	float Dedo1a;
	float movDedo1a;
	float Dedo2;
	float movDedo2;
	float Dedo2a;
	float movDedo2a;
	float Dedo3;
	float movDedo3;
	float Dedo3a;
	float movDedo3a;
	float Dedo4;
	float movDedo4;
	float Dedo4a;
	float movDedo4a;
	float Dedo5;
	float movDedo5;
	float Dedo5a;
	float movDedo5a;
}FRAME;


FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 0;			//introducir datos
bool play = false;
int playIndex = 0;


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int w = 500, h = 500;
int frame = 0, time, timebase = 0;
char s[30];

float	red[3] = { 1.0, 0.0, 0.0 }, //colores
green[3] = { 0.0,1.0,0.0 },
blue[3] = { 0.0,0.0,1.0 },
white[3] = { 1.0,1.0,1.0 },
yellow[3] = { 1.0,1.0,0.0 };

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font = (int)GLUT_BITMAP_HELVETICA_18;

//GUARDAMOS LOS FRAMES QUE SE PUEDEN HACER
void saveFrame(void)
{
	printf("frameindex %d \n", FrameIndex);

	KeyFrame[FrameIndex].transX = transX;
	KeyFrame[FrameIndex].transZ = transZ;
	KeyFrame[FrameIndex].angleX = angleX;
	KeyFrame[FrameIndex].angleY = angleY;
	KeyFrame[FrameIndex].Hombro = Hombro;
	KeyFrame[FrameIndex].Codo = Codo;
	KeyFrame[FrameIndex].Dedo1 = Dedo1;
	KeyFrame[FrameIndex].Dedo1a = Dedo1a;
	KeyFrame[FrameIndex].Dedo2 = Dedo2;
	KeyFrame[FrameIndex].Dedo2a = Dedo2a;
	KeyFrame[FrameIndex].Dedo3 = Dedo3;
	KeyFrame[FrameIndex].Dedo3a = Dedo3a;
	KeyFrame[FrameIndex].Dedo4 = Dedo4;
	KeyFrame[FrameIndex].Dedo4a = Dedo4a;
	KeyFrame[FrameIndex].Dedo5 = Dedo5;
	KeyFrame[FrameIndex].Dedo5a = Dedo5a;
	FrameIndex++;

}

void resetElements(void)
{
	transX = KeyFrame[0].transX;
	transZ = KeyFrame[0].transZ;
	angleX = KeyFrame[0].angleX;
	angleY = KeyFrame[0].angleY;
	Hombro = KeyFrame[0].Hombro;
	Codo = KeyFrame[0].Codo;
	Dedo1 = KeyFrame[0].Dedo1;
	Dedo1a = KeyFrame[0].Dedo1a;
	Dedo2 = KeyFrame[0].Dedo2;
	Dedo2a = KeyFrame[0].Dedo2a;
	Dedo3 = KeyFrame[0].Dedo3;
	Dedo3a = KeyFrame[0].Dedo3a;
	Dedo4 = KeyFrame[0].Dedo4;
	Dedo4a = KeyFrame[0].Dedo4a; 
	Dedo5 = KeyFrame[0].Dedo5;
	Dedo5a = KeyFrame[0].Dedo5a;

}
void interpolation(void)
{
	KeyFrame[playIndex].inctransx = (KeyFrame[playIndex + 1].transX - KeyFrame[playIndex].transX) / i_max_steps;
	KeyFrame[playIndex].inctransz = (KeyFrame[playIndex + 1].transZ - KeyFrame[playIndex].transZ) / i_max_steps;
	KeyFrame[playIndex].angleX = (KeyFrame[playIndex + 1].incanglex - KeyFrame[playIndex].incanglex) / i_max_steps;
	KeyFrame[playIndex].angleY = (KeyFrame[playIndex + 1].incangley - KeyFrame[playIndex].incangley) / i_max_steps;
	KeyFrame[playIndex].movHombro = (KeyFrame[playIndex + 1].Hombro - KeyFrame[playIndex].Hombro) / i_max_steps;
	KeyFrame[playIndex].movCodo = (KeyFrame[playIndex + 1].Codo - KeyFrame[playIndex].Codo) / i_max_steps;
	KeyFrame[playIndex].movDedo1 = (KeyFrame[playIndex + 1].Dedo1 - KeyFrame[playIndex].Dedo1) / i_max_steps;
	KeyFrame[playIndex].movDedo1a = (KeyFrame[playIndex + 1].Dedo1a - KeyFrame[playIndex].Dedo1a) / i_max_steps;
	KeyFrame[playIndex].movDedo2 = (KeyFrame[playIndex + 1].Dedo2 - KeyFrame[playIndex].Dedo2) / i_max_steps;
	KeyFrame[playIndex].movDedo2a = (KeyFrame[playIndex + 1].Dedo2a - KeyFrame[playIndex].Dedo2a) / i_max_steps;
	KeyFrame[playIndex].movDedo3 = (KeyFrame[playIndex + 1].Dedo3 - KeyFrame[playIndex].Dedo3) / i_max_steps;
	KeyFrame[playIndex].movDedo3a = (KeyFrame[playIndex + 1].Dedo3a - KeyFrame[playIndex].Dedo3a) / i_max_steps;
	KeyFrame[playIndex].movDedo4 = (KeyFrame[playIndex + 1].Dedo4 - KeyFrame[playIndex].Dedo4) / i_max_steps;
	KeyFrame[playIndex].movDedo4a = (KeyFrame[playIndex + 1].Dedo4a - KeyFrame[playIndex].Dedo4a) / i_max_steps;
	KeyFrame[playIndex].movDedo5 = (KeyFrame[playIndex + 1].Dedo5 - KeyFrame[playIndex].Dedo5) / i_max_steps;
	KeyFrame[playIndex].movDedo5a = (KeyFrame[playIndex + 1].Dedo5a - KeyFrame[playIndex].Dedo5a) / i_max_steps;
}
void InitGL(GLvoid)     // Inicializamos parametros
{
					// Negro de fondo	
	// glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	

	//END NEW//////////////////////////////

	//objCamera.Position_Camera(0, 2.5f, 3, 0, 2.5f, 0, 0, 1, 0);

	//NEW Crear una lista de dibujo
	//ciudad_display_list = createDL();

	//NEW Iniciar variables de KeyFrames
	for (int i = 0; i<MAX_FRAMES; i++)
	{
		KeyFrame[i].transX = 0;
		KeyFrame[i].transZ = 0;
		KeyFrame[i].angleX = 0;
		KeyFrame[i].angleY = 0;
		KeyFrame[i].Hombro = 0;
		KeyFrame[i].Codo = 0;
		KeyFrame[i].Dedo1 = 0;
		KeyFrame[i].Dedo1a = 0;
		KeyFrame[i].Dedo2 = 0;
		KeyFrame[i].Dedo2a = 0;
		KeyFrame[i].Dedo3 = 0;
		KeyFrame[i].Dedo3a = 0;
		KeyFrame[i].Dedo4 = 0;
		KeyFrame[i].Dedo4a = 0;
		KeyFrame[i].Dedo5 = 0;
		KeyFrame[i].Dedo5a = 0;
	}

	
	//NEW//////////////////NEW//////////////////NEW///////////

}

void pintaTexto(float x, float y, float z, void *font, char *string)
{

	char *c;     //Almacena los caracteres a escribir
	glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
							//glWindowPos2i(150,100);
	for (c = string; *c != '\0'; c++) //Condicion de fin de cadena
	{
		glutBitmapCharacter(font, *c); //imprime
	}
}

void prisma(float color[3])
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

	glColor3fv(color);
	glBegin(GL_POLYGON);	//Front		
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

		glTranslatef(transX, 0.0f, transZ);
		glRotatef(angleY, 0.0, 1.0, 0.0);
		glRotatef(angleX, 1.0, 0.0, 0.0);
	//Poner Código Aquí.
	/*
	glRotatef(Hombro, 0.0, 0.0, 1.0);
	glTranslatef(1.25, 0.0, 0.0); //translado a la derecha
	glPushMatrix();
	//glScalef(5.0, 2.5, 5.0);
	
		glScalef(2.5, 2.0, 3.0);
		prisma(red);	//A  mandando el color
	glPopMatrix();
	*/
	glTranslatef(1.25, 0.0, 0.0);//TRASLADAR
		glRotatef(Codo, 0.0, 1.0, 0.0); //ROTAR
		glTranslatef(1.0, 0.0, 0.0); //PIVOTE
		glPushMatrix();
		glScalef(2.0, 2.0, 3.0);
		prisma(green);	//B
	glPopMatrix();

	glPushMatrix(); //dedo 1

		glTranslatef(1.4, 0.5, 0.875);
		glRotatef(Dedo1, 0.0, 0.0, 1.0);
		glTranslatef(0.05, 0.0, 0.0);
		glPushMatrix();
			glScalef(1.0, 0.4, 0.30);
			prisma(white);
		glPopMatrix();
		glTranslatef(0.05, 0.0, 0.0);
		glRotatef(Dedo1a, 0.0, 0.0, 1.0);
		glTranslatef(1.0, 0.0, 0.0);
		glScalef(1.0, 0.4, 0.3);
		prisma(yellow);
	glPopMatrix();

	//segundo dedo
	glPushMatrix();
		glTranslatef(1.2, 0.5, .3);
		glRotated(Dedo2, 0.0, 0.0, 1.0);
		glTranslatef(0.3, 0.0, 0.0);
		glPushMatrix();
			glScalef(1.0, 0.4, 0.3);
			prisma(blue);
		glPopMatrix();
		glTranslated(0.5, 0.0, 0.0);
		glRotatef(Dedo2a, 0.0, 0.0, 1.0);
		glTranslated(0.5, 0.0, 0.0);
		glScalef(1.0, 0.4, 0.3);
		prisma(yellow);
	glPopMatrix();
	
	//tercer dedo

	glPushMatrix();
		glTranslatef(1.2, 0.5, -0.2);
		glRotatef(Dedo3, 0.0, 0.0, 1.0);
		glTranslatef(0.375, 0.0, 0.0);
		glPushMatrix();
			glScalef(1.0, 0.4, 0.3);
			prisma(white);
		glPopMatrix();
		glTranslatef(0.375, 0.0, 0.0);
		glRotatef(Dedo3a, 0.0, 0.0, 1.0);
		glTranslatef(0.5, 0.0, 0.0);
		glScalef(1.0, 0.4, 0.3);
		prisma(blue);
	glPopMatrix();
	
	//Cuarto dedo
	glPushMatrix();
		glTranslatef(1.2, 0.5, -0.9);
		glRotatef(Dedo5, 0.0, 0.0, 1.0);
		glTranslatef(0.375, 0.0, 0.0);
		glPushMatrix();
			glScalef(1.0, 0.4, 0.3);
			prisma(white);
		glPopMatrix();
		glTranslatef(0.375, 0.0, 0.0);
		glRotatef(Dedo5a, 0.0, 0.0, 1.0);
		glTranslatef(0.5, 0.0, 0.0);
		glScalef(1.0, 0.4, 0.3);
		prisma(yellow);
	glPopMatrix();
	
	//quinto
	glPushMatrix();
		glTranslatef(1.0, -0.2, 1.2);
		glRotatef(Dedo4, 0.0, -1.0, 0.0);
		glTranslatef(0.375, 0.0, 0.0);
		glPushMatrix();
			glScalef(0.75, 0.4, 0.3);
			prisma(white);
		glPopMatrix();
		glTranslatef(0.375, 0.0, 0.0);
		glRotatef(Dedo4a, 0.0, -1.0, 0.0);
		glTranslatef(0.5, 0.0, 0.0);
		glScalef(1.0, 0.4, 0.3);
		prisma(yellow);
	glPopMatrix();
	
	glutSwapBuffers();
	// Swap The Buffers


	

}

void animacion()
{
	
	if (play)
	{

		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex>FrameIndex - 2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
								  //Interpolation
				interpolation();

			}
		}
		else
		{
			//Draw animation
			transX += KeyFrame[playIndex].inctransx;
			transZ += KeyFrame[playIndex].inctransz;
			angleX += KeyFrame[playIndex].incanglex;
			angleY += KeyFrame[playIndex].incangley;
			Hombro += KeyFrame[playIndex].movHombro;
			Codo += KeyFrame[playIndex].movCodo;
			Dedo1 += KeyFrame[playIndex].movDedo1;
			Dedo1a += KeyFrame[playIndex].movDedo1a;
			Dedo2 += KeyFrame[playIndex].movDedo2;
			Dedo2a += KeyFrame[playIndex].movDedo2a;
			Dedo3 += KeyFrame[playIndex].movDedo3;
			Dedo3a += KeyFrame[playIndex].movDedo3a;
			Dedo4 += KeyFrame[playIndex].movDedo4;
			Dedo4a += KeyFrame[playIndex].movDedo4a;
			Dedo5 += KeyFrame[playIndex].movDedo5;
			Dedo5a += KeyFrame[playIndex].movDedo5a;

			i_curr_steps++;
		}

	}
	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		sprintf(s, "FPS:%4.2f", frame*1000.0 / (time - timebase));
		timebase = time;
		frame = 0;
	}

	glutPostRedisplay();
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

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':
	case 'W':
		transZ += 0.3f;
		break;
	case 's':
	case 'S':
		transZ -= 0.3f;
		break;
	case 'a':
	case 'A':
		transX -= 1.0f;
		break;
	case 'd':
	case 'D':
		transX += 1.0f;
		break;
	case 'h':
		if (90.0 > Hombro)
			Hombro += 1.0f;
		break;
	case 'H':
		if (-120.0 < Hombro)
			Hombro -= 1.0f;
		break;
	case 'c':
		if (5.0 >Codo)
			Codo += 2.5;
		break;
	case 'C':
		if (-95.0 < Codo)
			Codo -= 2.5;
		break;
	case 'y':
		if (45>Dedo1)
			Dedo1 += 2.0;
		break;
	case 'Y':
		if (-90<Dedo1)
			Dedo1 -= 2.0;
		break;
		break;

	case 'u':
		if (0>Dedo1a)
			Dedo1a += 2.0;
		break;
	case 'U':
		if (-90<Dedo1a)
			Dedo1a -= 2.0;
		break;
	case 'n':
		if (45>Dedo2)
			Dedo2 += 2.0;
		break;
	case 'N':
		if (-110<Dedo2)
			Dedo2 -= 2.0;
		break;

	case 'm':
		if (0>Dedo2a)
			Dedo2a += 2.0;
		break;
	case 'M':
		if (-110<Dedo2a)
			Dedo2a -= 2.0;
		break;

	case 'j':
		if (45>Dedo3)
			Dedo3 += 2.0;
		break;
	case 'J':
		if (-90<Dedo3)
			Dedo3 -= 2.0;
		break;

	case 'b':
		if (0>Dedo3a)
			Dedo3a += 2.0;
		break;
	case 'B':
		if (-100<Dedo3a)
			Dedo3a -= 2.0;
		break;

	case 'v':
		if (45>Dedo4)
			Dedo4 += 2.0;
		break;
	case 'V':
		if (-90<Dedo4)
			Dedo4 -= 2.0;
		break;

	case 'p':
		if (0>Dedo4a)
			Dedo4a += 2.0;
		break;
	case 'P':
		if (-100<Dedo4a)
			Dedo4a -= 2.0;
		break;

	case 't':
		if (45 > Dedo5)
			Dedo5 += 2.0;
		break;
	case 'T':
		if (-90 < Dedo5)
			Dedo5 -= 2.0;
		break;

	case 'r':
		if (0 > Dedo5a)
			Dedo5a += 2.0;
		break;
	case 'R':
		if (-100 < Dedo5a)
			Dedo5a -= 2.0;
		break;
	case 'k':		//
	case 'K':
		if (FrameIndex<MAX_FRAMES)
		{
			saveFrame();
		}

		
		break;

	case 'l':
	case 'L':
		if (play == false && (FrameIndex>1))
		{

			resetElements();
			//First Interpolation				
			interpolation();

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
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
	case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX -= 2.0;
		break;
	case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX += 2.0;
		break;
	case GLUT_KEY_LEFT:
		angleY += 2.0;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 2.0;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void menuKeyFrame(int id)
{
	switch (id)
	{
	case 0:	//Save KeyFrame
		if (FrameIndex<MAX_FRAMES)
		{
			saveFrame();
		}
		break;

	case 1:	//Play animation
		if (play == false && FrameIndex >1)
		{

			resetElements();
			//First Interpolation
			interpolation();

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;


	}
}

void menu(int id)
{

}

int main(int argc, char** argv)   // Main Function
{
	int submenu;
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 11"); // Nombre de la Ventana
									 //glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);

	submenu = glutCreateMenu(menuKeyFrame);
	glutAddMenuEntry("Guardar KeyFrame", 0);
	glutAddMenuEntry("Reproducir Animacion", 1);
	glutCreateMenu(menu);
	glutAddSubMenu("Animacion Monito", submenu);

	glutAttachMenu(GLUT_RIGHT_BUTTON);


	glutMainLoop();          // 

	return 0;
}