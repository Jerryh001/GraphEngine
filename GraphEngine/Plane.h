#pragma once
#include"Vector3D.h"
#include"Line.h"
class Plane
{
	Vector3D<double> point;
	Vector3D<double> normal;
	double D;
public:
	Plane(const Vector3D<double>& p = Vector3D<double>(), const Vector3D<double>& n = Vector3D<double>());
	~Plane();
	double Distance(const Vector3D<double>&, const Vector3D<double>&) const;
	template<class T1>
	friend Vector3D<T1> TouchPoint(const Plane&, const Line<T1>&);
};
template<class T1>
Vector3D<T1> TouchPoint(const Plane& P, const Line<T1>& L)
{
	return L.GetSource() + L.GetDirect()*P.Distance(L.GetSource(), L.GetDirect());
}