#include "aghException.h"

#pragma once
template <class T>
class aghMatrix
{
	T** pointer;
	int m, n;
public:
	aghMatrix();
	aghMatrix(int, int);

	~aghMatrix();

	void setItem(int m, int n, T newValue);
	T getItem(int m, int n);
};




