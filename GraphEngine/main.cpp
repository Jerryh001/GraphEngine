#include<iostream>
#include<GL\glut.h>
#include"GraphEngine.h"
using namespace std;
Plane pl({ 0,0,0 }, { 0,1,0 });
Vector3D<float> S(10, 10, 10), V(0, -1, 0);
void draw()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3ub(255, 0, 0);
	glPointSize(10.0);
	glBegin(GL_QUADS);
	glVertex3i(20, 0, 20);
	glVertex3i(-20, 0, 20);
	glVertex3i(-20, 0, -20);
	glVertex3i(20, 0, -20);
	glEnd();
	glColor3ub(0, 255, 0);
	glBegin(GL_POINTS);
	glVertex3fv(S.GetArray());
	glEnd();
	glColor3ub(0, 0, 255);
	glBegin(GL_LINES);
	glVertex3fv(S.GetArray());
	glVertex3fv(TouchPoint(pl, Line<float>(S,V)).GetArray());
	glEnd();

	glFlush();
}
void key(unsigned char c, int x, int y)
{
	cout << S << endl;
	switch (c)
	{
	case 's':
		if (pl.Distance(S, V) > 0)
		{
			S = S + V;
		}
		break;
	case 'w':
		S = S - V;
		break;
	}
	glutPostRedisplay();
}
void glinit()
{
	glutInitDisplayMode(GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Shading");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(draw);
	glutKeyboardFunc(key);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-20, 20, -20, 20, -20, 20);
	gluLookAt(5, 1, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
}
int main()
{
	V = V.Normalize();
	glinit();
	cout << pl.Distance(S, V) << endl;
}