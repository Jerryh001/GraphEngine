#pragma once
#include"Vector3D.h"
class Plane
{
	Vector3D<double> point;
	Vector3D<double> normal;
	double D;
public:
	Plane(const Vector3D<double>&, const Vector3D<double>&);
	~Plane();
	double Distance(const Vector3D<double>&, const Vector3D<double>&);
};


Plane::Plane(const Vector3D<double>& p= Vector3D<double>(), const Vector3D<double>& n = Vector3D<double>())
{
	point = p.Normalize();
	normal = n.Normalize();
	D = -Dot(n,p);
}

Plane::~Plane()
{
}

double Plane::Distance(const Vector3D<double>& S, const Vector3D<double>& V)
{
	return -(Dot(normal, S.Normalize()) + D) / Dot(normal, V.Normalize());
}
