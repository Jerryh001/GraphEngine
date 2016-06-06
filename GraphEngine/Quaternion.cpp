#define _USE_MATH_DEFINES
#include<cmath>
#include "Vector3D.h"
#include "Quaternion.h"
Quaternion::Quaternion(const double & degangle, const Vector3D<double>& axis)
{
	Vector3D<double> a2 = axis.Normalize();
	double rad = degangle * M_PI / 360;
	w = cos(rad);
	x = y = z = sin(rad);
	x *= a2(0);
	y *= a2(1);
	z *= a2(2);
}

Quaternion::Quaternion(const double & w1, const double & x1, const double & y1, const double & z1)
{
	w = w1;
	x = x1;
	y = y1;
	z = z1;
}

Quaternion::~Quaternion()
{
}

double Quaternion::Magnitude() const
{
	return sqrt(w*w + x*x + y*y + z*z);
}

Quaternion Quaternion::Normalize() const
{
	return *this / (this->Magnitude());
}

Quaternion Quaternion::Conjugate() const
{
	return Quaternion(w, -x,-y,-z);
}

Quaternion Quaternion::Inverse() const
{
	double l = Magnitude();
	return Conjugate()/(l*l);
}

SquareMatrix<double, 4> Quaternion::GetMatrix() const
{
	double m1arr[4][4] =
	{ w,z,-y,x,
	-z,w,x,y,
	y,-x,w,z,
	-x,-y,-z,w };
	double m2arr[4][4] =
	{ w,z,-y,-x,
	-z,w,x,-y,
	y,-x,w,-z,
	x,y,z,w };
	SquareMatrix<double, 4> M1(m1arr), M2(m2arr);
	return M1*M2;
}

Quaternion Quaternion::operator=(const Quaternion & q)
{
	w = q.w;
	x = q.x;
	y = q.y;
	z = q.z;
	return *this;
}

Quaternion Quaternion::operator/(const double& a) const
{
	return Quaternion(w / a,  x / a,y / a,z / a );
}

Quaternion operator+(const Quaternion & a, const Quaternion & b)
{
	return Quaternion(a.w + b.w, a.x + b.x, a.y + b.y, a.z + b.z);
}

Quaternion operator-(const Quaternion & a, const Quaternion & b)
{
	return Quaternion(a.w - b.w, a.x - b.x, a.y - b.y, a.z - b.z);
}

Quaternion operator*(const Quaternion & a, const Quaternion & b)
{
	Vector3D<double> va(a.x, a.y, a.z),vb(b.x,b.y,b.z);
	Vector3D<double> vc = a.w*vb + b.w*va + Cross(va, vb);
	return Quaternion(a.w*b.w-Dot(va,vb),vc(0),vc(1),vc(2));
}

ostream & operator<<(ostream & cout, const Quaternion & q)
{
	return cout << q.w << " " << q.x << " " << q.y << " " << q.z;
}
