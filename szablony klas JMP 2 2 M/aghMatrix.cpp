/**
* \file aghMatrix.cpp
* \author Jakub Brzegowski
* \date 17.05.2015
* \version 1.0
* \Header file with specialized methods from aghMatrix class
*/
// -------------------------------------------------------------------------


#include "aghMatrix.h"	/// We add header file with class, and class' methods templates

aghMatrix<char> aghMatrix<char>::operator+ (const aghMatrix<char>& other)
{
	if (this->m != other.m || this->n != other.n)
		throw aghException(0, "You can't add two matrices which have different dimensions.", __FILE__, __LINE__);	/// Checking if we can add this two matrices

	aghMatrix<char> newMatrix(this->m, this->n);	/// Creation of new object with dimensions like two other matrices

	int sum = 0; ///< Auxiliary variable

	/** In ASCII table:
	*	a -> 97
	*	z -> 122
	*/
	for (int i = 0; i < this->m; i++)
		for (int j = 0; j < this->n; j++)
		{
		sum = (this->pointer[i][j] - 97) + (other.pointer[i][j] - 97);	/// Setting values of elements from 'newMatrix' by adding corresponding elements
		newMatrix.pointer[i][j] = sum % 26 + 97;
		}

	return newMatrix;	/// Returning created 'newMatrix'
}

aghMatrix<char> aghMatrix<char>::operator* (const aghMatrix<char>& other)
{
	if (this->n != other.m)
		throw aghException(0, "You can't mulitply two matrices which have different dimensions.", __FILE__, __LINE__);	/// Checking if we can multiply this two matrices

	aghMatrix<char> newMatrix(this->m, other.n);	/// Creation of new object with proper dimensions

	int sum = 0; ///< Auxiliary variable

	/** In ASCII table:
	*	a -> 97
	*	z -> 122
	*/
	for (int i = 0; i < this->m; i++)	/// Setting right row
		for (int j = 0; j < other.n; j++)	/// Setting right column
		{
			for (int k = 0; k < this->n; k++)	/// We multiply k elements, so...
			{
				sum += (this->pointer[i][k] - 97) * (other.pointer[k][j] - 97);	/// Setting values of elements from 'newMatrix' by adding multiplication of corresponding elements
			}

			newMatrix.pointer[i][j] = (sum % 26) + 97;	/// Insertion of calculated element into matrix.
			sum = 0;	/// Setting value of 'sum' to 0 in order to avoid interference of this element onto next one
		}

	return newMatrix;	/// Returning created 'newMatrix'
}