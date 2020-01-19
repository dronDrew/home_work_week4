#pragma once
#include "dependies.h"
template<typename T>
class Matrix
{
public:
	Matrix();//done
	Matrix(int row,int col);//done
	Matrix(Matrix &a);
	Matrix(Matrix&& a);
	~Matrix();//done
	void RandInit();//done
	void ManualInit();//done
	void Show();//done
	Matrix<T> operator +(Matrix a);//done
	Matrix<T>& operator -(Matrix& a);//done
	Matrix<T>& operator *(Matrix& a);//done
	Matrix<T> operator /(Matrix& a);
	Matrix<T> operator =(Matrix a);
	T min();//done
	T max();//done
private:
	int row;
	int col;
	T **arr;
};
template<typename T>
Matrix<T>::Matrix(Matrix&& a) {
	this->col = a.col;
	this->row = a.row;
	this->arr = a.arr;
	a.arr = nullptr;
}
template<typename T>
Matrix<T> Matrix<T>::operator =(Matrix a) {
		this->col = a.col;
		this->row = a.row;
		this->arr = new T*[row];
		for (int i = 0; i < row; i++)
		{
			this->arr[i] = new T[col];
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++) {
				arr[i][j] = a.arr[i][j];
			}
		}
		return *this;
}
template<typename T>
Matrix<T>::Matrix(Matrix<T> &a) {
	this->col = a.col;
	this->row = a.row;
	this->arr = new T *[row];
	for (int i = 0; i < row; i++)
	{
		this->arr[i] = new T[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) {
			arr[i][j] = a.arr[i][j];
		}
	}
}
template<typename T>
Matrix<T>::Matrix(int row,int col) {
	this->col = col;
	this->row = row;
	this->arr = new T * [this->row];
	for (int i = 0; i < this->row; i++)
	{
		this->arr[i] = new T[this->col];
	}
}
template<typename T>
Matrix<T>::Matrix() {
	this->col = 0;
	this->row = 0;
	this->arr = nullptr;
}
template<typename T>
Matrix<T>::~Matrix() {
	if (this->arr == nullptr) {
	}
	else
	{
		for (int i = 0; i < row; i++)
		{
			delete[]arr[i];
		}
		delete[]arr;
	}
}
template<typename T>
void Matrix<T>::RandInit() {
	if (this->row!=0&&this->col!=0) {
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++) {
				arr[i][j] = rand() % 100;
			}
		}
	}
	else
	{
		int row = 0;
		int col = 0;
		std::cout << "Enter how many rows must be in your matrix\n";
		std::cin >> row;
		std::cout << "Enter how many colums must be in your matrix\n";
		std::cin >> col;
		this->col = col;
		this->row = row;
		this->arr = new T * [row];
		for (int i = 0; i < row; i++)
		{
			this->arr[i] = new T[col];
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++) {
				arr[i][j] = rand() % 100;
			}
		}
	}
}
template<typename T>
void Matrix<T>::ManualInit() {
	if (this->row != 0 && this->col != 0) {
		std::cout << "Enter elements to matrix\n";
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++) {
				std::cin >> arr[i][j];
			}
		}
	}
	else
	{
		int row = 0;
		int col = 0;
		std::cout << "Enter how many rows must be in your matrix\n";
		std::cin >> row;
		std::cout << "Enter how many colums must be in your matrix\n";
		std::cin >> col;
		this->col = col;
		this->row = row;
		this->arr = new T * [row];
		for (int i = 0; i < row; i++)
		{
			this->arr[i] = new T[col];
		}
		std::cout << "Enter elements to matrix\n";
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++) {
				std::cin >> arr[i][j];
			}
		}
	}
}
template<typename T>
void Matrix<T>::Show() {
	for (int  i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
template<typename T>
Matrix<T> Matrix<T>::operator +(Matrix a) {
	if (this->col != a.col && this->row != a.row) {
		return *this;
	}
	else
	{
		Matrix<T> temp(this->row, this->col);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col;j++) {
				temp.arr[i][j] = this->arr[i][j] + a.arr[i][j];
			}
		}
		return temp;
	}
}
template<typename T>
Matrix<T>& Matrix<T>::operator -(Matrix& a) {
	if (this->col != a.col && this->row != a.row) {
		return *this;
	}
	else
	{
		Matrix<T> temp(this->row, this->col);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++) {
				temp.arr[i][j] = this->arr[i][j] - a.arr[i][j];
			}
		}
		return temp;
	}
}
template<typename T>
Matrix<T>& Matrix<T>::operator *(Matrix& a) {
	if (this->col != a.row) {
		return *this;
	}
	else
	{
		Matrix<T>temp(this->row, a.col);
		for (int i = 0; i < this->row; i++)
		{
			for (int j = 0; j < a.col; j++) {
				int k = i;
				while (k<a.col)
				{
					if (k==i) {
						temp.arr[i][j] = this->arr[i][k] * a.arr[k][i];
						k++;
					}
					else
					{
						temp.arr[i][j] += this->arr[i][k] * a.arr[k][j];
						k++;
					}
				}
			}
		}
		return temp;
	}
}
template<typename T>
Matrix<T> Matrix<T>::operator /(Matrix& a) {}
template<typename T>
T Matrix<T>::min() {
	T res = this->arr[0][0];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) {
			if (res > arr[i][j]) {
				res = arr[i][j];
			}
		}
	}
	return res;
}
template<typename T>
T Matrix<T>::max() {
	T res = this->arr[0][0];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) {
			if (res < arr[i][j]) {
				res = arr[i][j];
			}
		}
	}
	return res;
}