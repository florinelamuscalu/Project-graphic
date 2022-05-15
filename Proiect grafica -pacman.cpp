#include<iostream>
#include<fstream>
#include<windows.h>
#include<stdlib.h>
#include <GL/freeglut.h>
#include <thread>
#include <string>
#include <algorithm>

using namespace std;

using namespace std;
using namespace std::this_thread;

GLdouble left_m = -100.0;
GLdouble right_m = 700.0;
GLdouble bottom_m = -140.0;
GLdouble top_m = 460.0;
double ok = 1, ok_food = 1;
double j = 0.0;
double i = 0.0;
double contor = 0;
double loc_vert = 800, loc_vert_food = 800;
int vector[3] = { 0, 160, 320 };
double height = vector[rand() % 3], height_food = vector[rand() % 3];
int score = 0;
double timp = 0.3; //cat de repede se misca obiectele si liniile soselei
double timp_food = 0.4;
int pct = 1000;
double rsj, rdj, rss, rds = 0;
int screen = 1;
int x, y;
int window;

struct COLOR {
	GLfloat r, g, b;
};

//crearea ferestrei jocului
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(left_m, right_m, bottom_m, top_m, -1.0, 1.0);
}

void mouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		x = mx;
		y = my;
	}

}

void RenderString(float x, float y, void* font, const unsigned char* string)
{

	glColor3f(1.0f, 0.0f, 0.0f);
	glRasterPos2f(x, y);

	glutBitmapString(font, string);
}

void startgame(void)
{
	//pentru fantome
	if (height != j || (loc_vert > 64 || loc_vert < -50))
	{

		if (i < -300)
		{
			i = 0;
		}
		i = i - 2 * timp;

		loc_vert -= timp;

		if (loc_vert < -150)
		{
			//pe ce linie se pune urmatorul obiect
			height = vector[rand() % 3];
			char buf[100] = { 0 }; 
			loc_vert = 750;
		}

		if (score >= pct && pct <= 15000)
		{
			timp += 0.1;
			pct += 1000;
		}
	}
	else {
		ok = 0;
	}

	//pentru mancare
	if (true)
	{
		if (i < -300)
		{
			i = 0;
		}
		i = i - 2 * timp_food;

		loc_vert_food -= timp_food;

		if (height_food == j && loc_vert_food < 45 && loc_vert_food > -50) {
			score += 100;
			height_food = vector[rand() % 3];
			loc_vert_food = 800;
		} else if (loc_vert_food < -150) {
			loc_vert_food = 800;
		}

		if (score >= pct && pct <= 15000)
		{
			timp_food += 0.1;
			pct += 1000;
		}
		glutPostRedisplay();
	}
}

//functie pt toate textele din joc
void renderbitmap(float x, float y, void* font, char* string) {
	char* c;
	//coordonatele unde trebuie redat textul 
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++) {
		//atasarea fontului pentru textul care urmeaza a fi afisat
		glutBitmapCharacter(font, *c); 
	}
}

//triunghi pentru gura Pacman
void drawTri()
{
	glBegin(GL_TRIANGLES);
	glColor3f(0, 0, 0);

	glVertex2f(0, 0);
	glVertex2f(40, -30);
	glVertex2f(40, 20);
	glEnd();
}

void drawCircle(double radius, float x1, float y1, COLOR color)
{
	float angle;
	float x2, y2;

	glColor3f(color.r, color.g, color.b);

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1, y1);

	for (angle = 1.0f; angle < 361.0f; angle += 0.2)
	{
		if (angle > 2.0f && angle < 250.0f)
			continue;
		else {
			x2 = x1 + sin(angle) * radius;
			y2 = y1 + cos(angle) * radius;
			glVertex2f(x2, y2);
		}
	}

	glEnd();

}

void drawScene(void)
{

	//fisier unde salvam high scores 
	fstream f;
	//deschidem cu modul append - pt a se adauga info la sfarsitul fisierului
	f.open("highscores.txt", std::ios::app);
		//meniu
		if (screen == 1) {
			glClear(GL_COLOR_BUFFER_BIT);

			glColor3f(0, 0, 0);

			//titlu
			glColor3f(1.0f, 1.0f, 1.0f);
			char titleGame[100] = { 0 };
			sprintf_s(titleGame, "Pacman Race");
			renderbitmap(200, 400, GLUT_BITMAP_TIMES_ROMAN_24, titleGame);

			//Game rules
			glColor3f(1.0f, 1.0f, 1.0f);
			char rulesGame[100] = { 0 };
			sprintf_s(rulesGame, "GAME RULES: 1.Stay away from ghosts and 2.Eat proteins for a high score");
			renderbitmap(-80, 300, GLUT_BITMAP_TIMES_ROMAN_24, rulesGame);

			//Buton Play
			glColor3f(0.1, 0.6, 0.1);
			glRecti(235, 185, 310, 230);
			glColor3f(0.0f, 0.0f, 0.0f);
			char bufPlayGame[100] = { 0 };
			sprintf_s(bufPlayGame, "Play");
			renderbitmap(250, 200, GLUT_BITMAP_TIMES_ROMAN_24, bufPlayGame);

			//buton Exit 
			glColor3f(1, 0.2, 0.3);
			glRecti(235, 85, 310, 130);
			glColor3f(0.0f, 0.0f, 0.0f);
			char bufExitGame[100] = { 0 };
			sprintf_s(bufExitGame, "Exit");
			renderbitmap(250, 100, GLUT_BITMAP_TIMES_ROMAN_24, bufExitGame);

			//daca userul face click pe play, se incepe jocul (screen = 2)
			if (x >= 335 && x <= 410 && y >= 230 && y <= 275)
			{
				screen = 2;
			}
			//daca userul face click pe exit, se inchide fereastra
			if (x >= 335 && x <= 410 && y >= 330 && y <= 375)
			{
				glutDestroyWindow(window);
			}

			glFlush();
		}
		//in joc
		if (screen == 2)
		{
			glClear(GL_COLOR_BUFFER_BIT);


			glColor3f(0, 0, 1);

			// Imprejurimi jos
			glBegin(GL_POLYGON);
			glVertex2i(-100, -140);// Stanga jos
			glVertex2i(700, -140); // Dreapta jos
			glVertex2i(700, -80);  // Dreapta sus
			glVertex2i(-100, -80); // Stanga sus
			glEnd();

			// Imprejurimi sus
			glBegin(GL_POLYGON);
			glVertex2i(-100, 400);// Stanga jos
			glVertex2i(700, 400); // Dreapta jos
			glVertex2i(700, 460); // Dreapta sus
			glVertex2i(-100, 460);// Stanga sus
			glEnd();

			// Delimitare sosea
			glLineWidth(15);
			glColor3f(0, 0, 1);


			// Initializare pt tranzitii
			glPushMatrix();
			glTranslated(i * 1.25, 0.0, 0.0);

			//Delimitare sosea - linie punctata jos
			glPushAttrib(GL_ENABLE_BIT);
			glLineStipple(100, 0xAAAA);
			glEnable(GL_LINE_STIPPLE);
			glBegin(GL_LINES);
			glVertex2i(-500, 80);
			glVertex2i(1500, 80);
			glEnd();
			glPopAttrib();

			//Delimitare sosea - linie punctata sus
			glPushAttrib(GL_ENABLE_BIT);
			glLineStipple(100, 0xAAAA);
			glEnable(GL_LINE_STIPPLE);
			glBegin(GL_LINES);
			glVertex2i(-500, 240);
			glVertex2i(1500, 240);
			glEnd();
			glPopAttrib();

			glPopMatrix();

			//black circle for the eyes of the ghosts & Pacman
			struct COLOR circleEyes;
			circleEyes.r = 0;
			circleEyes.g = 0;
			circleEyes.b = 0;

			//desenam pacman
			glPushMatrix();
			glTranslated(0.0, j, 0.0);

			struct COLOR circlePacman;
			circlePacman.r = 1;
			circlePacman.g = 1;
			circlePacman.b = 0;
			drawCircle(40, 0, 0, circlePacman);
			drawCircle(5, 0, 20, circleEyes);
			drawTri();

			if (ok == 0)
			{
				rsj = 8;
				rss = -8;
				rdj = -8;
				rds = 8;
			}

			glPopMatrix();

			if (ok == 0) {
				f << score << endl; 
				sleep_for(1000ms);
				screen = 3;
			}

			if (contor == 1 && (j != 160 && j != 320))
				j = j + 1;
			else if (contor == -1 && (j != 160 && j != 0))
				j = j - 1;
			else {
				contor = 0;

			}

			//desenam fantomele pentru Pacman
			glPushMatrix();
			glTranslated(loc_vert, height, 0.0);

			glColor3f(0.471, 0.667, 0.949);
			struct COLOR circleGhost;
			circleGhost.r = 1;
			circleGhost.g = 0.2;
			circleGhost.b = 0.3;
			drawCircle(30, 0, 0, circleGhost);
			drawCircle(10, 0, -30, circleGhost);
			drawCircle(10, -20, -30, circleGhost);
			drawCircle(10, 20, -30, circleGhost);
			glColor3f(1, 0.2, 0.3);
			glRecti(-30, -35, 30, 5);
			drawCircle(5, -10, 6, circleEyes);
			drawCircle(5, 10, 6, circleEyes);
			glPopMatrix();

			//desenam mancarea pentru Pacman
			if (height_food == height && loc_vert == loc_vert_food && height == 320)
				height_food = 160;
			if (height_food == height && loc_vert == loc_vert_food && height == 160)
				height_food = 0;
			if (height_food == height && loc_vert == loc_vert_food && height == 0)
				height_food = 320;

			glPushMatrix();
			glTranslated(loc_vert_food, height_food, 0.0);
			glColor3f(0.471, 0.667, 0.949);
			drawCircle(10, 0, 0, circlePacman);
			glPopMatrix();

			startgame();
			//afisare scor
			glColor3f(1.0f, 0.0f, 0.0f);
			char buf[100] = { 0 };
			sprintf_s(buf, "Score: %d", score);
			renderbitmap(-90, -110, GLUT_BITMAP_TIMES_ROMAN_24, buf);
			glutPostRedisplay();
			glutSwapBuffers();
			glFlush();
		}

		//afisare high score Pacman
		if (screen == 3)
		{
			glClear(GL_COLOR_BUFFER_BIT);

			glColor3f(0, 0, 0);

			//titlu
			glColor3f(1.0f, 0.0f, 0.0f);
			char gameOver[100] = { 0 };
			sprintf_s(gameOver, "GAME OVER");
			renderbitmap(200, 370, GLUT_BITMAP_TIMES_ROMAN_24, gameOver);

			//High Scores titlu
			glColor3f(1.0f, 1.0f, 1.0f);
			char highScoresTitle[100] = { 0 };
			sprintf_s(highScoresTitle, "Top 3 High Scores:");
			renderbitmap(190, 300, GLUT_BITMAP_TIMES_ROMAN_24, highScoresTitle);

			int numLines = 0;

			f.close();
			f.open("highscores.txt", std::ios::in);

			if (!f.is_open())
			{
				cout << "Error opening file";
				exit(EXIT_FAILURE);
			}

			string scores[200] = {};
			string text;

			if (f.is_open())
			{
				while (!f.eof()) {
					getline(f, text);
					scores[numLines] = text;
					numLines++;
				}
			}

			int n = sizeof(scores) / sizeof(scores[0]);

			//sortare in ordine descendenta a vectorului cu scorurile
			std::sort(scores, scores + n, greater<string>());

				int score1 = stoi(scores[0]);
				int score2 = stoi(scores[1]);
				int score3 = stoi(scores[2]);
			

			if (score == score1) {
				glColor3f(0.2f, 1.0f, 0.1f);
				char congratsMessage[100] = { 0 };
				sprintf_s(congratsMessage, "Felicitari! Ai un nou High Score: %d!", score);
				renderbitmap(120, 400, GLUT_BITMAP_TIMES_ROMAN_24, congratsMessage);
			}

			//Score 1
			glColor3f(1.0f, 1.0f, 1.0f);
			char top1score[100] = { 0 };
			sprintf_s(top1score, "%d", score1);
			renderbitmap(250, 270, GLUT_BITMAP_TIMES_ROMAN_24, top1score);

			//Score 2
			glColor3f(1.0f, 1.0f, 1.0f);
			char top2score[100] = { 0 };
			sprintf_s(top2score, "%d", score2);
			renderbitmap(250, 250, GLUT_BITMAP_TIMES_ROMAN_24, top2score);
			//Score 3
			glColor3f(1.0f, 1.0f, 1.0f);
			char top3score[100] = { 0 };
			sprintf_s(top3score, "%d", score3);
			renderbitmap(250, 230, GLUT_BITMAP_TIMES_ROMAN_24, top3score);
			
			//buton Exit 
			glColor3f(1, 0.2, 0.3);
			glRecti(235, 85, 310, 130);
			glColor3f(0.0f, 0.0f, 0.0f);
			char bufExitGame[100] = { 0 };
			sprintf_s(bufExitGame, "Exit");
			renderbitmap(250, 100, GLUT_BITMAP_TIMES_ROMAN_24, bufExitGame);
			
			//daca userul face click pe exit, se inchide fereastra
			if (x >= 335 && x <= 410 && y >= 330 && y <= 375)
			{
				glutDestroyWindow(window);
			}
			glutPostRedisplay();
			glutSwapBuffers();
			glFlush();
	}
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100.0, 700.0, -140.0, 460.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void miscasus(void)
{
	if (ok != 0)
	{
		if (j < 320)
		{
			contor = 1;
			j += 1;
		}

		glutPostRedisplay();
	}
}

void miscajos(void)
{
	if (ok != 0)
	{
		if (j > 0)
		{
			contor = -1;
			j -= 1;


		}

		glutPostRedisplay();
	}
}

void keyboard(int key, int x, int y)
{


	switch (key) {
	case GLUT_KEY_UP:
		miscasus();
		break;
	case GLUT_KEY_DOWN:
		miscajos();
		break;

	}

}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	window = glutCreateWindow("Pacman game - eat all the proteins");
	init();
	glutMouseFunc(mouse);
	glutDisplayFunc(drawScene);
	glutReshapeFunc(reshape);
	glutSpecialFunc(keyboard);

	glutMainLoop();
}