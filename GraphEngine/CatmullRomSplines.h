#pragma once
#include<vector>
#include "Curve.h"
#include"Vector3D.h"
class CatmullRomSplines:public Curve
{
	vector<Vector3D<double>> node;
	Matrix<double, 4, 1> T;
public:
	CatmullRomSplines(const vector<Vector3D<double>>& in = { 0 });
	~CatmullRomSplines();
	Vector3D<double> operator()(const double& t);
};

