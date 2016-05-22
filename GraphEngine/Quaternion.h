#pragma once
#include<iostream>
#include"Vector3D.h"
template<class T> class Vector3D;
class Quaternion
{
	template<class T> friend class Vector3D;
	double elements[4];
	double &w = elements[0], &x = elements[1], &y = elements[2], &z = elements[3];
public:
	Quaternion(const double& degangle, const Vector3D<double>& axis);
	Quaternion(const double& w1=0, const double& x1 = 0, const double& y1 = 0, const double& z1 = 0);
	~Quaternion();
	double Magnitude() const;
	Quaternion Normalize() const;
	Quaternion Conjugate() const;
	Quaternion Inverse() const;
	friend Quaternion operator+(const Quaternion&, const Quaternion&);
	friend Quaternion operator-(const Quaternion&, const Quaternion&);
	friend Quaternion operator*(const Quaternion&, const Quaternion&);
	Quaternion operator/(const double&) const;
	friend ostream& operator<<(ostream&, const Quaternion&);
};

