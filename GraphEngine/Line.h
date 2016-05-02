#pragma once
#include"Vector3D.h"
template<class T>
class Line
{
	Vector3D<T> source;
	Vector3D<T> direct;
public:
	template<class T1,class T2>
	Line(const Vector3D<T1>& s= Vector3D<T1>(), const Vector3D<T2>& d= Vector3D<T2>());
	~Line();
	Vector3D<T> GetSource() const;
	Vector3D<T> GetDirect() const;
	template<class T1>
	Vector3D<T> operator()(const T1&) const;
};
extern template class Line<float>;
extern template class Line<double>;
template<class T>
template<class T1, class T2>
Line<T>::Line(const Vector3D<T1>& s, const Vector3D<T2>& d)
{
	source = s;
	direct = d;
}
template<class T>
template<class T1>
Vector3D<T> Line<T>::operator()(const T1& a) const
{
	return source + direct*a;
}

template<class T>
Line<T>::~Line()
{
}

template<class T>
Vector3D<T> Line<T>::GetSource() const
{
	return source;
}

template<class T>
Vector3D<T> Line<T>::GetDirect() const
{
	return direct;
}
