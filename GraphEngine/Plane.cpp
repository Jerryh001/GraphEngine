#include"Plane.h"


Plane::Plane(const Vector3D<double>& p, const Vector3D<double>& n)
{
	normal = n.Normalize();
	normal += Vector3D<double>(0,0,0, -Dot(normal, p.Normalize()));
}

Plane::~Plane()
{
}

double Plane::Distance(const Vector3D<double>& S, const Vector3D<double>& V) const
{
	return -(Dot(normal, S+ Vector3D<double>(0,0,0,1))) / Dot(normal, V.Normalize());
}

