#include "BezierCurve.h"



BezierCurve::BezierCurve(const Vector3D<double>& P1, const Vector3D<double>& P2, const Vector3D<double>& P3, const Vector3D<double>& P4) :Curve(P1, P2, P3, P4)
{
	double Marr[4][4] =
	{ { -1,3,-3,1 },
	{ 3,-6,3,0 },
	{ -3,3,0,0 },
	{ 1,0,0,0 } };
	M = Marr;
}


BezierCurve::~BezierCurve()
{
}

Vector3D<double> BezierCurve::operator()(const double& t)
{
	double tarr[1][4] = { t*t*t,t*t,t,1 };
	T = tarr;
	return (T*M*(G.Transpose()))(0, 0);
}
