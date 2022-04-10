#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <iostream>

using namespace std;

const double TWO_PI = 6.2831853;
const double PI = 3.1415926;

GLsizei winWidth = 1150, winHeight = 750;
GLuint regHexiii, regHexiv, regHexv, regHexvi, cerc, cercII, cercIII, cercIV, regHex;
static GLfloat rotTheta = 0.0;
int dif = 1;
//FACTORI TRANSFORMARI
double j = 0.0, i = 5.0, l = -6.0, m = -6.0;

class scrPt
{
public:
	GLint x, y;
};


static void init(void)
{

	scrPt hexVertex;
	GLdouble hexTheta;
	GLint k;
	glClearColor(1.0, 1.0, 1.0, 1.0);

	//ROTITE (regHex pt exterior, cerc pt inteior)
	regHexiii = glGenLists(1);
	glNewList(regHexiii, GL_COMPILE);
	int copie = 0;
	glPolygonMode(GL_FRONT, GL_FILL);
	glColor3f(0.4, 0.4, 0.45);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(180, 150);
	for (k = 1; k <= 151; k++)
	{
		hexTheta = TWO_PI * k / 150;
		if (k - copie == 5 && dif == 0) {
			dif = 1;
			copie = k;
		}
		if (k - copie == 5 && dif == 1) {
			dif = 0;
			copie = k;
		}
		if (dif) {
			hexVertex.x = 180 + 25 * cos(hexTheta);
			hexVertex.y = 151 + 25 * sin(hexTheta);
			glVertex2i(hexVertex.x, hexVertex.y);
		}
		else {
			hexVertex.x = 180 + 20 * cos(hexTheta);
			hexVertex.y = 150 + 20 * sin(hexTheta);
			glVertex2i(hexVertex.x, hexVertex.y);
		}

	}
	glEnd();
	glEndList();

	cerc = glGenLists(1);
	glNewList(cerc, GL_COMPILE);
	glPolygonMode(GL_FRONT, GL_FILL);
	glColor3f(0.105, 0.1, 0.1);
	glBegin(GL_POLYGON);
	for (k = 0; k < 150; k++)
	{
		hexTheta = TWO_PI * k / 80;
		hexVertex.x = 180 + 13 * cos(hexTheta);
		hexVertex.y = 150 + 13 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);

	}
	glEnd();
	glEndList();


	dif = 0;

	regHexiv = glGenLists(1);
	glNewList(regHexiv, GL_COMPILE);
	copie = 0;
	glPolygonMode(GL_FRONT, GL_FILL);

	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(140, 169);
	for (k = 0; k <= 171; k++)
	{
		hexTheta = TWO_PI * k / 170;
		if (k - copie == 5 && dif == 0) {
			dif = 1;
			copie = k;

		}
		if (k - copie == 5 && dif == 1) {
			dif = 0;
			copie = k;
		}
		if (dif) {
			hexVertex.x = 140 + 22 * cos(hexTheta);
			hexVertex.y = 169 + 22 * sin(hexTheta);
			glVertex2i(hexVertex.x, hexVertex.y);
		}
		else {
			hexVertex.x = 140 + 17 * cos(hexTheta);
			hexVertex.y = 169 + 17 * sin(hexTheta);
			glVertex2i(hexVertex.x, hexVertex.y);
		}

	}
	glEnd();
	glEndList();


	cercII = glGenLists(1);
	glNewList(cercII, GL_COMPILE);
	glPolygonMode(GL_FRONT, GL_FILL);
	glColor3f(0.105, 0.1, 0.1);
	glBegin(GL_POLYGON);
	for (k = 0; k < 150; k++)
	{
		hexTheta = TWO_PI * k / 80;
		hexVertex.x = 140 + 10 * cos(hexTheta);
		hexVertex.y = 169 + 10 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);

	}
	glEnd();
	glEndList();

	dif = 1;

	regHexv = glGenLists(1);
	glNewList(regHexv, GL_COMPILE);
	copie = 0;
	glPolygonMode(GL_FRONT, GL_FILL);

	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(100, 190);
	for (k = 0; k <= 81; k++)
	{
		hexTheta = TWO_PI * k / 80;
		if (k - copie == 5 && dif == 0) {
			dif = 1;
			copie = k;

		}
		if (k - copie == 5 && dif == 1) {
			dif = 0;
			copie = k;
		}
		if (dif) {
			hexVertex.x = 100 + 26.4 * cos(hexTheta);
			hexVertex.y = 190 + 26.4 * sin(hexTheta);
			glVertex2i(hexVertex.x, hexVertex.y);
		}
		else {
			hexVertex.x = 100 + 20.4 * cos(hexTheta);
			hexVertex.y = 190 + 20.4 * sin(hexTheta);
			glVertex2i(hexVertex.x, hexVertex.y);
		}

	}
	glEnd();
	glEndList();


	cercIII = glGenLists(1);
	glNewList(cercIII, GL_COMPILE);
	glPolygonMode(GL_FRONT, GL_FILL);
	glColor3f(0.105, 0.1, 0.1);
	glBegin(GL_POLYGON);
	for (k = 0; k < 80; k++)
	{
		hexTheta = TWO_PI * k / 80;
		hexVertex.x = 100 + 12 * cos(hexTheta);
		hexVertex.y = 190 + 12 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);

	}
	glEnd();
	glEndList();

	dif = 0;

	regHexvi = glGenLists(1);
	glNewList(regHexvi, GL_COMPILE);
	copie = 0;
	glPolygonMode(GL_FRONT, GL_FILL);

	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(125, 235);
	for (k = 0; k <= 81; k++)
	{
		hexTheta = TWO_PI * k / 80;
		if (k - copie == 5 && dif == 0) {
			dif = 1;
			copie = k;
		}
		if (k - copie == 5 && dif == 1) {
			dif = 0;
			copie = k;
		}
		if (dif) {
			hexVertex.x = 125 + 30 * cos(hexTheta);
			hexVertex.y = 235 + 30 * sin(hexTheta);
			glVertex2i(hexVertex.x, hexVertex.y);
		}
		else {
			hexVertex.x = 125 + 24 * cos(hexTheta);
			hexVertex.y = 235 + 24 * sin(hexTheta);
			glVertex2i(hexVertex.x, hexVertex.y);
		}

	}
	glEnd();
	glEndList();


	cercIV = glGenLists(1);
	glNewList(cercIV, GL_COMPILE);
	glPolygonMode(GL_FRONT, GL_FILL);
	glColor3f(0.105, 0.1, 0.1);
	glBegin(GL_POLYGON);
	for (k = 0; k < 80; k++)
	{
		hexTheta = TWO_PI * k / 80;
		hexVertex.x = 125 + 15 * cos(hexTheta);
		hexVertex.y = 235 + 15 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);

	}
	glEnd();
	glEndList();



	// desenare cap 

	regHex = glGenLists(1);
	glNewList(regHex, GL_COMPILE);
	glPolygonMode(GL_FRONT, GL_LINE);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (k = 0; k < 200; k++)
	{

		hexTheta = TWO_PI * k / 200;

		hexVertex.x = 127 + 100 * cos(hexTheta);
		hexVertex.y = 120 + 150 * sin(hexTheta);

		glVertex2i(hexVertex.x, hexVertex.y);
	}
	glEnd();
	glEndList();

}

void displayHex(void)
{
	glClear(GL_COLOR_BUFFER_BIT);


	//ROTITE (au rotatie pe loc, fiecare cu factori diferiti)
	glPushMatrix();
	glTranslated(180, 150, 0.0);
	glRotated(j, 0.0, 0.0, 1.0);
	glTranslated(-180, -150, 0.0);
	glCallList(regHexiii);
	glPopMatrix();

	glColor3f(0.4, 0.4, 0.45);
	glPushMatrix();
	glTranslated(140, 169, 0);
	glRotated(i, 0, 0, 1);
	glTranslated(-140, -169, 0);
	glCallList(regHexiv);
	glPopMatrix();


	glPushMatrix();
	glTranslated(100, 190, 0);
	glRotated(l, 0.0, 0.0, 1.0);
	glTranslated(-100, -190, 0);
	glCallList(regHexv);
	glPopMatrix();

	glPushMatrix();
	glTranslated(125, 235, 0);
	glRotated(m, 0.0, 0.0, 1.0);
	glTranslated(-125, -235, 0);
	glCallList(regHexvi);
	glPopMatrix();

	//MIJLOCUL ROITITELOR
	glCallList(cerc);
	glCallList(cercII);
	glCallList(cercIII);
	glCallList(cercIV);
	glCallList(regHex);

	glutSwapBuffers();
	glFlush();

	//cap
	//glCallList(regHex);
	//glPopMatrix();
	//glColor3f(0.0, 0.0, 0.0);
	//glRasterPos2i(120.0, 120.0);
	//glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1');
	//glutSwapBuffers();
	//glFlush();

	//triunghi alb gura
	/*glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 1); 
	glVertex2f(40.0, 30.0);
	glVertex2f(70.0, 55.0);
	glVertex2f(22.0, 100.0);
	*/

	

	//linii buze

	glLineWidth(3.0);
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0); 
	glVertex2i(100.0, 32.0); 
	glVertex2i(672.0, 55.0);
	glVertex2i(672.0, 55.0);
	glVertex2i(224.0, 102.0);

	glEnd();

	glFlush();
}

void miscad(void)
{
	//FACTORI ROTATIE ROTITE
	j += 0.01;
	i -= 0.013;
	l += 0.0096;
	m -= 0.0066;


	glutPostRedisplay();

}


void miscas(void)
{
	//FACTORI ROTATIE ROTITE
	j -= 0.01;
	i += 0.015;
	l -= 0.0096;
	m += 0.0066;


	glutPostRedisplay();

}

void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {

			glutIdleFunc(miscas);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) {

			glutIdleFunc(miscad);
		}
		break;
	case GLUT_MIDDLE_BUTTON:

	default:
		break;
	}
}

void winReshapeFcn(GLint newWidth, GLint newHeight)
{
	glViewport(0, 0, (GLsizei)newWidth, (GLsizei)newHeight);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-320.0, 320.0, -250.0, 340.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(150, 150);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Hexagon - utilizarea listelor de display");

	init();
	glutDisplayFunc(displayHex);
	glutReshapeFunc(winReshapeFcn);
	glutMouseFunc(mouse);
	glutMainLoop();
}