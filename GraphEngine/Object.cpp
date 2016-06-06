#define _USE_MATH_DEFINES
#include<cmath>
#include<algorithm>
#include "Object.h"

Object::Object(const Vector3D<double>& l, const Vector3D<double>& s, const Vector3D<double>& acc)
{
	location = l;
	speed = s;
	accelerate = acc;
}

Object::Object(const Vector3D<double>& l, const double & angle, const double & s, const Vector3D<double>& acc)
{
	location = l;
	speed = { s*cos(angle*M_PI / 180),s*sin(angle*M_PI / 180),0 };
	accelerate = acc;
}

Object::~Object()
{
}

void Object::SetGravity()
{
	accelerate = { 0,-9.8,0 };
}

void Object::SetMess(const double& m)
{
	mess = m;
}

Vector3D<double> Object::GetLocation() const
{
	return location;
}

void Object::Move(const double& time)
{
	location += time*speed;
	speed += time*accelerate;
}

void Object::SlideInit(const double & angle, const double & uk)
{
	double temp =max(0.0, 9.8*(sin(angle*M_PI / 180) - uk*cos(angle*M_PI / 180)));
	accelerate = { temp*cos(angle*M_PI / 180),-temp*sin(angle*M_PI / 180),0 };
}

void Object::Slide(const double & time)
{
	Move(time);
}
