#pragma once
#include<iostream>
#include<cmath>
using namespace std;
template<class T>
class Vector3D
{
	T elements[4];
	T &x = elements[0], &y = elements[1], &z = elements[2], &w = elements[3];
public:
	Vector3D();
	Vector3D(const T&, const T&, const T&);
	Vector3D(const Vector3D&);
	~Vector3D();
	T Length() const;
	Vector3D<T> Normalize() const;
	T* GetArray() const;
	Vector3D<T> operator=(const Vector3D<T>&);
	template<class T>
	friend Vector3D<T> operator+(Vector3D<T>, const Vector3D<T>&);
	Vector3D operator+=(const Vector3D<T>&);
	template<class T>
	friend Vector3D<T> operator-(const Vector3D<T>&, const Vector3D<T>&);
	template<class T>
	friend Vector3D<T> operator/(Vector3D<T>, const T&);
	template<class T>
	friend istream& operator >> (istream& cin, Vector3D<T>& v);
	template<class T>
	friend ostream& operator << (ostream& cout,const Vector3D<T>& v);
	template<class T>
	friend T Dot(const Vector3D<T>&, const Vector3D<T>&);
	template<class T>
	friend Vector3D<T> Cross(const Vector3D<T>&, const Vector3D<T>&);
};
template<class T>
Vector3D<T> CrossNormalize(const Vector3D<T>&, const Vector3D<T>&);


template<class T>
Vector3D<T>::Vector3D()
{
	x = 0;
	y = 0;
	z = 0;
}

template<class T>
Vector3D<T>::Vector3D(const T& a = 0, const T& b = 0, const T& c = 0)
{
	x = a;
	y = b;
	z = c;
}
template<class T>
Vector3D<T>::Vector3D(const Vector3D& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}
template<class T>
Vector3D<T>::~Vector3D()
{
}
template<class T>
T Vector3D<T>::Length() const
{
	return sqrt(x*x + y*y + z*z);
}

template<class T>
Vector3D<T> Vector3D<T>::Normalize() const
{
	if (Length() > 0)
	{
		return *this / Length();
	}
	return *this;
}

template<class T>
T* Vector3D<T>::GetArray() const
{
	return elements;
}
template<class T>
Vector3D<T> Vector3D<T>::operator=(const Vector3D<T>& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}
template<class T>
Vector3D<T> operator+(Vector3D<T> v1, const Vector3D<T>& v2)
{
	return v1 += v2;
}
template<class T>
Vector3D<T> Vector3D<T>::operator+=(const Vector3D<T>& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}
template<class T>
Vector3D<T> operator-(const Vector3D<T>& v1, const Vector3D<T>& v2)
{
	return Vector3D<T>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
template<class T>
Vector3D<T> operator/(Vector3D<T> v, const T& a)
{
	v.x /= a;
	v.y /= a;
	v.z /= a;
	return v;
}
template<class T>
istream& operator >> (istream& cin, Vector3D<T>& v)
{
	return cin >> v.x >> v.y >> v.z;
}
template<class T>
ostream& operator<<(ostream& cout,const Vector3D<T>& v)
{
	return cout << v.x << v.y << v.z;
}
template<class T>
T Dot(const Vector3D<T>& v1, const Vector3D<T>& v2)
{
	return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

template<class T>
Vector3D<T> Cross(const Vector3D<T>& v1, const Vector3D<T>& v2)
{
	return Vector3D<T>(v1.y*v2.z - v2.y*v1.z, v1.z*v2.x - v2.z*v1.x, v1.x*v2.y - v2.x*v1.y);
}

template<class T>
Vector3D<T> CrossNormalize(const Vector3D<T>& v1, const Vector3D<T>& v2)
{
	Vector3D<T> ans = Cross(v1, v2);
	if (ans.Length() > 0)
	{
		return ans / ans.Length();
	}
	else
	{
		return ans;
	}
}

