#include<cmath>
#include "Slerp.h"
#include"Quaternion.h"
#include"Vector3D.h"
Slerp::Slerp(const Quaternion & qa, const Quaternion & qb)
{
	q1 = qa;
	q2 = qb;
	Vector3D<double> va(q1.x,q1.y,q1.z), vb(q2.x, q2.y, q2.z);
	angle = acos(Dot(va, vb) / (va.Length()*vb.Length()));
}

Quaternion Slerp::operator()(const double & t)
{
	return (sin((1-t)*angle)*q1+sin(t*angle)*q2)/sin(angle);
}

Slerp::~Slerp()
{
}
