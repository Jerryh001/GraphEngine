#include"Plane.h"


Plane::Plane(const Vector3D<double>& p, const Vector3D<double>& n)
{
	point = p.Normalize();
	normal = n.Normalize();
	D = -Dot(n, p);
}

Plane::~Plane()
{
}

double Plane::Distance(const Vector3D<double>& S, const Vector3D<double>& V) const
{
	return -(Dot(normal, S) + D) / Dot(normal, V.Normalize());
}

