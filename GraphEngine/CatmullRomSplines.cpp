#include<vector>
#include<stdexcept>
#include "CatmullRomSplines.h"
using namespace std;


CatmullRomSplines::CatmullRomSplines(const vector<Vector3D<double>>& in) :Curve(0, 0, 0, 0)
{
	double Marr[4][4] =
	{ { 0,-0.5,1,-0.5 },
	{ 1,0,-2.5,1.5 },
	{ 0,0.5,2,-1.5 },
	{ 0,0,-0.5,0.5 } };
	M = Marr;
	node = in;
}


CatmullRomSplines::~CatmullRomSplines()
{
}

Vector3D<double> CatmullRomSplines::operator()(const double & t)
{
	if (t < 0 || (t + 3 >= node.size()))
	{
		throw invalid_argument("Out of range");
	}
	double temp = t;
	int i = int(t);
	temp -= i;
	double tarr[4][1] = { 1,temp,temp*temp,temp*temp*temp };
	T = tarr;
	Vector3D<double> Garr[1][4] = { node[i],node[i+1],node[i+2],node[i+3] };
	G = Garr;
	return (G*M*T)(0,0);
}
