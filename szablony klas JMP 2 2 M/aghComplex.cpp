/**
* \file agComplex.cpp
* \author Jakub Brzegowski
* \date 17.05.2015
* \version 1.0
* \Header file with class' functions from class aghComplex
*/
// -------------------------------------------------------------------------

#include "aghComplex.h"

aghComplex& aghComplex::operator= (const aghComplex& other)
{
	this->re = other.re;
	this->im = other.im;

	return *this;
}

aghComplex& aghComplex::operator= (const int& other)
{
	this->re = other;
	this->im = 0;

	return *this;
}

aghComplex& aghComplex::operator+= (const aghComplex& other)
{
	this->re += other.re;
	this->im += other.im;

	return *this;
}

aghComplex aghComplex::operator+ (const aghComplex& other)
{
	aghComplex newComplex;

	newComplex.re = this->re + other.re;
	newComplex.im = this->im + other.im;

	return newComplex;
}

aghComplex aghComplex::operator* (const aghComplex& other)
{
	aghComplex newComplex;

	newComplex.re = this->re * other.re - this->im * other.im;
	newComplex.im = this->im * other.re + this->re * other.im;

	return newComplex;
}

bool aghComplex::operator== (const aghComplex& other)
{
	if (this->re == other.re && this->im == other.im) return true;

	return false;
}

bool aghComplex::operator!= (const aghComplex& other)
{
	if (this->re == other.re && this->im == other.im) return false;

	return true;
}
