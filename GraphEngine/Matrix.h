#pragma once
#include<iostream>
#include<stdexcept>
using namespace std;
#define row_s (row > 0 ? row : 1)
#define column_s (column > 0 ? column : 1)
template<class T,size_t row,size_t column>
class Matrix
{
	T elements[row_s][column_s];
public:
	Matrix(const T m[row_s][column_s]=nullptr);
	template<class T2>
	Matrix(const Matrix<T2, row, column>&);
	~Matrix();
	Matrix<T, column, row> Transpose();
	template<class T2>
	Matrix<T, row, column> operator=(const Matrix<T2, row, column>&);
	template<class T1, size_t row1, size_t column1, class T2, size_t row2, size_t column2>
	friend Matrix<T1, row1, column2> operator*(const Matrix<T1, row1, column1>&, const Matrix<T2, row2, column2>&);
	template<class T, size_t row, size_t column>
	friend ostream& operator<<(ostream&, const Matrix<T, row, column>&);
	T operator()(const size_t&, const size_t&) const;
};

template<class T, size_t row, size_t column>
Matrix<T, row, column>::Matrix(const T m[row_s][column_s])
{
	if (m == nullptr) return;
	for (size_t i = 0; i < row_s; i++)
	{
		for (size_t j = 0; j < column_s; j++)
		{
			elements[i][j] = m[i][j];
		}
	}
}
template<class T, size_t row, size_t column>
template<class T2>
Matrix<T, row, column>::Matrix(const Matrix<T2, row, column>& m)
{
	for (size_t i = 0; i < row_s; i++)
	{
		for (size_t j = 0; j < column_s; j++)
		{
			elements[i][j] = m(i)(j);
		}
	}
}
template<class T, size_t row, size_t column>
template<class T2>
Matrix<T, row, column> Matrix<T, row, column>::operator=(const Matrix<T2, row, column>& m)
{
	return *this(m);
}
template<class T, size_t row, size_t column>
Matrix<T, row, column>::~Matrix()
{
}
template<class T, size_t row, size_t column>
Matrix<T, column, row> Matrix<T, row, column>::Transpose()
{
	T arr[column_s][row_s];
	for (size_t i = 0; i < row_s; i++)
	{
		for (size_t j = 0; j < column_s; j++)
		{
			arr[j][i] = elements[i][j];
		}
	}
	return Matrix<T, column, row>(arr);
}
template<class T, size_t row, size_t column>
T Matrix<T, row, column>::operator()(const size_t& i, const size_t& j) const
{
	return elements[i][j];
}
template<class T1, size_t row1, size_t column1, class T2, size_t row2, size_t column2>
Matrix<T1, row1, column2> operator*(const Matrix<T1, row1, column1>& m1, const Matrix<T2, row2, column2>& m2)
{
	if (row2 != column1)
	{
		throw invalid_argument("Matrix size not match");
	}
	T1 ans[row1][column2] = { 0 };
	//Matrix<T1, row1, column2> ans;
	for (size_t i = 0; i < row1; i++)
	{
		for (size_t j = 0; j < column2; j++)
		{
			for (size_t a = 0; a < column1; a++)
			{
				ans[i][j] += (m1(i,a) * m2(a,j));
			}
		}
	}
	return Matrix<T1, row1, column2>(ans);
}
template<size_t row1, size_t column1, class T2, size_t row2, size_t column2>
Matrix<T2, row1, column2> operator*(const Matrix<double, row1, column1>& m1, const Matrix<T2, row2, column2>& m2)
{
	if (row2 != column1)
	{
		throw invalid_argument("Matrix size not match");
	}
	T2 ans[row1][column2] = { 0 };
	//Matrix<T1, row1, column2> ans;
	for (size_t i = 0; i < row1; i++)
	{
		for (size_t j = 0; j < column2; j++)
		{
			for (size_t a = 0; a < column1; a++)
			{
				ans[i][j] += (m1(i, a) * m2(a, j));
			}
		}
	}
	return Matrix<T2, row1, column2>(ans);
}
template<class T, size_t row, size_t column>
ostream& operator<<(ostream& cout, const Matrix<T, row, column>& m)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < column; j++)
		{
			cout << m.elements[i][j] << " ";
		}
		cout << endl;
	}
	return cout;
}

