#pragma once
#include<iostream>
#include"Vector3D.h"
class Quaternion
{
	double elements[4];
	double &w = elements[0], &x = elements[1], &y = elements[2], &z = elements[3];
public:
	Quaternion(const double& degangle = 0, const Vector3D<double>& axis = { 0 });
	Quaternion(const double& w1=0, const double& x1 = 0, const double& y1 = 0, const double& z1 = 0);
	~Quaternion();
	double Magnitude();
	Quaternion Normalize();
	Quaternion Conjugate();
	Quaternion Inverse();
	friend Quaternion operator+(const Quaternion&, const Quaternion&);
	friend Quaternion operator-(const Quaternion&, const Quaternion&);
	friend Quaternion operator*(const Quaternion&, const Quaternion&);
	Quaternion operator/(const double&);
	friend ostream& operator<<(ostream&, const Quaternion&);
};

