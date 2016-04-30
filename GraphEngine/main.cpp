#include<iostream>
#include"GraphEngine.h"
using namespace std;
int main()
{
	int ele[4][4] = { 3,1,2,4,1,-2,-3,-2,10,2,3,9,-4,-3,-3,-4 };
	Matrix<int, 4> m(ele);
	cout << m << endl;
	Vector3D<double> v(1, 2, 3);
	cout << v+v;
}