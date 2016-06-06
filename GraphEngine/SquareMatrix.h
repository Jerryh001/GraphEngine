#pragma once
#include<iostream>
#include"Matrix.h"
#define size_s (level > 0 ? level : 1)
using namespace std;
template<class T, size_t level>
class SquareMatrix:public Matrix<T,level,level>
{
	T elements[size_s][size_s];
public:
	SquareMatrix();
	template<class T2>
	SquareMatrix(T2 m[size_s][size_s] = nullptr);
	template<class T2>
	SquareMatrix(const SquareMatrix<T2, level>&);
	template<class T2>
	SquareMatrix(const Matrix<T2, level,level>&);
	~SquareMatrix();
	T Cofactor(const size_t&, const size_t&) const;
	T Det() const;
	SquareMatrix<double, level> Inverse() const;
	

};


template<class T, size_t level>
template<class T2>
SquareMatrix<T, level>::SquareMatrix(T2 m[size_s][size_s]) :Matrix(m)
{

}
template<class T, size_t level>
template<class T2>
SquareMatrix<T, level>::SquareMatrix(const SquareMatrix<T2, level>& m):Matrix(m)
{
}
template<class T, size_t level>
template<class T2>
inline SquareMatrix<T, level>::SquareMatrix(const Matrix<T2, level, level>& m):Matrix(m)
{
}
template<class T, size_t level>
inline SquareMatrix<T, level>::SquareMatrix()
{
}
template<class T, size_t level>
SquareMatrix<T, level>::~SquareMatrix()
{

}
template<class T, size_t level>
T SquareMatrix<T, level>::Cofactor(const size_t& a, const size_t& b) const
{
	const size_t minusone = size_s > 1 ? (size_s - 1) : 1;
	T m[minusone][minusone];
	for (size_t i = 0, x = 0; i < level; i++)
	{
		if (i == a) continue;
		for (size_t j = 0, y = 0; j < level; j++)
		{
			if (j == b) continue;
			m[x][y] = elements[i][j];
			y++;
		}
		x++;
	}
	return ((a + b) % 2 ? -1 : 1)*SquareMatrix<T, minusone>(m).Det();
}

template<class T, size_t level>
T SquareMatrix<T, level>::Det() const
{
	T ans = 0;
	if (level > 2)
	{
		for (size_t i = 0; i < level; i++)
		{
			ans += elements[0][i] * Cofactor(0, i);
		}
	}
	else
	{
		ans = elements[0][0] * elements[1][1] - elements[1][0] * elements[0][1];
	}
	return ans;
}

template<class T, size_t level>
SquareMatrix<double, level> SquareMatrix<T, level>::Inverse() const
{
	double temp[level][level];
	double delta = Det();
	for (size_t i = 0; i < level; i++)
	{
		for (size_t j = 0; j < level; j++)
		{
			temp[i][j] = Cofactor(j, i) / delta;
		}
	}
	return SquareMatrix<double, level>(temp);
}


