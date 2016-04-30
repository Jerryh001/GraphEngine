#pragma once
#include<iostream>
#define size (level > 0 ? level : 1)
using namespace std;
template<class T, size_t level>
class Matrix
{
	T elements[size][size];
public:
	Matrix();
	Matrix(T m[size][size]);
	~Matrix();
	T Cofactor(const size_t&, const size_t&) const;
	T Det() const;
	Matrix<double, level> Inverse() const;
	template<class T, size_t level>
	friend ostream& operator<<(ostream&, const Matrix<T, level>&);

};
template<class T, size_t level>
Matrix<T, level>::Matrix()
{
	for (size_t i = 0; i < level; i++)
	{
		for (size_t j = 0; j < level; j++)
		{
			elements[i][j] = 0;
		}
	}
}

template<class T, size_t level>
Matrix<T, level>::Matrix(T m[size][size])
{
	for (size_t i = 0; i < level; i++)
	{
		for (size_t j = 0; j < level; j++)
		{
			elements[i][j] = m[i][j];
		}
	}
}

template<class T, size_t level>
Matrix<T, level>::~Matrix()
{

}
template<class T, size_t level>
T Matrix<T, level>::Cofactor(const size_t& a, const size_t& b) const
{
	const size_t minusone = size > 1 ? (size - 1) : 1;
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
	Matrix<T, minusone> temp(m);
	return ((a + b) % 2 ? -1 : 1)*temp.Det();
}

template<class T, size_t level>
T Matrix<T, level>::Det() const
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
Matrix<double, level> Matrix<T, level>::Inverse() const
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
	return Matrix<double, level>(temp);
}
template<class T, size_t level>
ostream& operator<<(ostream& cout, const Matrix<T, level>& m)
{
	for (size_t i = 0; i < level; i++)
	{
		for (size_t j = 0; j < level; j++)
		{
			cout<<m.elements[i][j]<<" ";
		}
		cout << endl;
	}
	return cout;
}
