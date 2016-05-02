#include<iostream>
#include<vector>
#include<GL\glut.h>
#include"GraphEngine.h"
using namespace std;
Plane pl({ 0,0,0 }, { 0,1,0 });
Vector3D<float> S(10, 10, 10), V(0, -1, 0);
Vector3D<double> HP1(0, 0, 0), HP2(8,10,12), T1(-1, 0, 0), T2(1, 0, 0);
Vector3D<double> BP1(0,0,0), BP2(1,2,3), BP3(5,5,5), BP4(3,4,5);
Vector3D<double> CP0(-1,-2,-3),CP1(0, 0, 0), CP2(1, 2, 3), CP3(5, 5, 5), CP4(6, 7, 5),CP5(0,5,3);
HermiteCurve H;
BezierCurve B;
CatmullRomSplines C;
float t = 0;
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
	//HermiteCurve
	glColor3ub(0, 255, 0);
	glBegin(GL_POINTS);
	glVertex3dv(H(t).GetArray());
	glEnd();
	glColor3ub(0, 0, 255);
	glBegin(GL_POINTS);
	glVertex3dv(HP2.GetArray());
	glEnd();

	//BezierCurve
	glColor3ub(0, 255, 0);
	glBegin(GL_POINTS);
	glVertex3dv(B(t).GetArray());
	glEnd();
	glColor3ub(0, 0, 255);
	glBegin(GL_POINTS);
	glVertex3dv(BP4.GetArray());
	glEnd();

	//CatmullRomSplines
	glColor3ub(0, 255, 0);
	glBegin(GL_POINTS);
	glVertex3dv(C(t*3).GetArray());
	glEnd();
	glColor3ub(0, 0, 255);
	glBegin(GL_POINTS);
	glVertex3dv(CP4.GetArray());
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
	gluLookAt(10, 1, 1, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
}
int main()
{
	H = HermiteCurve(HP1, HP2, T1, T2);
	B = BezierCurve(BP1, BP2, BP3, BP4);
	C = vector<Vector3D<double>>({ CP0, CP1, CP2, CP3, CP4, CP5 });
	glinit();
	
}