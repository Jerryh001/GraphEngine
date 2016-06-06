#pragma once
#include "Curve.h"
#include"Quaternion.h"
class Slerp
{
	friend class Quaternion;
	Quaternion q1, q2;
	double angle;//rad
public:
	Slerp(const Quaternion& qa=0,const Quaternion& qb=0);
	Quaternion operator()(const double& t);
	~Slerp();
};

