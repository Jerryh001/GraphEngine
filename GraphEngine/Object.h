#pragma once
#include<vector>
#include"Vector3D.h"
struct Term
{
	int exp;
	double parameter;
};
class Object
{
	double mess;
	Vector3D<double> location;
	Vector3D<double> speed;
	Vector3D<double> accelerate;

public:
	Object(const Vector3D<double>& l, const Vector3D<double>& s = { 0,0,0 }, const Vector3D<double>& acc = { 0,0,0 });
	Object(const Vector3D<double>& l, const double&,const double& , const Vector3D<double>& acc = { 0,0,0 });
	~Object();
	void SetGravity();
	void SetMess(const double&);
	Vector3D<double> GetLocation() const;
	void Move(const double&);
	void SlideInit(const double& angle, const double& uk);
	void Slide(const double& time);
};

