#include<iostream>
#include<vector>
#include<GL\glut.h>
#include"GraphEngine.h"
using namespace std;
Object O(Vector3D<double>(0,0,0), 45,10);
Object O2(Vector3D<double>(0, 0, 0));
float t = 0;
void draw()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPointSize(10);
	//Slerp
	glColor3ub(0, 255, 0);
	glBegin(GL_POINTS);
	glVertex3dv(O.GetLocation().GetArray());
	glEnd();
	glColor3ub(0, 0, 255);
	glBegin(GL_POINTS);
	glVertex3dv(O2.GetLocation().GetArray());
	glEnd();


	glFlush();
}
void key(unsigned char c, int x, int y)
{

	glutPostRedisplay();
}
void idle()
{
	O.Move(0.0001);
	O2.Slide(0.0005);
	t += 0.00005;
	if (t > 1)
	{
		t = 0;
	}
	glutPostRedisplay();
}
void glinit()
{
	glutInitDisplayMode(GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("OPENGL");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(draw);
	glutKeyboardFunc(key);
	glutIdleFunc(idle);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-20, 20, -20, 20, -20, 20);
	gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
}
int main()
{
	O.SetGravity();
	O2.SetMess(100);
	O2.SlideInit(27, 0.5);
	glinit();
	
}