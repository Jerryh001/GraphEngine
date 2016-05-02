#pragma once
#include "Curve.h"
#include"Vector3D.h"
class BezierCurve :	public Curve
{
	Matrix<double, 1, 4> T;
public:
	BezierCurve(const Vector3D<double>& P1 = { 0,0,0 }, const Vector3D<double>&P2 = { 0,0,0 }, const Vector3D<double>&T1 = { 0,0,0 }, const Vector3D<double>&T2 = { 0,0,0 });
	~BezierCurve();
	Vector3D<double> operator()(const double& t);
};

