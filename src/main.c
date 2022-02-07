#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include "model/sphere.h"
// Initial square position and size
GLfloat x = 10.0;
GLfloat y = 1.0;
GLfloat z = 0.0;
GLfloat radius = 2.5;
GLint rings = 6, nsides = 20, slices = 20, stacks = 10;

// Step values for coordinates 
GLfloat xstep = 0.25;
GLfloat ystep = 0.25;

void quad()
{
	Sphere* s = constructor(slices, stacks, radius, x, y, z);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	glTranslatef(getX(s),getY(s),getZ(s));
	// set current drawing color to red

	glutSolidSphere(getRadius(s), getSlices(s), getStacks(s));

	// Executa os comandos OpenGL
	glutSwapBuffers();
}

GLvoid DESENHAR(GLvoid)
{
	glClearColor(0.0f,0.0f,1.0f,3.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,100.0,0.0,100.0);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
	// END collision detection for a square 
	glTranslatef(x,y,z);
	// set current drawing color to red
	glColor3f(1.0f,0.0f,0.0f);
	quad();
	// flush drawing commands and swap
	glutSwapBuffers();
}

GLvoid TEMPORIZADOR()
{
	// Redraw the scene by calling the display function DESENHAR
	glutPostRedisplay();
	glutTimerFunc(33,TEMPORIZADOR, 1);
}

void ESCAPE(unsigned char key, int a, int b)
{
	if(key==27) exit(0);
}

int main (int argc, char** argv) 
{
	// initialization for GLUT/OpenGL
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	// create window with resolution 500x500
	glutInitWindowSize(1000,1000);
	glutCreateWindow("Bounce");
	// register callbacks
	glutDisplayFunc(DESENHAR);
	glutKeyboardFunc(ESCAPE);
	glutTimerFunc(33,TEMPORIZADOR,1);
	// process events
	glutMainLoop();
	return 0;
}