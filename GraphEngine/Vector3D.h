#pragma once
#include<iostream>
#include<cmath>
#include"Matrix.h"
#include"SquareMatrix.h"
#include"Quaternion.h"
class Quaternion;
using namespace std;
template<class T>
class Vector3D :public Matrix<T, 1, 4>
{
	friend class Quaternion;
	T &x = elements[0][0], &y = elements[0][1], &z = elements[0][2], &w = elements[0][3];
public:
	Vector3D(const T& a = 0, const T& b = 0, const T& c = 0, const T& d = 0);
	Vector3D(const Vector3D<T>&);
	template<class T2>
	Vector3D(const Matrix<T2, 1, 4>&);
	template<class T2>
	Vector3D(const Vector3D<T2>&);
	~Vector3D();
	T Length() const;
	Vector3D<T> Normalize() const;
	const T* GetArray() const;
	Vector3D<T> Rotate(const Quaternion&) const;
	T operator()(const int&) const;
	Vector3D<T> operator=(const Vector3D<T>&);
	template<class T2>
	Vector3D<T> operator=(const Vector3D<T2>&);
	template<class T1, class T2>
	friend Vector3D<T1> operator+(Vector3D<T1>, const Vector3D<T2>&);
	template<class T1, class T2>
	friend Vector3D<T1> operator+=(Vector3D<T1>&, const Vector3D<T2>&);
	template<class T1, class T2>
	friend Vector3D<T1> operator-(const Vector3D<T1>&, const Vector3D<T2>&);
	template<class T1, class T2>
	friend Vector3D<T1> operator*(Vector3D<T1>, const T2&);
	template<class T1, class T2>
	friend Vector3D<T1> operator*(const T2&, Vector3D<T1>);
	template<class T>
	friend Vector3D<T> operator/(Vector3D<T>, const T&);
	template<class T>
	friend istream& operator >> (istream& cin, Vector3D<T>& v);
	template<class T1, class T2>
	friend T1 Dot(const Vector3D<T1>&, const Vector3D<T2>&);
	template<class T1, class T2>
	friend Vector3D<T1> Cross(const Vector3D<T1>&, const Vector3D<T2>&);
};
extern template class Vector3D<float>;
extern template class Vector3D<double>;
template<class T1, class T2>
Vector3D<T1> CrossNormalize(const Vector3D<T1>&, const Vector3D<T2>&);


template<class T>
inline Vector3D<T>::Vector3D(const T& a, const T& b, const T& c, const T& d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
template<class T>
inline Vector3D<T>::Vector3D(const Vector3D<T>& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
template<class T>
template<class T2>
inline Vector3D<T>::Vector3D(const Matrix<T2, 1, 4>& m)
{
	x = m(0,0);
	y = m(0, 1);
	z = m(0,2);
	w = m(0, 3);
}
template<class T>
template<class T2>
inline Vector3D<T>::Vector3D(const Vector3D<T2>& v)
{
	const T2* arr = v.GetArray();
	x = arr[0];
	y = arr[1];
	z = arr[2];
	w = arr[3];
}
template<class T>
inline Vector3D<T> Vector3D<T>::operator=(const Vector3D<T>& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}
template<class T>
template<class T2>
inline Vector3D<T> Vector3D<T>::operator=(const Vector3D<T2>& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}
template<class T>
inline Vector3D<T>::~Vector3D()
{
}
template<class T>
inline T Vector3D<T>::Length() const
{
	return sqrt(x*x + y*y + z*z);
}

template<class T>
inline Vector3D<T> Vector3D<T>::Normalize() const
{
	if (Length() > 0)
	{
		return (*this) / Length();
	}
	return *this;
}
template<class T>
inline const T* Vector3D<T>::GetArray() const
{
	return &elements[0][0];
}
template<class T>
inline Vector3D<T> Vector3D<T>::Rotate(const Quaternion & q) const
{

	return Matrix<T,1,4>(*this)*q.GetMatrix();
	//???
	//Quaternion ans = q.Inverse()*Quaternion(this->x, this->y, this->z, 0)*q;
	//return Vector3D<T>(ans.w, ans.x, ans.y);
}
template<class T>
inline T Vector3D<T>::operator()(const int& i)const
{
	return elements[0][i];
}

template<class T1, class T2>
inline Vector3D<T1> operator+(Vector3D<T1> v1, const Vector3D<T2>& v2)
{
	return v1 += v2;
}
template<class T1, class T2>
inline Vector3D<T1> operator+=(Vector3D<T1>& v1, const Vector3D<T2>& v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	v1.w += v2.w;
	return v1;
}
template<class T1, class T2>
inline Vector3D<T1> operator-(const Vector3D<T1>& v1, const Vector3D<T2>& v2)
{
	return Vector3D<T1>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
template<class T1, class T2>
inline Vector3D<T1> operator*(Vector3D<T1> v, const T2& a)
{
	v.x *= a;
	v.y *= a;
	v.z *= a;
	v.w *= a;
	return v;
}
template<class T1, class T2>
inline Vector3D<T1> operator*(const T2& a, Vector3D<T1> v)
{
	return v*a;
}
template<class T>
inline Vector3D<T> operator/(Vector3D<T> v, const T& a)
{
	v.x /= a;
	v.y /= a;
	v.z /= a;
	v.w /= a;
	return v;
}
template<class T>
inline istream& operator >> (istream& cin, Vector3D<T>& v)
{
	return cin >> v.x >> v.y >> v.z;
}
template<class T1, class T2>
inline T1 Dot(const Vector3D<T1>& v1, const Vector3D<T2>& v2)
{
	return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z + v1.w*v2.w;
}

template<class T1, class T2>
inline Vector3D<T1> Cross(const Vector3D<T1>& v1, const Vector3D<T2>& v2)
{
	return Vector3D<T1>(v1.y*v2.z - v2.y*v1.z, v1.z*v2.x - v2.z*v1.x, v1.x*v2.y - v2.x*v1.y);
}

template<class T1, class T2>
inline Vector3D<T1> CrossNormalize(const Vector3D<T1>& v1, const Vector3D<T2>& v2)
{
	Vector3D<T1> ans = Cross(v1, v2);
	if (ans.Length() > 0)
	{
		return ans / ans.Length();
	}
	else
	{
		return ans;
	}
}

